
#include "pch.h"
#include "cv05Library.h"
#include <iostream>

void MyLibrary::sayHello() const {
	std::cout << "HELLO FROM LIBRARY!" << std::endl;
}

void MyLibrary::sayBye() const {
	std::cout << "BYE FROM LIBRARY!" << std::endl;
}
