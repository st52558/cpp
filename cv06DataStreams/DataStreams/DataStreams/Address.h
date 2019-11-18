#ifndef ADDRESS_H
#define ADDRESS_H
#include <iostream>

struct Address
{
private:
	std::string _street;
	std::string _city;
	int _zipCode;
public:
	Address() {}
	Address(std::string street, std::string city, int zipCode) : _street(street), _city(city), _zipCode(zipCode) {}
	std::string getStreet() const { return _street; }
	std::string getCity() const { return _city; }
	int getZipCode() const { return _zipCode; }
	void setStreet(std::string street) { _street = street; }
	void setCity(std::string city) { _city = city; }
	void setZipCode(int zipCode) { _zipCode = zipCode; }
};

std::ostream& operator<<(std::ostream& os, const Address& address) {
	os << ", " << address.getStreet() << ", " << address.getCity() << ", " << address.getZipCode();
	return os;
}
std::istream& operator>>(std::istream& is, Address& address) {
	char character;
	is >> character;

	std::string street;
	is >> street;
	address.setStreet(street.substr(0, street.length()-1));

	std::string city;
	is >> city;
	address.setCity(city.substr(0, city.length() - 1));

	int zipCode;
	is >> zipCode;
	address.setZipCode(zipCode);

	return is;
}
#endif // !ADDRESS
