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

    auto author1 = std::make_shared<Author>("���� ������");
    auto author2 = std::make_shared<Author>("����� �������");

    publisher.addAuthor(author1);
    publisher.addAuthor(author2);

    auto book = std::make_shared<Book>("����� �� C++", 2023);
    book->addCoAuthors(author1);
    author1->addPublication(book);
    publisher.addPublication(book);

    auto journal = std::make_shared<Journal>("������� ������", 2022);
    journal->addCoAuthors(author2);
    author2->addPublication(journal);
    publisher.addPublication(journal);

    auto guide = std::make_shared<Guide>("������������ �����������", 2021);
    guide->addCoAuthors(author1);
    author1->addPublication(guide);
    publisher.addPublication(guide);

    std::cout << "\n���������� ������ ���� ������:\n";
    author1->displayPublications();

    std::cout << "\n���������� ������ ����� �������:\n";
    author2->displayPublications();

    // ������������ - ����� ���������� �� ����
    std::cout << "\n���������� ���������� �� 2023 ���:\n";
    publisher.displayPublicationCountByPeriod(2023);

    // �������� �� ��������� ����������
    std::cout << "\n������ ���� ���������� � ������������:\n";
    for (const auto& publication : publisher.getPublicationsByAuthor("���� ������")) {
        publication->displayInfo();
    }

    return 0;
}
