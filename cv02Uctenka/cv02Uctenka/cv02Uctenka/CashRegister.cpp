
#include "pch.h"
#include "CashRegister.h"
#include <exception>
#include <iostream>


int CashRegister::idCounter = 1000;

CashRegister::CashRegister() {
	receiptNo = 0;
	receipts = new Receipt[10];
}
CashRegister::~CashRegister() {
	delete[] receipts;
}
Receipt& CashRegister::createReceipt(double sum, double vat) {
	if (receiptNo == 10) {
		throw std::overflow_error("Cash register is full");
	}
	receipts[receiptNo].setReceiptNo(idCounter);
	receipts[receiptNo].setSum(sum);
	receipts[receiptNo].setVat(vat);
	idCounter++;
	receiptNo++;
}
Receipt& CashRegister::giveReceipt(int id) {
	for (int i = 0; i < receiptNo; i++)
	{
		if (id == receipts[i].getReceiptNo()) {
			return receipts[i];
		}
	}
	return receipts[0];
}
double CashRegister::giveSum() const {
	double sum = 0;
	for (int i = 0; i < receiptNo; i++)
	{
		sum += receipts[i].getSum();
	}
	return sum;
}
double CashRegister::giveSumIncludingVat() const {
	double sum = 0;
	for (int i = 0; i < receiptNo; i++)
	{
		sum += receipts[i].getSum() * (1 + receipts[i].getVat());
	}
	return sum;
}