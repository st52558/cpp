#include "Person.h"
#include <string>
using namespace std;
Entity::Person::Person(string name, string telefon, int id) {
	this->id = id;
	this->name = name;
	this->phone = telefon;
}
string Entity::Person::getName() {
	return name;
}
string Entity::Person::getPhone() {
	return phone;
}
int Entity::Person::getID() {
	return id;
}
void Entity::Person::setID(int id) {
	this->id = id;
}
void Entity::Person::setPhone(string telefon) {
	this->phone = phone;
}
void Entity::Person::setName(string name) {
	this->name = name;
}