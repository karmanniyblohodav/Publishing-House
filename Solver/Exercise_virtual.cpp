#include "Exercise_virtual.h"
#include <iostream>

Exercise_virtual::Exercise_virtual(const int rows, const int columns, std::unique_ptr<Generator> generator, std::ostream& out)
    : out(out) {
    matrix = std::make_unique<Matrix>(rows, columns, *generator);
}

void Exercise_virtual::Run()
{
    out << "=== " << title() << " ===" << std::endl;

    out << "Исходная матрица:" << std::endl;
    out << *matrix << '\n';

    out << "Результат выполнения Task 1:" << std::endl;
    Task1();

    out << "Результат выполнения Task 2:" << std::endl;
    Task2();
}
