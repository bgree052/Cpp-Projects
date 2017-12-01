#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "utils.h"

int main() {
	std::map <std::string,std::string> wordChain;
	std::string input, nexts, lastWord, output;
	std::vector<std::string> tempStrings;
	int index;
	// a string to store the user input

	std::cout << "parrotbot> Hello. what seems to be the problem?" << std::endl;
	// print out a prompt to the user

	while (true) {
	// run forever
		std::getline(std::cin, input); 
		// read a line from cin (console input) to the input string

		wordChain = addWordsToMarkov(wordChain, input);
		//breaks the words up and adds them to the word chain

		tempStrings = tokenise(input, ' ');
		//tokenise the string on spaces

		lastWord = tempStrings.back();
		//use the last word they typed

		output = "";
		//define output string as an empty string

		for (int i = 0; i < 5; i++) {
			//queries the chain 5 times to pull out the tokenised words

			nexts = wordChain[lastWord];
			//sets nexts to the previous word in the word chain?

			tempStrings = tokenise(nexts, ' ');
			//breaks the sentence up by defining the words when there is a space

			if (nexts.size() == 0) {
				//if havent seen word
				tempStrings = getMapKeys(wordChain);
				//mapping new word to the word chain
			}
			
			index = randInt(tempStrings.size());
			//we chose one using an int no larger than the vector size

			lastWord = tempStrings[index];

			output += lastWord+" ";
			//stores the chosen word in the output string
		}
		std::cout << output << std::endl;
		//print the output string to the console

	}
}