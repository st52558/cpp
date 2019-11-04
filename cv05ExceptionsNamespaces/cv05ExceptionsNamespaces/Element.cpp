#include "Element.h"
Entity::Person getOsoba() {

}
void setOsoba(Entity::Person osoba) {

}
Element::Element(Entity::Person current, Element* next) {
	this->current = current;
	this->next = next;
}