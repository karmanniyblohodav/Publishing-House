#pragma once

#include "Exercise_virtual.h"

class Exercise : public Exercise_virtual {
public:
    Exercise(const int rows, const int cols, std::unique_ptr<Generator> generator, std::ostream& out = std::cout)
        : Exercise_virtual(rows, cols, std::move(generator), out) {}

protected:
    std::string title() const noexcept override;
    void Task1() override;
    void Task2() override;
};