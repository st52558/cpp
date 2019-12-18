#include "dbapi.h"
#include <iostream>

FieldObject** combineToDefinition(FieldObject* f, FieldObject* g) {
	FieldObject** definition = new FieldObject*();
	definition[0] = f;
	definition[1] = g;
	return definition;
}

Object** combineToRow(Object* f, Object* g) {
	Object** row = new Object*();
	row[0] = f;
	row[1] = g;
	return row;
}

int main(int agrc, char** argv)
{
	
	Db* db = Db::open("testdb");
	
	// Vytvo�en�/otev�en� tabulky
	/*auto idField = Db::Field("id", FieldType::Integer);
	auto nameField = Db::Field("name", FieldType::String);
	auto userFields = combineToDefinition(idField, nameField);
	Table* users = db->openOrCreateTable("users", 2, userFields);
	// Vlo�en� ��dku do tabulky
	auto id = Db::Int(15);
	auto name = Db::String("Peter");
	auto row = combineToRow(id, name);
	users->insert(row);
	// Select
	auto it = users->select();
	while (it->moveNext())
	{
		auto row = it->getRow();
		std::cout << row[0]->getInt() << ": " << row[1]->getString() << std::endl;
	}
	it->close();
	// Ulo�en� tabulky na disk
	users->commit();
	// Uzav�en� tabulky (a dealokace pam�ov�ch prost�edk�)
	users->close();
	// Uzav�en� db (a dealokace pam�ov�ch prost�edk�)
	db->close();*/
}