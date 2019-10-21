#ifndef GAME_H
#define GAME_H
#include "Object.h"
#include "MovableObject.h"
#include "StaticObject.h"
struct Game
{
private:
	Object** objects;
	int count;
public:
	Game();
	void insertObject(Object* o);
	int* findStaticObjectsIds(double xmin, double xmax, double ymin, double ymax) const;
	MovableObject** findMovableObjectsInArea(double x, double y, double r) const;
	MovableObject** findMovableObjectsInArea(double x, double y, double r, double umin, double umax) const;

};
#endif
