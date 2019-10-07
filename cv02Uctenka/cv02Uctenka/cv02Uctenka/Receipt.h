#ifndef RECEIPT_H
#define RECEIPT_H

struct Receipt
{
private:
	int receiptNo;
	double sum;
	double vat;
public:
	void setReceiptNo(int number);
	void setSum(double number);
	void setVat(double number);
	int getReceiptNo() const;
	double getSum() const;
	double getVat() const;
};
#endif