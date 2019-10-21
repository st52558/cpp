#include "pch.h"
#include "Monster.h"

Monster::Monster(int id) : MovableObject(id) {

}

int Monster::getHp() const {
	return hp;
}
void Monster::setHp(int hp) {
	this->hp = hp;
}
int Monster::getMaxHp() const {
	return maxhp;
}
void Monster::setMaxHp(int maxhp) {
	this->maxhp = maxhp;
}