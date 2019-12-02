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



void saveBinary() {
	Person** persons = new Person * [3];
	int personCount = 3;
	persons[0] = new Person("Petr", "Cerveny", new Address("Zelena", "Praha", 10000), new Date(21, 5, 1984));
	persons[1] = new Person("Pavel", "Zluty", new Address("Bila", "Brno", 20000), new Date(2, 4, 1991));
	persons[2] = new Person("Roman", "Cerny", new Address("Cervena", "Pardubice", 33333), new Date(16, 10, 1996));

	std::ofstream stream{ "././output.dat",std::ios_base::out | std::ios_base::binary };

	
	std::string name;
	std::string surname;
	std::string street;
	std::string city;
	int zipCode;
	size_t variableSize;
	
	stream.write((char*)& personCount, sizeof(personCount));

	for (int i = 0; i < 3; i++)
	{
		Person* person = persons[i];
		name = person->getName();
		variableSize = name.size();
		stream.write((char*)& variableSize, sizeof(variableSize));
		stream.write(name.c_str(), variableSize);

		surname = person->getSurname();
		variableSize = surname.size();
		stream.write((char*)& variableSize, sizeof(variableSize));
		stream.write(surname.c_str(), surname.size());

		stream.write((char*)& person->getDate(), sizeof(person->getDate()));

		street = person->getAddress().getStreet();
		variableSize = street.size();
		stream.write((char*)& variableSize, sizeof(variableSize));
		stream.write(street.c_str(), street.size());

		city = person->getAddress().getCity();
		variableSize = city.size();
		stream.write((char*)& variableSize, sizeof(variableSize));
		stream.write(city.c_str(), city.size());

		int zipCode = person->getAddress().getZipCode();
		stream.write((char*)& zipCode, sizeof(zipCode));
	}

	stream.close();
}

void loadBinary() {
	std::ifstream stream{ "././output.dat", std::ios_base::in | std::ios_base::binary };

	stream.seekg(0, std::ios_base::end);
	int size = stream.tellg();
	stream.seekg(0, std::ios_base::beg);

	Date* date;
	std::string name;
	std::string surname;
	std::string street;
	std::string city;
	int zipCode;
	size_t variableSize;

	Person** persons = new Person*[3];

	for (int i = 0; i < 3; i++)
	{
		stream.read((char*)& size, sizeof(size));
		name.resize(size);
		stream.read((char*)& name[0], size);

		stream.read((char*)& size, sizeof(size));
		surname.resize(size);
		stream.read((char*)& surname[0], size);

		stream.read((char*)& date, sizeof(date));

		stream.read((char*)& size, sizeof(size));
		street.resize(size);
		stream.read((char*)& street[0], size);

		stream.read((char*)& size, sizeof(size));
		city.resize(size);
		stream.read((char*)& city[0], size);

		stream.read((char*)& zipCode, sizeof(zipCode));

		persons[i] = new Person(name, surname, new Address(street, city, zipCode), date);
	}
}

int main(int agrc, char** argv)
{
	save();
	load();
	saveBinary();
	loadBinary();
}

