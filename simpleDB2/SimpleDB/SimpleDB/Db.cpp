#include "dbapi.h"

// Otevøe databázi
Db* Db::open(std::string database) {
	name = database;
	std::string path = "./";
	for (const auto& entry : std::filesystem::directory_iterator(path))
		std::cout << entry.path() << std::endl;
	return nullptr;
}
// Uzavøe databázi (dealokuje pamìové prostøedky)
void close() {}
// Vytvoøí novou tabulku
Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields) {
	
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tables[i]->name) 
		{
			// tady vypsat chybu (tabulka už existuje)
			return nullptr;
		}
	}
	return new Table(name,fieldsCount,fields);
	
}
// Otevøe existující tabulku
Table* Db::openTable(std::string name) {
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tables[i]->name)
		{
			return tables[i];
		}
	}
	// vypsat chybu (špatný název tabulky)
}
// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields) {
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tables[i]->name)
		{
			return openTable(name);
		}
	}
	return new Table(name, fieldsCount, fields);
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