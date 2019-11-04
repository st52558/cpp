#ifndef I_OBJECT
#define I_OBJECT
#include "iostream"

using namespace std;

struct IObject {
	virtual ~IObject();
	virtual string toString() const = 0;

};

#endif // !I_OBJECT