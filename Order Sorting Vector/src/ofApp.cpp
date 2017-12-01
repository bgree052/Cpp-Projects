#include "ofApp.h"
#include <iostream>

int v[] = {3,3,4,6,5,3,7,7};

int a = 0;
int b = 0;

//--------------------------------------------------------------
void ofApp::setup(){
	//EXERCISE(myInts);

	for (int i = 0; i < sizeof(v)/sizeof(int); i++) {
		if (v[i] > b) {
			if (v[i] > a) {
				b = a;
				a = v[i];
			}
			else {
				b = v[i];
			}
		}
	}
	cout << b;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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

//void EXERCISE(int v[]) {
//	int a = 0;
//	int b = 0;
//	for (int i = 0; i < v; i++) {
//		if (v[i] > b) {
//			if (v[i] > a) {
//				b = a;
//				a = v[i];
//			}
//			else {
//				b = v[i];
//			}
//		}
//	}
//	return b;
//}