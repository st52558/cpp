#include "Phonebook.h"
#include "Exceptions.h"
#include <iostream>

int main(int agrc, char** argv)
{
	Model::Phonebook phonebook;
	/*Entity::Person* person1 = new Entity::Person("Petr Cerveny", "123 456 000", 1);
	Entity::Person* person2 = new Entity::Person("Tomas Zeleny", "123 456 111", 2);
	Entity::Person* person3 = new Entity::Person("Pavel Zluty", "123 456 222", 3);
	Entity::Person* person4 = new Entity::Person("Vojtech Cerny", "123 456 333", 4);
	Entity::Person* person5 = new Entity::Person("Josef Bily", "123 456 444", 5);

	phonebook.addPerson(person1);
	phonebook.addPerson(person2);
	phonebook.addPerson(person3);
	phonebook.addPerson(person4);
	phonebook.addPerson(person5);*/

	try {
		std::cout << "tel. osoby s ID 3: " << phonebook.findPhone(2) << std::endl;
		std::cout << "tel. Jana Mala: " << phonebook.findPhone("Vojtech Cerny") << std::endl;
		//std::cout << "tel. osoby s ID 6: " << phonebook.findPhone(6) << std::endl;
		//std::cout << "tel. " << phonebook.findPhone("") << std::endl;
		//std::cout << "tel. " << phonebook.findPhone("asd") << std::endl;
		std::cout << "tel. osoby s ID 6: " << phonebook.findPhone(-1) << std::endl;
	}
	catch (ElementNotFound &enf){
		std::cout << enf.GetMessage() << std::endl;
	}
	catch (InvalidArgument &ia) {
		std::cout << ia.GetMessage() << std::endl;
	}
	return 0;
}