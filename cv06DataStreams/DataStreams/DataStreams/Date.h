#ifndef DATE_H
#define DATE_H
#include <iostream>

struct Date
{
private:
	int _day;
	int _month;
	int _year;
public:
	Date() {}
	Date(int day, int month, int year) : _day(day), _month(month), _year(year) {} 
	int getDay() const { return _day; }
	int getMonth() const { return _month; }
	int getYear() const { return _year; }
	void setYear(int year) { _year = year; }
	void setMonth(int month) { _month = month; }
	void setDay(int day) { _day = day; }
};

std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date.getDay() << ". " << date.getMonth() << ". " << date.getYear();
	return os;
}
std::istream& operator>>(std::istream& is, Date& date) {
	
	int day;
	is >> day;
	while (!is)
	{
		is >> day;
	}
	date.setDay(day);
	int month;
	is >> month;
	while (month == 0)
	{
		is >> month;
	}
	date.setMonth(month);
	int year;
	is >> year;
	while (!is)
	{
		is >> year;
	}
	date.setYear(year);
	return is;
}
#endif // !DATE
