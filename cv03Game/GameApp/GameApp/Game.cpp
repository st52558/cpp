#include "pch.h"
#include "Game.h"



Game::Game() {
	count = 0;
	//objects = new Object*[count];
	objects = new Object*[100];
}

void Game::insertObject(Object* o) {
	
	//Object** temp = new Object*[count];
	/*for (int i = 0; i < count-1; i++)
	{
		temp[i] = objects[i];
	}*/
	//temp[count] = o;
	//objects = temp;
	objects[count] = o;
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
	for (int i = 0; i < count; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr) {
			if (so->getX() > xmin && so->getX() < xmax && so->getY() < ymax && so->getY() > ymin) {
				ids[i] = so->getId();
				i++;
			}
		}
	}
	return ids;
}
MovableObject** Game::findMovableObjectsInArea(double x, double y, double r) const {
	return nullptr;
}
MovableObject** Game::findMovableObjectsInArea(double x, double y, double r, double umin, double umax) const {
	return nullptr;
}