#ifndef GENERIC_H
#define GENERIC_H

#include <iostream>



struct Point
{
	int X;
	int Y;
	Point(int x, int y) : X(x), Y(y) {}
};

template <typename T>
void Print(T aValue)
{
	std::cout << aValue << std::endl;
}



void Generic()
{
	Print(2);
	Print("text");
	Print(Point(1, 1));
}

#endif // !GENERIC_H
