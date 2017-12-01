#include "car.h"

Car::Car() {
	wheel1.setParent(carBody);
	wheel2.setParent(carBody);
	wheel3.setParent(carBody);
	wheel4.setParent(carBody);
	wheel1.setPosition(-100, 200, 100);
	wheel2.setPosition(100, 200, 100);
	wheel3.setPosition(-100, 200, 0);
	wheel4.setPosition(100, 200, 0);
	wheel1.setRadius(100);
	wheel2.setRadius(100);
	wheel3.setRadius(100);
	wheel4.setRadius(100);
	carBody.setWidth(400);
	carBody.setDepth(400);
}

void Car::setPosition(float x, float y, float z) {
	carBody.setPosition(x, y, z);
}

void Car::draw() {
	carBody.rotate(1, 0, 1, 0);

	wheel1.draw();
	wheel2.draw();
	wheel3.draw();
	wheel4.draw();
	carBody.draw();
}