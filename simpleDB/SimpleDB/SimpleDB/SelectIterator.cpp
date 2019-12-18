#include "dbapi.h"

SelectIterator::SelectIterator(int rowCountI, Object*** rowsI) {
	rowCount = rowCountI;
	rows = rowsI;
	currentRow = 0;
}
// Posun na dal�� ��dek (vrac� true, pokud je iter�tor platn�; logika podle Java Iterator)
bool SelectIterator::moveNext() {
	currentRow++;
	if (currentRow == rowCount) {
		return false;
	}
	return true;
}
// Vrac� pole Object* obsahuj�c� data ��dku
Object** SelectIterator::getRow() {
	return rows[currentRow];
}
// Vrac� intern� rowId aktu�ln�ho ��dku
int SelectIterator::getRowId() {
	return currentRow;
}
// Uzav�e iter�tor (dealokuje pam�ov� prost�edky)
void SelectIterator::close() {

}