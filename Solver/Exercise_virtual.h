#pragma once

#include "..//Solver/Generator.h"
#include "..//Solver/Matrix.h"
#include <iostream>
#include <memory>

class Exercise_virtual
{
protected:
    std::unique_ptr<Matrix> matrix;
    std::ostream& out;

    virtual std::string title() const noexcept = 0;
    virtual void Task1() = 0;
    virtual void Task2() = 0;

public:
    explicit Exercise_virtual(
        const int rows,
        const int columns,
        std::unique_ptr<Generator> generator,
        std::ostream& out = std::cout);

    virtual ~Exercise_virtual() = 0 {};

    void Run();
};
