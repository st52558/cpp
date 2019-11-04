#include "Time.h"
#include <string>

Time::~Time() {
}

Time::Time(int hours, int minutes, int seconds) {
	_hours = hours;
	_minutes = minutes;
	_seconds = seconds;

}
int Time::compareTo(IComparable* obj)const {
	Time* time = (Time*)obj;
	double time1 = this->_hours + this->_minutes / 60 + this->_seconds / 3600;
	double time2 = time->_hours + time->_minutes / 60 + time->_seconds / 3600;

	if (time1 > time2) {
		return 1;
	}
	else if (time1 < time2) {
		return -1;
	}
	else return 0;
}
string Time::toString() const {
	return to_string(_hours) + ":" + to_string(_minutes) + ":" + to_string(_seconds);



}

