#include "dbapi.h"

// Otevøe databázi
static Db* open(std::string database) {}
// Uzavøe databázi (dealokuje pamìové prostøedky)
void close() {}
// Vytvoøí novou tabulku
Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields) {
	
	for (int i = 0; i < count; i++)
	{
		if (name == tables[i]->name) 
		{
			// tady vypsat chybu (tabulka u existuje)
			return nullptr;
		}
	}
	Table* newTable = new Table();
	newTable->name = name;
	newTable->fields = fields;
	newTable->fieldCount = fieldsCount;
	return newTable;
}
// Otevøe existující tabulku
Table* Db::openTable(std::string name) {
	for (int i = 0; i < count; i++)
	{
		if (name == tables[i]->name)
		{
			return tables[i];
		}
	}
	// vypsat chybu (špatnı název tabulky)
}
// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
Table* Db::openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields) {
	for (int i = 0; i < count; i++)
	{
		if (name == tables[i]->name)
		{
			return openTable(name);
		}
	}
	Table* newTable = new Table();
	newTable->name = name;
	newTable->fields = fields;
	newTable->fieldCount = fieldsCount;
	return newTable;
}
// Alokuje objekt „int“
static Object* Int(int value);
// Alokuje objekt „double“
static Object* Double(double value);
// Alokuje objekt „string“
static Object* String(std::string value) {
	
}
// Alokuje objekt „field“
static FieldObject* Field(std::string name, FieldType type) {
	return new FieldObject(name, type);
}