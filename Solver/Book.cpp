#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, int year) : Publication(title, year) {}

void Book::displayInfo() const {
    std::cout << "Book - Title: " << title << ", Year: " << year << std::endl;
}
