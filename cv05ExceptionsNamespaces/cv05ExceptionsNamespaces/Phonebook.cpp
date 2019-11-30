#include "Phonebook.h"
#include "Exceptions.h"

Model::Phonebook::~Phonebook() {
	Element* actual = _first;
	if (actual != nullptr)
	{
		do {
			Element* temp = actual->next;
			delete actual;
			actual = temp;

		} while (actual->next != nullptr);
	}
	
}
Model::Phonebook::Phonebook() {
	_first = nullptr;
}
void Model::Phonebook::addPerson(Entity::Person *o) {
	Element* newElement = new Element();
	newElement->current = o;
	if (_first == nullptr) {
		newElement->next = nullptr;
		_first = newElement;
	}
	else {
		Element* temp = _first;
		newElement->next = temp;
		_first = newElement;
	}
}
std::string Model::Phonebook::findPhone(std::string name) const {
	if (_first == nullptr) {
		throw ElementNotFound("List je prazdny");
	}
	if (name.empty())
	{
		throw InvalidArgument("Jmeno neni vyplnene");
	}
	Element* actual = _first;
	do {
		if (actual->current->getName() == name) {
			return actual->current->getPhone();
		}
		actual = actual->next;
	} while (actual->next != nullptr);
	throw ElementNotFound(name + " nenalezen");
}
std::string Model::Phonebook::findPhone(int id) const {
	if (_first == nullptr) {
		throw ElementNotFound("List je prazdny");
	}
	if (id < 0)
	{
		throw InvalidArgument(std::to_string(id) + " je neplatne");
	}
	Element* actual = _first;
	do {
		if (actual->current->getID() == id) {
			return actual->current->getPhone();
		}
		actual = actual->next;
	} while (actual->next != nullptr);
	throw ElementNotFound(std::to_string(id) + " nenalezen");
}