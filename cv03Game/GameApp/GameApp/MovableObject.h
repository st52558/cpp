#ifndef MOVABLEOBJECT_H
#define MOVABLEOBJECT_H

#include "Object.h"

struct MovableObject : Object
{
private:
	double angle;

public:
	MovableObject(int id);
	double getAngle() const;
	void setAngle(double angle);
};

#endif