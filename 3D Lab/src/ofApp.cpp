#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	parent.setPosition(ofGetHeight()/2,ofGetWidth()/2,0);
	
	box.setParent(parent);
	box.setPosition(0, 0, 0);
	box.setOrientation(ofVec3f(120,0,0));
	box.set(100);
	// if we don't do this things get weird
	// things that are supposed to be behind will
	// in front
	ofEnableDepthTest();

	// two things we need to enable for it to work
	// turn on lighting
	ofEnableLighting();

	light.setPointLight();
	light.setAmbientColor(ofFloatColor(0.3, 0.3, 0.3));
	light.setDiffuseColor(ofFloatColor(1.0, 0.5, 0.0));
	light.setPosition(ofGetWidth()*.5, ofGetHeight()*.7, 300);

	material.setDiffuseColor(ofFloatColor(1.0,0,0));

	texture.load("akko.jpg");
	texture.mirror(true, false);

	// set texture coordinates from 0-1 rather
	// than in actual pixels (otherwise it is
	// really hard to get the texturing right)
	ofEnableNormalizedTexCoords();
}

//--------------------------------------------------------------
void ofApp::update(){
	float mouseX = ofGetMouseX();
	mouseX = ofMap(mouseX, 0, ofGetWidth(),0,2);
	box.rotate(mouseX, 1.0, 1.0, 0);
}

//--------------------------------------------------------------
void ofApp::draw(){
	light.enable();
	//material.begin();
	texture.getTexture().bind();
	box.draw();
	texture.getTexture().unbind();
	//material.end();
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
