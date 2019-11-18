#ifndef PERSON_H
#define PERSON_H


#include <string>
namespace Entity {
	struct Person
	{
	private:
		std::string name;
		std::string phone;
		int id;
	public:
		Person(std::string name, std::string phone, int id);
		Person();
		~Person();
		std::string getName() const;
		std::string getPhone() const;
		int getID() const;
		void setID(int id);
		void setPhone(std::string phone);
		void setName(std::string name);
	};
}

#endif // !PERSON_H