#ifndef EXCEPTION_EXAMPLE_H
#define EXCEPTION_EXAMPLE_H

#include <iostream>
#include <exception>

void ExceptionExample() 
{
	std::cout << "Zadejte dìlenec: ";
	int delenec;
	std::cin >> delenec;

	std::cout << "Zadejte dìlitele: ";
	int delitel;
	std::cin >> delitel;

	double result = (double)delenec / delitel;	
	std::cout << "Výsledek je: " << result << std::endl;
}

void ExceptionExample2()
{
	int values[5];
	int count = sizeof(values) / sizeof(values[0]);
	try
	{
		for (size_t i = 0; i <= count; i++)
		{
			values[i] = i;
		}
	}
	catch (std::exception ex)
	{
		std::cout << ex.what() << std::endl;
	}
	
}

#endif //EXCEPTION_EXAMPLE_H