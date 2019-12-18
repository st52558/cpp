#include "dbapi.h"

Table::Table(std::string nameI, int fieldsCount, FieldObject** fieldsI) {
	rowCount = 0;
	fields = fieldsI;
	table = new Object**();
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
	}
}
// Smazání vyrabného øádku z tabulky
void Table::remove(int rowid) {
	if (rowid < rowCount) {
		Object*** temp = new Object**();
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
Iterator* select() {
	return nullptr;
}
// Commit – pøenese zmìny z pamìti do datových souborù
void commit();
// Uzavøe tabulku (dealokuje pamìové prostøedky)
void close();
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
// ============== Bonusové metody: ================
// Select s podmínkou
Iterator* select(Condition* condition) { throw 0; }
// Nalezení rowId s podmínkou
int findRowId(Condition* condition) { throw 0; }
// Update – aktualizuje øádky vyhovující podmínce, aktualizaci provádí funkce „callback“
// callback na vstupu obdrží data øádku a vrací data
void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }

// Polymorfní datový objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno