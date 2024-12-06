#include "Author.h"
#include "Publication.h"
#include <iostream>

Author::Author(const std::string& name) : name(name) {}

std::string Author::getName() const {
    return name;
}

void Author::addPublication(const std::shared_ptr<Publication>& publication) {
    publications.push_back(publication);
}

void Author::displayPublications() const {
    std::cout << "Publications by " << name << ":" << std::endl;
    for (const auto& publication : publications) {
        publication->displayInfo();
    }
}
