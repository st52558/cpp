#include "dbapi.h"

// Otev�e datab�zi
static Db* open(std::string database) {

}
// Uzav�e datab�zi (dealokuje pam�ov� prost�edky)
void close() {}
// Vytvo�� novou tabulku
Table* Db::createTable(std::string name, int fieldsCount, FieldObject** fields) {
	
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tables[i]->name) 
		{
			// tady vypsat chybu (tabulka u� existuje)
			return nullptr;
		}
	}
	return new Table(name,fieldsCount,fields);
	
}
// Otev�e existuj�c� tabulku
Table* Db::openTable(std::string name) {
	for (int i = 0; i < tablesCount; i++)
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
	for (int i = 0; i < tablesCount; i++)
	{
		if (name == tables[i]->name)
		{
			return openTable(name);
		}
	}
	return new Table(name, fieldsCount, fields);
}
// Alokuje objekt �int�
Object* Db::Int(int value) {
	return new IntObject(value);
}
// Alokuje objekt �double�
Object* Db::Double(double value) {
	return new DoubleObject(value);
}
// Alokuje objekt �string�
Object* Db::String(std::string value) {
	return new StringObject(value);
}
// Alokuje objekt �field�
FieldObject* Db::Field(std::string name, FieldType type) {
	return new FieldObject(name, type);
}