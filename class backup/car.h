#ifndef CAR_H
#define CAR_H

#include "ofMain.h"

class Car
{
public:
	Car();
	void draw();
	void setPosition(float x, float y, float z);
private:
	ofSpherePrimitive wheel1;
	ofSpherePrimitive wheel2;
	ofSpherePrimitive wheel3;
	ofSpherePrimitive wheel4;
	ofBoxPrimitive carBody;
};

#endif // CAR_H
