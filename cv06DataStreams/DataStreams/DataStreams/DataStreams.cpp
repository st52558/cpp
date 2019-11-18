#include "Date.h"
#include "Address.h"
#include "Person.h"
#include <fstream>

int main(int agrc, char** argv)
{
	std::ofstream outputFile{ "././output.txt" };
	outputFile << "Prvni retezec 1234567890 123" << std::endl;
	Person person1 = Person();
	"Petr Cerveny, 1. 2. 2011, Zelena, Praha, 10000" >> person1;
	Person person2 = Person();
	std::string cin = "Pavel Zluty, 3. 4. 2055, Cerna, Brno, 20000";
	cin >> person2;
}