
#include "pch.h"
#include "Receipt.h"

void Receipt::setReceiptNo(int number) {
	receiptNo = number;
}
void Receipt::setSum(double number) {
	sum = number;
}
void Receipt::setVat(double number) {
	vat = number;
}
int Receipt::getReceiptNo() const {
	return receiptNo;
}
double Receipt::getSum() const {
	return sum;
}
double Receipt::getVat() const {
	return vat;
}