#include <vector>
#include <memory>
#include <string>
#include "Publication.h"
#include "Author.h"

class Publisher {
private:
    std::vector<std::shared_ptr<Publication>> publications;
    std::vector<std::shared_ptr<Author>> authors;

public:
    void addPublication(const std::shared_ptr<Publication>& publication);
    void addAuthor(const std::shared_ptr<Author>& author);

    std::vector<std::shared_ptr<Publication>> getPublicationsByAuthor(const std::string& authorName) const;

    void displayPublicationCountByPeriod(int year) const;
};