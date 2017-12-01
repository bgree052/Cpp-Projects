#include "car.h"

Car::Car() {

    
    basic.setDiffuseColor(ofFloatColor(129,129,129));
    
	wheel1.setParent(carBody);
	wheel2.setParent(carBody);
	wheel3.setParent(carBody);
	wheel4.setParent(carBody);
    
    wheel1.setResolution(50, 2);
    wheel2.setResolution(50, 2);
    wheel3.setResolution(50, 2);
    wheel4.setResolution(50, 2);
    
	wheel1.setPosition(-100, 100, 100);
	wheel2.setPosition(100, 100, 100);
	wheel3.setPosition(-100, 100, -100);
	wheel4.setPosition(100, 100, -100);
    
    wheel1.setOrientation(ofVec3f(90,0,0));
    wheel2.setOrientation(ofVec3f(90,0,0));
    wheel3.setOrientation(ofVec3f(90,0,0));
    wheel4.setOrientation(ofVec3f(90,0,0));
    
	wheel1.set(50,20);
	wheel2.set(50,20);
	wheel3.set(50,20);
	wheel4.set(50,20);
    
	carBody.setWidth(300);
    carBody.setHeight(200);
	carBody.setDepth(200);
    
    tireImg.load("wheel.jpg");
    sideView.load("carriageSide.png");
}

void Car::onMouseClick(int x, int y, int button)
{
    switcher = !switcher;
}

void Car::setPosition(float x, float y, float z) {
	carBody.setPosition(x, y, z);
    
}

void Car::draw() {

    if(switcher == true){
        rot = 1;
    }
    else if (switcher == false){
        rot = -1;
    }
	carBody.rotate(rot, 0, 1, 0);
    
    tireImg.getTexture().bind();
    
	wheel1.draw();
	wheel2.draw();
	wheel3.draw();
	wheel4.draw();
    
    tireImg.getTexture().unbind();
    
    //sideView.getTexture().bind();
    basic.begin();
	carBody.draw();
    basic.end();
    //sideView.getTexture().unbind();
    

    //camera.end();
}
