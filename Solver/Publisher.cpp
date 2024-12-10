#include "Publisher.h"
#include <iostream>

void Publisher::addPublication(const std::shared_ptr<Publication>& publication) {
    publications.push_back(publication);
}

void Publisher::addAuthor(const std::shared_ptr<Author>& author) {
    authors.push_back(author);
}

std::vector<std::shared_ptr<Publication>> Publisher::getPublicationsByAuthor(const std::string& authorName) const {
    std::vector<std::shared_ptr<Publication>> result;
    for (const auto& publication : publications) {
        for (const auto& coAuthor : publication->getCoAuthors()) {
            if (coAuthor->getName() == authorName) {
                result.push_back(publication);
                break;
            }
        }
    }
    return result;
}

void Publisher::displayPublicationCountByPeriod(int year) const {
    int count = 0;
    for (const auto& publication : publications) {
        if (publication->getYear() == year) {
            count++;
        }
    }
    std::cout << "Publications in " << year << ": " << count << std::endl;
}
