#include "..//Solver/Matrix.h"
#include "..//Solver/Generator.h"
#include "..//Solver/IStreamGenerator.h"
#include "..//Solver/RandomGenerator.h"
#include "..//Solver/Exercise_virtual.h"
#include "..//Solver/Exercise.h"
#include <iostream>
#include <locale>

int main()
{
    setlocale(LC_ALL, "RU");
    std::unique_ptr<Generator> randomGenerator = std::make_unique<RandomGenerator>(1, 100);

    Exercise exercise(3, 3, std::move(randomGenerator));

    exercise.Run();

    return 0;
}