#ifndef ELEMENT_H
#define ELEMENT_H

#include "Person.h"
struct Element
{
public:
	Entity::Person* current;
	Element* next;
	~Element();
	Element() : current(nullptr), next(nullptr) {}
};

#endif // !ELEMENT_H