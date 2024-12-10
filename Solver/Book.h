#include "Publication.h"

class Book : public Publication {
public:
    Book(const std::string& title, int year);
    void displayInfo() const override;
};