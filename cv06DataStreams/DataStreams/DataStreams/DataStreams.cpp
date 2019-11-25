#include "Person.h"
#include <fstream>
#include <sstream>

void writeToConsole(Person** persons, int count) {
	for (int i = 0; i < count; i++)
	{
		std::cout << *persons[i] << std::endl;
	}
}

void load() {
	Person** persons = nullptr;
	std::string line;
	int personsCount = 0;

	std::ifstream in{};
	in.open("././output.txt");

	while (getline(in, line)) {
		personsCount++;
	}

	in.clear();
	in.seekg(0);

	persons = new Person*[personsCount];

	std::string surname;
	std::string name;
	int day;
	int month;
	int year;
	std::string street;
	std::string city;
	int zipCode;

	int counter = 0;
	char delimiter = ',';
	char delimiterDot = '.';
	char delimiterSpacebar = ' ';
	std::string token;

	while (getline(in, line)) {
		std::stringstream ss(line);
		getline(ss, name, delimiterSpacebar);
		getline(ss, surname, delimiter);
		getline(ss, token, delimiterDot);
		day = stoi(token);
		getline(ss, token, delimiterDot);
		month = stoi(token);
		getline(ss, token, delimiter);
		year = stoi(token);
		getline(ss, street, delimiter);
		getline(ss, city, delimiter);
		getline(ss, token, '\n');
		zipCode = stoi(token);

		persons[counter] = new Person(name, surname, new Address(street, city, zipCode), new Date(day, month, year));
		counter++;
	}
	in.close();
	writeToConsole(persons, personsCount);

	for (int i = 0; i < 3; i++)
	{
			delete persons[i];
	}

	delete[] persons;
	}

void save() {
	Person** persons = new Person * [3];

	persons[0] = new Person("Petr", "Cerveny", new Address("Zelena", "Praha", 10000), new Date(21, 5, 1984));
	persons[1] = new Person("Pavel", "Zluty", new Address("Bila", "Brno", 20000), new Date(2, 4, 1991));
	persons[2] = new Person("Roman", "Cerny", new Address("Cervena", "Pardubice", 33333), new Date(16, 10, 1996));

	std::ofstream out{};
	out.open("././output.txt");

	for (int i = 0; i < 3; i++)
	{
		out << *persons[i] << std::endl;
	}
	out.close();


	for (int i = 0; i < 3; i++)
	{
		delete persons[i];
	}
	delete[] persons;
}

int main(int agrc, char** argv)
{
	save();
	load();
}

