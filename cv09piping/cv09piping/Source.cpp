#include <sstream>
#include <iostream>
#include <fstream>
#include "PipeTypes.h"

int main(int agrc, char** argv)
{
	std::ifstream in{};
	in.open("././input.txt");
	std::string line;
	std::string token;
	getline(in, line);
	std::stringstream ss(line);
	int dimension;
	getline(ss, token, '\n');
	dimension = stoi(token);
	char** charArray = new char*[dimension];
	for (int i = 0; i < dimension; i++)
	{
		charArray[i] = new char[dimension];
	}
	//char* charArray = new char [dimension*dimension];
	
	for (int i = 0; i < dimension; i++)
	{
		getline(in, line);
		std::stringstream ss(line);
		getline(ss, token, '\n');
		for (int j = 0; j < dimension; j++)
		{
			charArray[i][j] = token.at(j);
		}
	}

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			std::cout << charArray[i][j];
		}
		std::cout << std::endl;
	}

	IPiping* piping = new Piping(dimension, charArray);
	if (piping->IsPipingOk()) {
		std::cout << "zapojeno spravne";
	}
	else {
		std::cout << "zapojeno spatne";
	}
	
}