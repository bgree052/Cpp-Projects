#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofEnableDepthTest();
	//camera.setPosition(ofGetWidth()/2,ofGetHeight()/2,700);
	ofEnableLighting();
	light.setPointLight();
	light.setAmbientColor(ofFloatColor(0.3, 0.3, 0.3));
	light.setDiffuseColor(ofFloatColor(1.0, 0.5, 0.0));
	light.setPosition(ofGetWidth(), ofGetHeight(), 300);
}

//--------------------------------------------------------------
void ofApp::update(){
    newCar.setPosition(mouseX, mouseY, 0);
    newTree.SetPosition(100,100,100);
	newTree.FlashStar();
}

//--------------------------------------------------------------
void ofApp::draw(){
	light.enable();
	//camera.begin();
    newCar.draw();
    newTree.Draw();
	light.disable();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    newCar.onMouseClick(x, y, button);
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
