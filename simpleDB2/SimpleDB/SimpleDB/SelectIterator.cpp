#include "dbapi.h"

SelectIterator::SelectIterator(int rowCountI, Object*** rowsI) {
	rowCount = rowCountI;
	rows = rowsI;
	currentRow = 0;
}
// Posun na další øádek (vrací true, pokud je iterátor platnı; logika podle Java Iterator)
bool SelectIterator::moveNext() {
	currentRow++;
	if (currentRow == rowCount) {
		return false;
	}
	return true;
}
// Vrací pole Object* obsahující data øádku
Object** SelectIterator::getRow() {
	return rows[currentRow];
}
// Vrací interní rowId aktuálního øádku
int SelectIterator::getRowId() {
	return currentRow;
}
// Uzavøe iterátor (dealokuje pamìové prostøedky)
void SelectIterator::close() {

}