#include "pch.h"
#include "MovableObject.h"

MovableObject::MovableObject(int id) : Object(id) {

}

double MovableObject::getAngle() const {
	return angle;
}
void MovableObject::setAngle(double angle) {
	this->angle = angle;
}