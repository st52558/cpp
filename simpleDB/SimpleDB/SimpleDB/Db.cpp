#include "dbapi.h"

// Otev�e datab�zi
static Db* open(std::string database) {}
// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
void close() {}
// Vytvo�� novou tabulku
Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields) {
	
	for (int i = 0; i < count; i++)
	{
		if (name == tables[i]->name) 
		{
			// tady vypsat chybu (tabulka u� existuje)
			return nullptr;
		}
	}
	Table* newTable = new Table();
	newTable->name = name;
	newTable->fields = fields;
	newTable->fieldCount = fieldsCount;
	return newTable;
}
// Otev�e existuj�c� tabulku
Table* Db::openTable(std::string name) {
	for (int i = 0; i < count; i++)
	{
		if (name == tables[i]->name)
		{
			return tables[i];
		}
	}
	// vypsat chybu (�patn� n�zev tabulky)
}
// Otev�e tabulku (pokud neexistuje, vytvo�� automaticky novou)
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
// Alokuje objekt �int�
static Object* Int(int value);
// Alokuje objekt �double�
static Object* Double(double value);
// Alokuje objekt �string�
static Object* String(std::string value) {
	
}
// Alokuje objekt �field�
static FieldObject* Field(std::string name, FieldType type) {
	return new FieldObject(name, type);
}