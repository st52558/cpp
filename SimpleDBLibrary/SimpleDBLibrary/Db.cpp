#include "pch.h"
#include "dbapi.h"


// Otevøe databázi


Db::Db(std::string nameI, std::string* tablesNamesI, int tablesCountI) {
	name = nameI;
	tablesCount = tablesCountI;
	for (int i = 0; i < tablesCount; i++)
	{
		tablesNames[i] = tablesNamesI[i];
	}
	
}

Db* Db::open(std::string database) {
	std::string tables[100];
	int count = 0;
	std::string line;
	std::ifstream in{};
	in.open("./databases/" + database + ".txt");

	if (in.is_open()) {
		while (getline(in, line)) {
			count++;
		}
		in.close();
	}
	else {
		std::cout << "Unable to open file";
	}
	
	in.open("./databases/" + database + ".txt");
	if (in.is_open()) {
		int counter = 0;
		while (getline(in, line)) {
			tables[counter] = line;
			counter++;
		}
		in.close();
	}
	
	std::cout << "TABLE NAMES:" << std::endl;
	for (int i = 0; i < count; i++)
	{
		std::cout << tables[i] << std::endl;
	}
	return new Db(database,tables, count);
}
// Uzavøe databázi (dealokuje pamìové prostøedky)
void Db::close() {

}
// Vytvoøí novou tabulku
Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields) {
	tablesNames[tablesCount] = name;
	tablesCount++;
	std::ofstream outfile("./databases/" + this->name + ".txt", std::ofstream::app);
	outfile << std::endl << name ;
	outfile.close();
	openedTable = new Table(name, fieldsCount, fields, this->name);
	return openedTable;

}
// Otevøe existující tabulku
Table* Db::openTable(std::string name) {
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tablesNames[i])
		{
			openedTable = new Table(name, this->name);
			return openedTable;
		}
	}
	// vypsat chybu (špatný název tabulky)
}
// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields) {
	
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tablesNames[i])
		{
			return openTable(name);
		}
	}
	return createTable(name, fieldsCount, fields);
}
// Alokuje objekt „int“
Object* Db::Int(int value) {
	return new IntObject(value);
}
// Alokuje objekt „double“
Object* Db::Double(double value) {
	return new DoubleObject(value);
}
// Alokuje objekt „string“
Object* Db::String(std::string value) {
	return new StringObject(value);
}
// Alokuje objekt „field“
FieldObject* Db::Field(std::string name, FieldType type) {
	return new FieldObject(name, type);
}