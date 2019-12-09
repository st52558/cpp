#include "PipeTypes.h"
#include <iostream>

Piping::Piping(int dim, char** charArray) {
	dimension = dim;
	elements = new APipeElement*[dim*dim];

	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			switch (charArray[i][j])
			{
			case '-':
				elements[i * dimension + j] = new EastWest(i,j);
				break;
			case 'I':
				elements[i * dimension + j] = new NorthSouth(i,j);
				break;
			case '+':
				elements[i * dimension + j] = new AllSides(i,j);
				break;
			case 'O':
				elements[i * dimension + j] = new NoDirection(i,j);
				break;
			case 'T':
				elements[i * dimension + j] = new EastWestSouth(i,j);
				break;
			case ' ':
				elements[i * dimension + j] = nullptr;
				break;
			default:
				elements[i * dimension + j] = nullptr;
				break;
			}
		}
	}
}

const APipeElement* Piping::GiveElement(int x, int y) const {
	if (x < 0 || y < 0 || y > dimension || x > dimension) {
		return nullptr;	
	}
	else {
		std::cout << x * dimension + y << std::endl;
		return elements[x * dimension + y];
	}
}

bool Piping::IsPipingOk() const {
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (GiveElement(i, j)==nullptr || !GiveElement(i, j)->IsCorrectlyInvolved(this)) {
				return false;
			}
		}
	}
	return true;
}