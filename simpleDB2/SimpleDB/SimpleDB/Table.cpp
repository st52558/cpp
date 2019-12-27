#include "dbapi.h"

Table::Table(std::string nameI, int fieldsCount, FieldObject** fieldsI) {
	rowCount = 0;
	fields = fieldsI;
	table = new Object**();
	fieldCount = fieldsCount;
	name = nameI;
}

// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
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
// Smaz�n� vyrabn�ho ��dku z tabulky
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
// Select � vytvo�� iter�tor k proch�zen� tabulky
Iterator* select() {
	return nullptr;
}
// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
void commit();
// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
void close();
// Vrac� po�et ��dk� v tabulce
int Table::getRowCount() const {
	return rowCount;
}
// Vrac� pole FieldObject* popisuj�c� sloupe�ky tabulky
FieldObject** Table::getFields() const {
	return fields;
}
// Vrac� po�et sloupe�k�
int Table::getFieldCount() const {
	return fieldCount;
}
// ============== Bonusov� metody: ================
// Select s podm�nkou
Iterator* select(Condition* condition) { throw 0; }
// Nalezen� rowId s podm�nkou
int findRowId(Condition* condition) { throw 0; }
// Update � aktualizuje ��dky vyhovuj�c� podm�nce, aktualizaci prov�d� funkce �callback�
// callback na vstupu obdr�� data ��dku a vrac� data
void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }

// Polymorfn� datov� objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhran� vyhovuje z�kladn�m typ�m int, double, string; pro typ �field� je rozhran� roz���eno