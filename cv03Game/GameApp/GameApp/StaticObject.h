#ifndef STATICOBJECT_H
#define STATICOBJECT_H

#include "Object.h"
#include "BarrierType.h"

struct StaticObject : Object
{
private:
	BarrierType barrierType;

public:

	StaticObject(int id, BarrierType barrierType);
	BarrierType getBarrierType() const;
};
#endif