

#include "pch.h"
#include <iostream>
#include "Game.h"

int main()
{
	Game* game = new Game();
	MovableObject* movable = new MovableObject(1);
	movable->setX(1);
	movable->setY(1);
	movable->setAngle(0);
	game->insertObject(movable);
	StaticObject* staticObject = new StaticObject(2, BarrierType::BigFlower);
	staticObject->setX(2);
	staticObject->setY(2);
	game->insertObject(staticObject);
	int* statics = game->findStaticObjectsIds(0, 0, 5, 5);
	std::cout << statics[0] << std::endl;
	//game->findMovableObjectsInArea(0, 0, 10);
	//std::cout << statics[0] << std::endl;
}
