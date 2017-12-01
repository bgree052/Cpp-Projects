#include "ofApp.h"
#include <iostream>

float hunger; //holds hunger value
float happiness; //holds happiness value
float clean; //holds cleanliness value
int state; //holds an integer used to change the game state

//--------------------------------------------------------------
void ofApp::setup(){
	hunger = 100;
	happiness = 100;
	clean = 100;
	state = 1;

	ofBackground(192, 192, 192);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	//Change to dead screen
	if (state == 1 && (hunger <= 0 || happiness <= 0 || clean <= 0)) {
		state = 2;
		hunger = 0;
		clean = 0;
		happiness = 0;
	}

	//Instructions
	ofSetColor(0);
	if (state == 1) {
		ofDrawBitmapString("Press 'f' to feed him", 260, 30);
		ofDrawBitmapString("Press 'p' to play with him", 260, 50);
		ofDrawBitmapString("Press 'c' to clean him", 260, 70);
	}
	else {
		ofDrawBitmapString("Tama is Dead", 260, 30);
		ofDrawBitmapString("Press 'r' to start again!", 260, 50);
	}

	if (hunger > 0){hunger -= 0.025;}
	if (happiness > 0) {happiness -= 0.015; }
	if (clean > 0) {clean -= 0.020; }

	//hungerbar
	ofRectangle hungerBar;
	hungerBar.x = 25;
	hungerBar.y = 150;
	hungerBar.width = 100;
	hungerBar.height = 10;

	ofSetColor(0);
	ofDrawRectangle(hungerBar);

	ofSetColor(0, 255, 0);
	ofDrawRectangle(hungerBar.x, hungerBar.y, hunger , hungerBar.height);

	//cout << hungerBar.width-hunger;

	//happinessbar
	ofRectangle happinessBar;
	happinessBar.x = 25;
	happinessBar.y = 170;
	happinessBar.width = 100;
	happinessBar.height = 10;

	ofSetColor(0);
	ofDrawRectangle(happinessBar);

	ofSetColor(255, 255, 0);
	ofDrawRectangle(happinessBar.x, happinessBar.y, happiness, happinessBar.height);

	//cleanbar
	ofRectangle cleanBar;
	cleanBar.x = 25;
	cleanBar.y = 190;
	cleanBar.width = 100;
	cleanBar.height = 10;

	ofSetColor(0);
	ofDrawRectangle(cleanBar);

	ofSetColor(0, 191, 255);
	ofDrawRectangle(cleanBar.x, cleanBar.y, clean, cleanBar.height);


	//Body
	ofRectangle rect;
	rect.x = 25;
	rect.y = 10;
	rect.width = 100;
	rect.height = 100;

	if (clean > 50) {
		ofSetColor(255, 0, 0);
	}
	else {
		ofSetColor(0, 150, 0);
	}

	ofDrawRectangle(rect);

	ofSetColor(0, 0, 0);
	
	//Eyes turn to x's to show he is dead
	//Left eye
	if (hunger <= 0 || happiness <= 0 || clean <= 0) {
		ofSetLineWidth(3);
		ofDrawLine(rect.x + 25, rect.y + 15, rect.x + 43, rect.y + 28);
		ofDrawLine(rect.x + 25, rect.y + 28, rect.x + 43, rect.y + 15);
	}
	else {
		ofDrawEllipse(rect.x + rect.width / 3, rect.y + rect.height / 5, 10, 10);
	}

	//Right eye
	if (hunger <= 0 || happiness <= 0 || clean <= 0) {
		ofSetLineWidth(3);
		ofDrawLine(rect.x + 5 + rect.width / 2, rect.y + 15, rect.x + 23 + rect.width / 2, rect.y + 28);
		ofDrawLine(rect.x + 5 + rect.width / 2, rect.y + 28, rect.x + 23 + rect.width / 2, rect.y + 15);
	}
	else {
		ofDrawEllipse(rect.x + (2 * rect.width) / 3, rect.y + rect.height / 5, 10, 10);
	}

	//Mouth(ellipse)
	int mouthx = rect.x + rect.width / 2;
	int mouthy = rect.y + (1.75 * rect.height) / 3;

	ofDrawEllipse(mouthx, mouthy, 50,50);

	//Mouth(rectangle)
	if (clean > 50) {
		ofSetColor(255, 0, 0);
	}
	else {
		ofSetColor(0, 150, 0);
	}
	//shows he is unhappy
	if (happiness <= 50) {
		ofDrawRectangle(mouthx - 25, mouthy, 50, 25);
	}
	else {
		ofDrawRectangle(mouthx - 25, mouthy - 25, 50, 25);
	}

	//shows he is hungry
	if (hunger < 50) {
		ofSetColor(0);
		ofDrawLine(130, 85, 140, 70);
		ofDrawBitmapString("GRUMBLE~", 145, 70);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	//std::cout << "You pressed " << key << std::endl;

	//only works when he is alive
	if (state == 1) {
		//keys for interaction with tama
		if (key == 'f' && hunger < 100) {
			if (hunger < 90) {
				hunger += 20;
			}
			else {
				hunger = 100;
			}
		}
		else if (key == 'p' && happiness > 0) {
			if (happiness < 90) {
				happiness += 5;
			}
			else {
				happiness = 100;
			}
		}
		else if (key == 'c' && clean > 0) {
			if (clean < 90) {
				clean += 20;
			}
			else {
				clean = 100;
			}
		}
	}
	//resets the game
	if(key == 'r' && state == 2){
		state = 1;
		hunger = 100;
		clean = 100;
		happiness = 100;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
