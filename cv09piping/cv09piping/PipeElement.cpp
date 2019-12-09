#include "PipeTypes.h"
#include <iostream>

EastWest::EastWest(int x, int y) {
	_x = x;
	_y = y;
}

NorthSouth::NorthSouth(int x, int y) {
	_x = x;
	_y = y;
}

AllSides::AllSides(int x, int y) {
	_x = x;
	_y = y;
}

NoDirection::NoDirection(int x, int y) {
	_x = x;
	_y = y;
}

EastWestSouth::EastWestSouth(int x, int y) {
	_x = x;
	_y = y;
}

bool EastWest::IsCorrectlyInvolved(const IPiping* potrubi) const {
	return potrubi->GiveElement(_x - 1, _y) != nullptr && potrubi->GiveElement(_x + 1, _y) != nullptr;
}

bool NorthSouth::IsCorrectlyInvolved(const IPiping* potrubi) const {
	return potrubi->GiveElement(_x, _y - 1) != nullptr && potrubi->GiveElement(_x, _y + 1) != nullptr;
}

bool AllSides::IsCorrectlyInvolved(const IPiping* potrubi) const {
	return potrubi->GiveElement(_x, _y - 1) != nullptr && potrubi->GiveElement(_x, _y + 1) != nullptr && potrubi->GiveElement(_x + 1, _y) != nullptr && potrubi->GiveElement(_x - 1, _y) != nullptr;
}

bool NoDirection::IsCorrectlyInvolved(const IPiping* potrubi) const {
	return true;
}

bool EastWestSouth::IsCorrectlyInvolved(const IPiping* potrubi) const {
	return potrubi->GiveElement(_x, _y + 1) != nullptr && potrubi->GiveElement(_x + 1, _y) != nullptr && potrubi->GiveElement(_x - 1, _y) != nullptr;
}
