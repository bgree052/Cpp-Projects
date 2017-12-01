#include "ofApp.h"
#include <iostream>



//--------------------------------------------------------------
void ofApp::setup() {
	xval = 0;
	phaseOff = 0.01;
	// fill the pixels array with white pixels
	int size = sizeof(pixels) / sizeof(char);
	for (int i = 0; i<size; i++) {
		pixels[i] = 255;
	}
	tex.loadData(pixels, 100, 100, GL_LUMINANCE); // 4th argument tells it it is greyscale
}

//--------------------------------------------------------------
void ofApp::update() {
	//MORE NOTES ON THIS IN YOUR NOTEBOOK!
	int size = sizeof(pixels) / sizeof(char); //size of the array in memory 
	float phase = 0.0; //represents the angle, similar to the x axis in the sine graph
	float phaseD = TWO_PI / 100.0; //two_pi is equivalent to a whole circle, and the 100 value is the space of pixels you have to work with. This calculation is effectively calculating the incriment space for the sine wave
	for (int i = 0; i<size; i++) {
		pixels[i] = (sinf(phase + phaseOff)+1)/2 * 255.0;
		phase += 4*phaseD;
	}
	tex.loadData(pixels, 100, 100, GL_LUMINANCE); // 4th argument tells it it is greyscale
	phaseOff += 0.01;
}

//--------------------------------------------------------------
void ofApp::draw() {
	tex.draw(xval, 0, ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}