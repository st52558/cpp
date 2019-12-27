#include "pch.h"
#include "dbapi.h"

Table::Table(std::string nameI, std::string databaseNameI) {
	// používá se, pokud se tabulka otevírá
	name = nameI;
	databaseName = databaseNameI;

	std::ifstream in{};
	in.open("./databases/" + databaseName + "_" + name + ".txt");
	std::string line;
	if (in.is_open()) {
		getline(in, line);
		fieldCount = std::stoi(line);
		fields = new FieldObject*[fieldCount];
		FieldType type;
		std::string typeN, value;
		for (int i = 0; i < fieldCount; i++)
		{
			getline(in, line);
			std::stringstream ss(line);
			getline(ss, typeN, ' ');
			getline(ss, value);
			if (typeN == "Integer") {
				type = FieldType::Integer;
			} else if (typeN == "Double") {
				type = FieldType::Double;
			} else if(typeN == "String") {
				type = FieldType::String;
			}
			else {
				type = FieldType::String;
			}
			fields[i] = new FieldObject(value, type);
		}
		getline(in, line);
		rowCount = std::stoi(line);
		table = new Object * *();
		for (int i = 0; i < rowCount; i++)
		{
			table[i] = nullptr; //TODO!!!
		}
		in.close(); 
	}
}

Table::Table(std::string nameI, int fieldsCount, FieldObject** fieldsI, std::string databaseNameI) {
	// používá se pokud je potøeba tabulku vytvoøit
	databaseName = databaseNameI;
	rowCount = 0;
	fields = fieldsI;
	table = new Object **();
	fieldCount = fieldsCount;
	name = nameI;
}

// Vložení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
void Table::insert(Object** row) {
	bool valid = true;
	for (int i = 0; i < fieldCount; i++)
	{
		IntObject* intObject = dynamic_cast<IntObject*>(row[i]);
		if (intObject != nullptr) {
			if (getFields()[i]->getType() != FieldType::Integer) {
				valid = false;
			}
		}

		StringObject* stringObject = dynamic_cast<StringObject*>(row[i]);
		if (stringObject != nullptr) {
			if (getFields()[i]->getType() != FieldType::String) {
				valid = false;
			}
		}

		DoubleObject* doubleObject = dynamic_cast<DoubleObject*>(row[i]);
		if (doubleObject != nullptr) {
			if (getFields()[i]->getType() != FieldType::Double) {
				valid = false;
			}
		}

	}
	if (valid) {
		table[rowCount] = row;
		rowCount++;
	}
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < fieldCount; j++)
		{
			// tady výpis podle typu 

		}
		std::cout << table[i][0]->getInt() << ", " << table[i][1]->getString() << std::endl;
	}
}
// Smazání vyrabného øádku z tabulky
void Table::remove(int rowid) {
	if (rowid < rowCount) {
		Object*** temp = new Object * *();
		int counter = 0;
		for (int i = 0; i < rowCount; i++)
		{
			if (rowid != rowCount) {
				temp[counter] = table[i];
				counter++;
			}
		}
		table = temp;
		rowCount--;
		//DESTRUKTOR!!!!!!!!!!!!!!!!!!!!!
	}
}
// Select – vytvoøí iterátor k procházení tabulky
Iterator* Table::select() {
	return nullptr;
}
// Commit – pøenese zmìny z pamìti do datových souborù
void Table::commit() {
	std::ofstream outfile("./databases/" + databaseName + "_" + name + ".txt");

	outfile << fieldCount << std::endl;
	for (int i = 0; i < fieldCount; i++)
	{
		if (fields[i]->isType(FieldType::Integer)) {
			outfile << "Integer " << fields[i]->getName() << std::endl;
		}
		else if (fields[i]->isType(FieldType::Double)) {
			outfile << "Double " << fields[i]->getName() << std::endl;
		}
		else if (fields[i]->isType(FieldType::String)) {
			outfile << "String " << fields[i]->getName() << std::endl;
		}
	}
	outfile << rowCount << std::endl;
	for (int i = 0; i < rowCount; i++)
	{
		// tady dopsat data v tabulkách
	}
	outfile.close();
}
// Uzavøe tabulku (dealokuje pamìové prostøedky)
void Table::close() {}
// Vrací poèet øádkù v tabulce
int Table::getRowCount() const {
	return rowCount;
}
// Vrací pole FieldObject* popisující sloupeèky tabulky
FieldObject** Table::getFields() const {
	return fields;
}
// Vrací poèet sloupeèkù
int Table::getFieldCount() const {
	return fieldCount;
}