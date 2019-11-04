#ifndef TIME
#define TIME

#include "IComparable.h"

struct Time :IComparable {
private:
	int _hours, _minutes, _seconds;
public:
	~Time();
	Time(int hours, int minutes, int seconds);

	virtual int compareTo(IComparable* obj) const;
	virtual string toString() const override;
};

#endif // !TIME