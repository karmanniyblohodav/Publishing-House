#include "Guide.h"
#include <iostream>

Guide::Guide(const std::string& title, int year) : Publication(title, year) {}

void Guide::displayInfo() const {
	std::cout << "Book - Title: " << title << ", Year: " << year << std::endl;
}