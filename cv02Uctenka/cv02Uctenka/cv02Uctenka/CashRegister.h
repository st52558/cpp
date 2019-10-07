#ifndef CASHREGISTER_H
#define CASHREGISTER_H
#include "Receipt.h"

struct CashRegister
{
private:
	Receipt* receipts;
	int receiptNo;
	static int idCounter;
public:
	CashRegister();
	~CashRegister();
	Receipt& createReceipt(double sum, double vat);
	Receipt& giveReceipt(int id);
	double giveSum() const;
	double giveSumIncludingVat() const;
};
#endif