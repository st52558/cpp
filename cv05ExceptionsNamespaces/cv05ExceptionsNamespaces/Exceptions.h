#ifndef EXCEPTIPION_H
#define EXCEPTIPION_H

#include <string>

struct Exceptions {

};

struct ElementNotFound : public Exceptions {
private:
	std::string _message;
public:
	ElementNotFound(std::string message) : _message(message) {}
	std::string GetMessage() const;
};

struct InvalidArgument : public Exceptions {
private:
	std::string _message;
public:
	InvalidArgument(std::string message) : _message(message) {}
	std::string GetMessage() const;
};

#endif // !EXCEPTIPION_H