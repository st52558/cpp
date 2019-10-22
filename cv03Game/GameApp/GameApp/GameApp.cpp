

#include "pch.h"
#include <iostream>
#include "Game.h"

int main()
{
	Game* game = new Game();

	//working with movable objects
	MovableObject* movable = new MovableObject(1);
	movable->setX(1);
	movable->setY(1);
	movable->setAngle(0);
	game->insertObject(movable);
	MovableObject* movable2 = new MovableObject(4);
	movable2->setX(2);
	movable2->setY(2);
	movable2->setAngle(10);
	game->insertObject(movable2);
	MovableObject** movables = game->findMovableObjectsInArea(0, 0, 2.2);
	if (movables != nullptr)
	{
		// nefunguje (i=1, i když by mìlo být i=2)
		for (int i = 0; i < sizeof(movables) / sizeof(MovableObject*); i++)
		{
			std::cout << "Movable object in area:" << movables[i]->getId() << std::endl;
		}
	}
	movables = game->findMovableObjectsInArea(0, 0, 5, 5, 15);
	if (movables != nullptr)
	{
		for (int i = 0; i < sizeof(movables) / sizeof(MovableObject*); i++)
		{
			std::cout << "Movable object in area with angle:" << movables[i]->getId() << std::endl;
		}
	}

	// working with static objects
	StaticObject* staticObject = new StaticObject(2, BarrierType::BigFlower);
	staticObject->setX(2);
	staticObject->setY(2);
	StaticObject* staticObject2 = new StaticObject(3, BarrierType::BigFlower);
	staticObject2->setX(1);
	staticObject2->setY(1);
	game->insertObject(staticObject);
	game->insertObject(staticObject2);
	int* statics = game->findStaticObjectsIds(0, 1.5, 0, 1.5);
	if (statics != nullptr)
	{
		for (int i = 0; i < sizeof(statics) / sizeof(int); i++)
		{
			std::cout << "Static object in area:" << statics[i] << std::endl;
		}
	}
	
}
