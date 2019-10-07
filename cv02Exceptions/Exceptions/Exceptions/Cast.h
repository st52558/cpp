#ifndef CAST_H
#define CAST_H

#include <iostream>
class PrivateType
{
public:
	PrivateType(int aValue) : value(aValue) {}
private:
	int value;
};

class PublicType
{
public:
	PublicType(int aValue) : Value(aValue) {}
	int Value;
};

void CastExample()
{
	int* i = new int(3);
	void* pI = (void*)i;

	PrivateType* obj01 = new PrivateType(1);
	void* pObj01 = static_cast<void*>(obj01);
	PrivateType* obj02 = static_cast<PrivateType*>(obj01);

	delete obj01; //delete obj01 i obj02
	//delete obj02; pøístup k už deletnuté pamìti

	PublicType* obj03 = reinterpret_cast<PublicType*>(obj01);
	std::cout << obj03->Value << std::endl;

}


#endif // !CAST_H
