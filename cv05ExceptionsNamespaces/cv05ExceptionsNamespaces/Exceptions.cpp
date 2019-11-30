#include "Exceptions.h"

#include <string>

std::string InvalidArgument::GetMessage() const {
	return _message;
}

std::string ElementNotFound::GetMessage() const {
	return _message;
}