#include "ofApp.h"
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup() {
	// fill the pixels array with white pixels
	int size = sizeof(pixels) / sizeof(char);
	for (int i = 0; i<size; i++) {
		pixels[i] = 0;
	}
	tex.loadData(pixels, 100, 100, GL_LUMINANCE); // 4th argument tells it it is greyscale
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	tex.draw(0, 0, ofGetWidth(), ofGetHeight());

	int size = sizeof(pixels) / sizeof(char);
	
	for (int j = 0; j < size; j+= 20) {
		for (int i = 0; i < size; i += 20) {
			pixels[i] = 255;
		}
	}

	//for (int i = 0; i<size; i += 10) {
	//	pixels[i] = 0;
	//}
	tex.loadData(pixels, 100, 100, GL_LUMINANCE); // 4th argument tells it it is greyscale
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