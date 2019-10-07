#ifndef INHERITENCE_H
#define INHERITENCE_H

#include <string>
using namespace std;

class GeneralType
{
public:
	GeneralType(int aId) :id(aId) {}
	int GetId() const { return id; }
	int& GetId() { return id; }
private:
	int id;
};

class AdvancedType final /*final -> nelze dále dìdit*/ : private GeneralType, public IPrintable
{
public:
	AdvancedType(int aId, string aText) : GeneralType(aId), text(aText)
	{

	}
private:
	string text;	

	// Inherited via IPrintable
	virtual void Print() const override;
};

class IPrintable
{
public:
	virtual void Print() const = 0;
};

void Inheritence()
{
	/*AdvancedType adv01(2, "text");
	IPrintable print01 = dynamic_cast<IPrintable>(adv01);*/

	AdvancedType* adv01 = new AdvancedType(1, "text");
	IPrintable* printable01 = dynamic_cast<IPrintable*>(adv01);
	GeneralType* general01 = dynamic_cast<GeneralType*>(adv01);

	//IPrintable* printable02 = dynamic_cast<IPrintable*>(general01);
	GeneralType* printable02 = dynamic_cast<GeneralType*>(general01);

}

#endif // !INHERITENCE_H
