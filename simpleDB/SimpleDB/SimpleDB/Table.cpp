#include "dbapi.h"

// Vlo�en� nov�ho ��dku do tabulky (pole Object* (pro jednotliv� hodnoty sloupe�k�))
void Table::insert(Object** row) {}
// Smaz�n� vyrabn�ho ��dku z tabulky
void remove(int rowid);
// Select � vytvo�� iter�tor k proch�zen� tabulky
Iterator* select();
// Commit � p�enese zm�ny z pam�ti do datov�ch soubor�
void commit();
// Uzav�e tabulku (dealokuje pam�ov� prost�edky)
void close();
// Vrac� po�et ��dk� v tabulce
int Table::getRowCount() const {
	
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