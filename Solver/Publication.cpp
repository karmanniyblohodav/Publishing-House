#include "Publication.h"
#include <iostream>

Publication::Publication(const std::string& title, int year) : title(title), year(year) {}

std::string Publication::getTitle() const {
    return title;
}

int Publication::getYear() const {
    return year;
}

void Publication::addCoAuthor(const std::shared_ptr<Author>& author) {
    coAuthors.push_back(author);
}

const std::vector<std::shared_ptr<Author>>& Publication::getCoAuthors() const {
    return coAuthors;
}

void Publication::displayInfo() const {
    std::cout << "Title: " << title << ", Year: " << year << std::endl;
}
