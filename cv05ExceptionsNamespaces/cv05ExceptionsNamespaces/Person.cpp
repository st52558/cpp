#include "Person.h"
#include <string>
Entity::Person::Person(std::string name, std::string telefon, int id) {
	this->id = id;
	this->name = name;
	this->phone = telefon;
}
Entity::Person::Person() {
}
Entity::Person::~Person() {

}
std::string Entity::Person::getName() const{
	return name;
}
std::string Entity::Person::getPhone() const{
	return phone;
}
int Entity::Person::getID() const{
	return id;
}
void Entity::Person::setID(int id) {
	this->id = id;
}
void Entity::Person::setPhone(std::string telefon) {
	this->phone = phone;
}
void Entity::Person::setName(std::string name) {
	this->name = name;
}