#include <string>
#include <vector>
#include <memory>

class Author;

class Publication {
protected:
    std::string title;
    int year;
    std::vector<std::shared_ptr<Author>> coAuthors;

public:
    Publication(const std::string& title, int year);
    virtual ~Publication() = default;

    std::string getTitle() const;
    int getYear() const;
    void addCoAuthor(const std::shared_ptr<Author>& author);

    const std::vector<std::shared_ptr<Author>>& getCoAuthors() const;

    virtual void displayInfo() const;
};