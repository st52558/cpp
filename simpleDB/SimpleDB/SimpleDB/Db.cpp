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
			return nullptr;
		}
	}
	Table* newTable = new Table();
	newTable->name = name;
	newTable->fields = fields;

}
// Otevøe existující tabulku
Table* openTable(std::string name);
// Otevøe tabulku (pokud neexistuje, vytvoøí automaticky novou)
Table* openOrCreateTable(std::string name, int fieldsCount, FieldObject** fields);
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