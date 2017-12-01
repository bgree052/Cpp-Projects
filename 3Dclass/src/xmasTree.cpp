/*
 * xmasTree.cpp
 *
 *  Created on: 27 Nov 2017
 *      Author: Connor Brooks
 */
#include "xmasTree.h"
#include "ofMain.h" //buggy IDE (eclipse) Requires this when using any OF functions. You probably dont need this.


XmasTree::XmasTree(){

	// Set up the materials for the tree.
	treeMaterial.setDiffuseColor(ofFloatColor(0, 1, 0));
	starMaterial.setSpecularColor(ofFloatColor(1, 1, 0));
	starMaterial.setShininess(1);
	trunkMaterial.setDiffuseColor(ofFloatColor(0.5, 0.1, 0.1));

	// Set the size of the star
	star.set( 20, 10);

	// Set the size of the top section of tree
	top.set(100, 200);

	// and add it below the star
	top.setParent(star);
	top.setPosition(0, 100, 0);

	// Set the size of the middle section of the tree
	middle.set(125, 250);

	// And add it below the top section
	middle.setParent(top);
	middle.setPosition(0, 100, 0);

	// Set the size of the bottom section of the tree
	bottom.set(150, 300);

	// And add it below the middle
	bottom.setParent(middle);
	bottom.setPosition(0, 100, 0);

	// Set the size of the trunk up
	trunk.setHeight( 100);
	trunk.setWidth(50);
	trunk.setDepth(50);

	// And add it below the bottom section of the tree
	trunk.setParent(bottom);
	trunk.setPosition(0, 200, 0);
}

// Draw the tree
void XmasTree::Draw(){

	// Begin the trunk material and then draw the trunk
	trunkMaterial.begin();
	trunk.draw();
	trunkMaterial.end();

	// Begin the tree material and draw the sections of the tree
	treeMaterial.begin();
	top.draw();
	middle.draw();
	bottom.draw();
	treeMaterial.end();

	// Begin the star material and draw the star
	starMaterial.begin();
	star.draw();
	starMaterial.end();

	// Spin the tree (via the star
    star.rotate(1, 0, 1, 0);

}

// Function to set position of the tree
void XmasTree::SetPosition(float setX, float setY, float setZ){
	star.setPosition(setX, setY, setZ);

}

// Interaction function, when triggered changes the star colors to random color
void XmasTree::FlashStar(){
	starMaterial.setSpecularColor(ofFloatColor(ofRandom(0,1), ofRandom(0,1), ofRandom(0, 1)));
}

