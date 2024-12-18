#pragma once

#include "Exercise.h"

std::string Exercise::title() const noexcept {
    return "My Matrix Tasks";
}

void Exercise::Task1() {
    for (size_t i = 0; i < matrix->getRows(); ++i) {
        for (size_t j = 0; j < matrix->getCols(); ++j) {
            if ((*matrix)[i][j] < 0) {
                (*matrix)[i][j] = 0;
            }
        }
    }
    out << *matrix << std::endl;
}

void Exercise::Task2() {
    size_t rows = matrix->getRows();
    size_t cols = matrix->getCols();

    std::vector<int> columns_to_delete;

    for (int j = 0; j < cols; ++j) {
        bool has_multiply_five = false;
        for (int i = 0; i < rows; ++i) {
            if ((*matrix)[i][j] % 5 == 0) {
                has_multiply_five = true;
                break;
            }
        }
        if (has_multiply_five) {
            columns_to_delete.push_back(j);
        }
    }
    out << "Количество столбцов для удаления: " << columns_to_delete.size() << "\n";
    for (int k = columns_to_delete.size() - 1; k >= 0; --k) {
        matrix->deleteColumn(columns_to_delete[k]);
    }

    out << "Матрица после удаления столбцов:\n";
    out << *matrix;
}

