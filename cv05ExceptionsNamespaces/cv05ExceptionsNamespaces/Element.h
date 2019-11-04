#ifndef ELEMENT_H
#define ELEMENT_H

#include "Person.h"
struct Element
{
private:
	Entity::Person current;
	Element* next;
public:
	//PrvekSeznam::~PrvekSeznam;
	Entity::Person getPerson();
	void setOsoba(Entity::Person person);
	Element(Entity::Person current, Element* next);
};

#endif // !ELEMENT_H