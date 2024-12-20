#include "Generator.h"
#include <sstream>
#include "Matrix.h"

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(rows, std::vector<int>(cols)) {}

Matrix::Matrix(int rows, int cols, Generator& generator) : rows(rows), cols(cols), data(rows, std::vector<int>(cols))
{
    if (rows < 0 || cols < 0) {
        throw std::logic_error("The matrix is not correct");
    }
    fill(generator);
}

void Matrix::fill(const Generator& generator)
{
    for (size_t i = 0; i < rows; ++i)
    {
        for (size_t j = 0; j < cols; ++j)
        {
            data[i][j] = generator.generate();
        }
    }
}

Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols), data(other.data) {}


Matrix::Matrix(Matrix&& other) noexcept : rows(other.rows), cols(other.cols), data(std::move(other.data))
{
    other.rows = 0;
    other.cols = 0;
}


Matrix& Matrix::operator=(const Matrix& other)
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = other.data;
    }
    return *this;
}


Matrix& Matrix::operator=(Matrix&& other) noexcept
{
    if (this != &other)
    {
        rows = other.rows;
        cols = other.cols;
        data = std::move(other.data);
        other.rows = 0;
        other.cols = 0;
    }
    return *this;
}


std::vector<int>& Matrix::operator[](int index)
{
    return data[index];
}

const std::vector<int>& Matrix::operator[](int index) const
{
    return data[index];
}

int Matrix::getRows() const
{
    return rows;
}


int Matrix::getCols() const
{
    return cols;
}

void Matrix::deleteColumn(int col_index) {
    if (col_index < 0 || col_index >= getCols()) return;

    for (size_t i = 0; i < getRows(); ++i) {
        data[i].erase(data[i].begin() + col_index);
    }
    --cols;
}

std::string Matrix::toString() const
{
    std::ostringstream oss;
    for (const auto& row : data)
    {
        for (const auto& elem : row)
        {
            oss << elem << " ";
        }
        oss << std::endl;
    }
    return oss.str();
}
std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
    for (size_t i = 0; i < matrix.rows; ++i)
    {
        for (size_t j = 0; j < matrix.cols; ++j)
        {
            os << matrix.data[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
