#include "pch.h"
#include "Game.h"
#include <cmath>

Game::Game() {
	count = 0;
	objects = new Object*[100];
}

Game::~Game() {
	for (size_t i = 0; i < count; i++)
	{
		delete objects[i];
	}

	delete[] objects;
}


void Game::insertObject(Object* o) {
	Object** temp = new Object*[count];
	for (int i = 0; i < count; i++)
	{
		temp[i] = objects[i];
	}
	temp[count] = o;
	objects = temp;
	count++;
}

int* Game::findStaticObjectsIds(double xmin, double xmax, double ymin, double ymax) const {
	int staticObjectsCounter = 0;
	for (int i = 0; i < count; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr) {
			if (so->getX() > xmin && so->getX() < xmax && so->getY() < ymax && so->getY() > ymin) {
				staticObjectsCounter++;
			}
		}
	}
	int* ids = new int[staticObjectsCounter];
	if (staticObjectsCounter==0)
	{
		return nullptr;
	}
	staticObjectsCounter = 0;
	
	for (int i = 0; i < count; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr) {
			if (so->getX() > xmin && so->getX() < xmax && so->getY() < ymax && so->getY() > ymin) {
				ids[staticObjectsCounter] = so->getId();
				staticObjectsCounter++;
			}
		}
	}
	return ids;
}
MovableObject** Game::findMovableObjectsInArea(double x, double y, double r) const {
	int movableObjectsCounter = 0;

	for (int i = 0; i < count; i++)
	{
		MovableObject* mo = dynamic_cast<MovableObject*>(objects[i]);
		if (mo != nullptr) {
			if (abs(mo->getX()-x) < r && abs(mo->getY() - y) < r) {
				movableObjectsCounter++;
			}
		}
	}
	if (movableObjectsCounter == 0)
	{
		return nullptr;
	}
	MovableObject** movableObjects = new MovableObject*[movableObjectsCounter];
	
	movableObjectsCounter = 0;
	
	for (int i = 0; i < count; i++)
	{
		MovableObject* mo = dynamic_cast<MovableObject*>(objects[i]);
		if (mo != nullptr) {
			if (abs(mo->getX() - x) < r && abs(mo->getY() - y) < r) {
				movableObjects[movableObjectsCounter] = mo;
				movableObjectsCounter++;
			}
		}
	}
	return movableObjects;
}
MovableObject** Game::findMovableObjectsInArea(double x, double y, double r, double umin, double umax) const {
	int movableObjectsCounter = 0;
	for (int i = 0; i < count; i++)
	{
		MovableObject* mo = dynamic_cast<MovableObject*>(objects[i]);
		if (mo != nullptr) {
			if (abs(mo->getX() - x) < r && abs(mo->getY() - y) < r && mo->getAngle() < umax && mo->getAngle() > umin) {
				movableObjectsCounter++;
			}
		}
	}
	MovableObject** movableObjects = new MovableObject*[movableObjectsCounter];
	if (movableObjectsCounter == 0)
	{
		return nullptr;
	}
	movableObjectsCounter = 0;

	for (int i = 0; i < count; i++)
	{
		MovableObject* mo = dynamic_cast<MovableObject*>(objects[i]);
		if (mo != nullptr) {
			if (abs(mo->getX() - x) < r && abs(mo->getY() - y) < r && mo->getAngle() < umax && mo->getAngle() > umin) {
				movableObjects[movableObjectsCounter] = mo;
				movableObjectsCounter++;
			}
		}
	}
	return movableObjects;
}