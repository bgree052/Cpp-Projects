#ifndef CAR_H
#define CAR_H

#include "ofMain.h"

class Car
{
public:
	Car();
	void draw();
	void setPosition(float x, float y, float z);
    void onMouseClick(int x, int y, int button);
private:
	ofCylinderPrimitive wheel1;
	ofCylinderPrimitive wheel2;
	ofCylinderPrimitive wheel3;
	ofCylinderPrimitive wheel4;
	ofBoxPrimitive carBody;
    ofMaterial basic;
    ofImage tireImg;
    ofImage sideView;

    int rot = 1;
    bool switcher = true;
};

#endif // CAR_H
