#include "ofApp.h"
#include <iostream>



//--------------------------------------------------------------
void ofApp::setup() {
	xval = 0;
	phaseOff = 0.01;
	move = 0.0;
	//int size = sizeof(pixels) / sizeof(char);
	//float phase = 0.0;
	//float phaseD = TWO_PI / 10.0;
	//for (int i = 0; i<size; i += 4) {// we are going in steps of 4
	//	pixels[i] = ofClamp(sinf(phase),0,1)*255.0;
	//	pixels[i + 1] = ofClamp(sinf(phase*2),0,1)* 255.0;
	//	pixels[i + 2] = ofClamp(sinf(phase * 1.5),0,1) * 255.0;
	//	pixels[i + 3] = 255;
	//	phase += phaseD;
	//}
	//tex.loadData(pixels, 100, 100, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update() {
	move -= 0.01;
	int size = sizeof(pixels) / sizeof(char); // calculates the size that an int takes up in memory
	float phase = 0.0;
	phase += move;
	float phaseD = TWO_PI / 10.0;
	for (int i = 0; i<size; i += 4) {// we are going in steps of 4
		pixels[i] = ofClamp(sinf(phase), 0, 1)*255.0;
		pixels[i + 1] = ofClamp(sinf(phase * 2), 0, 1)* 255.0;
		pixels[i + 2] = ofClamp(sinf(phase * 1.5), 0, 1) * 255.0;
		pixels[i + 3] = 255;
		phase += phaseD;
	}
	tex.loadData(pixels, 100, 100, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::draw() {
	tex.draw(0, 0, ofGetWidth(), ofGetHeight());
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