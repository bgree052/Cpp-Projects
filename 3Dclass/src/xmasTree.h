/*
 * xmasTree.h
 *
 *  Created on: 27 Nov 2017
 *      Author: Connor Brooks
 */

#ifndef SRC_XMASTREE_H_
#define SRC_XMASTREE_H_
#include "ofMain.h"

class XmasTree {
public:
	XmasTree();
	void Draw();
	void SetPosition(float x, float y, float z);
	void FlashStar();
private:
	ofBoxPrimitive present, trunk;
	ofConePrimitive bottom, middle, top;
	ofSpherePrimitive star;
	ofMaterial treeMaterial, trunkMaterial, starMaterial;

};



#endif /* SRC_XMASTREE_H_ */
