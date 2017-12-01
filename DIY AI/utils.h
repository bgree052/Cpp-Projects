#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <random>


// return random int in the range 0-max
int randInt(int max){
  double r = std::rand();
  r /= RAND_MAX;
  r *= max;
  int i = r;
  return i;
}


// tokenizer - splits the sent string on the sent seperator and sends it back as a vector
// of strings. e.g 'hello how are you' -> {"hello", "how", "are", "you"}
std::vector<std::string> tokenise(std::string input, char sep){
  std::vector<std::string> vec;
  int end;
  int start = input.find_first_not_of(sep, 0);
  std::string token;
  //  std::cout << "processing '"<< input << "'" << input.length() << std::endl;
  // find index of sep
  do{
    end = input.find_first_of(sep, start);
    //std::cout << start << " - " << end << std::endl;
    if (start == input.length() || start == end){// whitespace at the end
      break;
    }
    if (end >= 0){// we found it - use end for substr
      token = input.substr(start, end - start);
    }
    else { // we did not find it, use the remaining length of the string
      token = input.substr(start, input.length() - start);
    }
    //std::cout << "got token " << token << std::endl;
    vec.push_back(token);
    // did we find it?
    start = end + 1;
  }while (end > 0);  // yes? continue
  return vec;
}

// updates the sent map by adding the sent vector of words to it
// with first order analyis. e.g.:
// input: hello how are you ->
// action: add the following entries to the map:
// hello -> how
// how -> are
// are -> you
// returns the updated map
std::map <std::string,std::string> addWordsToMarkov(std::map <std::string,std::string> markov, std::string words){
  std::string now, prev, nexts;
  std::vector <std::string> tempStrings = tokenise(words, ' ');
  // iterate the word sequence
  
  for (int i=1; i<tempStrings.size();i++){
    //    std::cout << " adding " << tempStrings[i] << " to the chain ";
    // for each word, look up the previous word
    now = tempStrings[i];
    prev = tempStrings[i-1];
    // use the previous word as a key in the map
    nexts = markov[prev];
    // add the new 'observation' for a word following prev to the string
    nexts += now + " ";
    // put it back onto the map 
    markov[prev] = nexts;
    //    std::cout << "obs following " << prev << " updated to '" << nexts << "'" << std::endl;
  }
  
  return markov;
}

// returns a vector of strings representing the string keys of the sent map
std::vector <std::string> getMapKeys(std::map<std::string,std::string> theMap){
  std::vector<std::string> vec;
   // show content:
  // from the example code here:  http://www.cplusplus.com/reference/map/map/begin/
  for (std::map<std::string,std::string>::iterator it=theMap.begin(); it!=theMap.end(); ++it){
    //std::cout << it->first << " => " << it->second << '\n';
    vec.push_back(it->first);
  }
  return vec;
}


void test_addWordsToMarkov(){
  std::map <std::string,std::string> chain;
  // this should give me a map mapping "two" to "tokens"
  chain = addWordsToMarkov(chain, "two tokens");
  if (chain["two"] != "tokens "){
    std::cout << "two token test **failed**. two not mapped to token "<< std::endl;
  }
  else {
    std::cout << "two token test passed.  "<< std::endl;
  }
  // now more tokens
  chain = addWordsToMarkov(chain, "two bad are two good");
  if (chain["two"] != "tokens bad good "){
    std::cout << "read two from one phrase **failed**. two not mapped to tokens good "<< std::endl;
  }
  else {
    std::cout << "read two from one phrase passed.  "<< std::endl;
  }

}


// test code for randInt 
int testRandInt(){
  for (int i=0;i<100;i++){
    int v = randInt(5);
    if (v > 5){
      std::cout << "test faild. v is greater than 5" << v << std::endl;
    }
  }
}

// a whole bunch of tests for the tokeniser.
void testTokenise(){
  std::vector <std::string> vec;
  vec = tokenise("two token", ' ');
  if (vec.size() != 2){
    std::cout << "two token test **failed** " << " vec size is " << vec.size() << std::endl;
    
  }
  else {
    // now check what we have
    if (vec[0] == "two" && vec[1] == "token"){
      std::cout << "two token test passed." << std::endl;
    }
    else {
      std::cout << "two token test **failed** " << " tokens look bad " << std::endl;      
    }
  }
  
  vec = tokenise("onetoken", ' ');
  if (vec.size() != 1){
    std::cout << "one token test **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "one token test passed." << std::endl;
  }
  
  vec = tokenise(" onetoken ", ' ');
  if (vec.size() != 1){
    std::cout << "one token test space both ends **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "one token test space both ends  passed." << std::endl;
  }
  
  vec = tokenise(" onetoken", ' ');
  if (vec.size() != 1){
    std::cout << "one token test space at start **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "one token test space at start  passed." << std::endl;
  }

  vec = tokenise(" two token ", ' ');
  if (vec.size() != 2){
    std::cout << "two token test space at both ends **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "two token test space at both ends passed." << std::endl;
  }

  vec = tokenise(" two token    ", ' ');
  if (vec.size() != 2){
    std::cout << "two token test space at both ends with extra spaces at end **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "two token test space at both ends with extra spaces at end passed." << std::endl;
  }

  vec = tokenise("    two token    ", ' ');
  if (vec.size() != 2){
    std::cout << "two token test space at both ends with extra spaces at start+end **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "two token test space at both ends with extra spaces at start+end passed." << std::endl;
  }


  vec = tokenise(" three token withspace ", ' ');
  if (vec.size() != 3){
    std::cout << "three token test space at both ends **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "three token test space at both ends passed." << std::endl;
  }

  vec = tokenise("three token test", ' ');
  if (vec.size() != 3){
    std::cout << "three token test **failed** " << " vec size is " << vec.size() << std::endl;

  }
  else {
    std::cout << "three token test passed." << std::endl;
  }
  
}

