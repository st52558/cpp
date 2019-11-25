#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Address.h"
#include "Date.h"

struct Person
{
private:
	std::string _name;
	std::string _surname;
	Address* _address;
	Date* _dateOfBirth;
public:
	Person(std::string name, std::string surname, Address* address, Date* date) : _name(name), _surname(surname), _address(address), _dateOfBirth(date) {};
	std::string getName() const { return _name; }
	std::string getSurname() const { return _surname; }
	Address getAddress() const { return *_address; }
	Date getDate() const { return *_dateOfBirth; }
	void setName(std::string name) { _name = name; }
	void setSurname(std::string surname) { _surname = surname; }
	void setAddress(Address* address) { _address = address; }
	void setDate(Date* date) { _dateOfBirth = date; }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
	os << person.getName() << " " << person.getSurname() << ", " << person.getDate() << person.getAddress();
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
	person.setDate(&date);

	Address address;
	is >> address;
	person.setAddress(&address);

	return is;
}
#endif // !PERSON
