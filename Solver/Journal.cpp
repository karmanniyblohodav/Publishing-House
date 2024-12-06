#include "Journal.h"
#include <iostream>

Journal::Journal(const std::string& title, int year) : Publication(title, year) {}

void Journal::displayInfo() const {
	std::cout << "Book - Title: " << title << ", Year: " << year << std::endl;
}