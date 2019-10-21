#ifndef MONSTER_H
#define MONSTER_H
#include "MovableObject.h"

struct Monster : MovableObject
{
private:
	int hp;
	int maxhp;

public:
	Monster(int id);
	int getHp() const;
	void setHp(int hp);
	int getMaxHp() const;
	void setMaxHp(int maxhp);
};
#endif