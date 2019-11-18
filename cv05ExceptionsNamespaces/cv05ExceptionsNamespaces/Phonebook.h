#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Person.h"
#include "Element.h"
#include <string>
namespace Model {
	struct Phonebook {
	private:
		Element* _first;
	public:
		~Phonebook();
		Phonebook();
		void addPerson(Entity::Person *o);
		std::string findPhone(std::string name)const;
		std::string findPhone(int id)const;
	};
}


#endif // !PHONEBOOK_H