#include "dbapi.h"

// Vloení nového øádku do tabulky (pole Object* (pro jednotlivé hodnoty sloupeèkù))
void Table::insert(Object** row) {}
// Smazání vyrabného øádku z tabulky
void remove(int rowid);
// Select – vytvoøí iterátor k procházení tabulky
Iterator* select();
// Commit – pøenese zmìny z pamìti do datovıch souborù
void commit();
// Uzavøe tabulku (dealokuje pamìové prostøedky)
void close();
// Vrací poèet øádkù v tabulce
int Table::getRowCount() const {
	
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
// callback na vstupu obdrí data øádku a vrací data
void update(Condition* condition, std::function<void(Object**)> callback) { throw 0; }

// Polymorfní datovı objekt (reprezentuje jednu datovou hodnotu v tabulce)
// Rozhraní vyhovuje základním typùm int, double, string; pro typ „field“ je rozhraní rozšíøeno