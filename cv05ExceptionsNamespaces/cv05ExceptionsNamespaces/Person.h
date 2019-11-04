#ifndef PERSON_H
#define PERSON_H


#include <string>
namespace Entity {
	using namespace std;
	struct Person
	{
	private:
		string name;
		string phone;
		int id;
	public:
		Entity::Person(string name, string phone, int id);
		string getName();
		string getPhone();
		int getID();
		void setID(int id);
		void setPhone(string phone);
		void setName(string name);
	};
}

#endif // !PERSON_H