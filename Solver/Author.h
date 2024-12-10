#include <string>
#include <vector>
#include <memory>

class Publication;

class Author {
private:
    std::string name;
    std::vector<std::shared_ptr<Publication>> publications;

public:
    Author(const std::string& name);

    std::string getName() const;
    void addPublication(const std::shared_ptr<Publication>& publication);
    void displayPublications() const;
};