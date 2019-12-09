#define PIPETYPES_H
#ifdef PIPETYPES_H

#include "AbstractStructs.h"

struct EastWest : APipeElement
{
	EastWest(int x, int y);
	~EastWest() { }
	bool IsCorrectlyInvolved(const IPiping* potrubi) const;
	int _x;
	int _y;
};

struct NorthSouth : APipeElement
{
	NorthSouth(int x, int y);
	~NorthSouth() { }
	bool IsCorrectlyInvolved(const IPiping* potrubi) const;
	int _x;
	int _y;
};

struct AllSides : APipeElement
{
	AllSides(int x, int y);
	~AllSides() { }
	bool IsCorrectlyInvolved(const IPiping* potrubi) const;
	int _x;
	int _y;
};

struct NoDirection : APipeElement
{
	NoDirection(int x, int y);
	~NoDirection() { }
	bool IsCorrectlyInvolved(const IPiping* potrubi) const;
	int _x;
	int _y;
};

struct EastWestSouth : APipeElement
{
	EastWestSouth(int x, int y);
	~EastWestSouth() { }
	bool IsCorrectlyInvolved(const IPiping* potrubi) const;
	int _x;
	int _y;
};

struct Piping : IPiping
{
private: 
	APipeElement** elements;
	int dimension;
public:
	Piping(int dim, char** charArray);
	~Piping();
	const APipeElement* GiveElement(int x, int y) const;
	bool IsPipingOk() const;
};

#endif // PIPETYPES_H