
#include "pch.h"
#include <iostream>
#include "CashRegister.h"

int main()
{
	CashRegister* cr = new CashRegister();
	cr->createReceipt(1.2, 0.21);
	cr->createReceipt(3.5, 0.2);
	cr->createReceipt(15.8, 0.115);
	cr->createReceipt(1.2, 0.21);
	cr->createReceipt(3.5, 0.2);
	cr->createReceipt(15.8, 0.115);
	cr->createReceipt(1.2, 0.21);
	cr->createReceipt(3.5, 0.2);
	cr->createReceipt(15.8, 0.115);
	//cr->createReceipt(1.2, 0.21);
	//cr->createReceipt(3.5, 0.2);
	/*std::cout << cr->giveReceipt(1001).getSum() << std::endl;
	std::cout << cr->giveSumIncludingVat() << std::endl;
	std::cout << cr->giveSum() << std::endl;*/
}