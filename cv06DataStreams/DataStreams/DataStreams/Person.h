#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"

struct Person
{
public:
	std::string _name;
	std::string _surname;
	Address _address;
	Date _dateOfBirth;

	std::string getName() const { return _name; }
	std::string getSurname() const { return _surname; }
	void setName(std::string name) { _name = name; }
	void setSurname(std::string surname) { _surname = surname; }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
	os << person.getName() << person.getSurname() << ", " << person._dateOfBirth << person._address;
	return os;
}
std::istream& operator>>(std::istream& is, Person& person) {
	std::string name;
	is >> name;
	person.setName(name);

	std::string surname;
	is >> surname;
	person.setSurname(surname.substr(0, surname.length() - 1));

	Date date;
	is >> date;
	person._dateOfBirth = date;

	Address address;
	is >> address;
	person._address = address;

	return is;
}
#endif // !PERSON
