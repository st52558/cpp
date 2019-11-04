#ifndef I_COMPARABLE
#define I_COMPARABLE
#include "IObject.h"

struct IComparable : IObject {
	~IComparable();
	virtual int compareTo(IComparable* obj) const = 0;

};

#endif // !I_COMPARABLE