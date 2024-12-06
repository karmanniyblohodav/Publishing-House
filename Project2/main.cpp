#include <iostream>
#include <vector>
#include <memory>
#include "..\Solver\Author.h"
#include "..\Solver\Publisher.h"
#include "..\Solver\Book.h"
#include "..\Solver\Journal.h"
#include "..\Solver\Guide.h"

int main() {
    Publisher publisher;

    auto author1 = std::make_shared<Author>("Иван Иванов");
    auto author2 = std::make_shared<Author>("Мария Петрова");

    publisher.addAuthor(author1);
    publisher.addAuthor(author2);

    auto book = std::make_shared<Book>("Книга по C++", 2023);
    book->addCoAuthors(author1);
    author1->addPublication(book);
    publisher.addPublication(book);

    auto journal = std::make_shared<Journal>("Научный журнал", 2022);
    journal->addCoAuthors(author2);
    author2->addPublication(journal);
    publisher.addPublication(journal);

    auto guide = std::make_shared<Guide>("Методическое руководство", 2021);
    guide->addCoAuthors(author1);
    author1->addPublication(guide);
    publisher.addPublication(guide);

    std::cout << "\nПубликации автора Иван Иванов:\n";
    author1->displayPublications();

    std::cout << "\nПубликации автора Мария Петрова:\n";
    author2->displayPublications();

    // Демонстрация - вывод публикаций по году
    std::cout << "\nКоличество публикаций за 2023 год:\n";
    publisher.displayPublicationCountByPeriod(2023);

    // Итерация по коллекции публикаций
    std::cout << "\nСписок всех публикаций в издательстве:\n";
    for (const auto& publication : publisher.getPublicationsByAuthor("Иван Иванов")) {
        publication->displayInfo();
    }

    return 0;
}
