#include "pch.h"
#include "Object.h"

Object::Object(int id) {
	this->id = id;
}

Object::~Object() {

}
double Object::getX() const {
	return x;
}
double Object::getY() const {
	return y;
}
void Object::setX(double x) {
	this->x = x;
}
void Object::setY(double y) {
	this->y = y;
}
int Object::getId() const {
	return id;
}