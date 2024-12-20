#include "CppUnitTest.h"
#include "../Solver/Matrix.h"
#include "../Solver/RandomGenerator.h"
#include "../Solver/IStreamGenerator.h"
#include "../Solver/Exercise.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(MatrixTests)
	{
	public:
		TEST_METHOD(Test_Matrix_Initialization)
		{
			Matrix matrix(3, 3);
			Assert::AreEqual(3, matrix.getRows());
			Assert::AreEqual(3, matrix.getCols());
		}

		TEST_METHOD(Test_Matrix_Fill)
		{
			RandomGenerator generator(1, 10);
			Matrix matrix(3, 3, generator);

			for (int i = 0; i < matrix.getRows(); ++i)
			{
				for (int j = 0; j < matrix.getCols(); ++j)
				{
					Assert::IsTrue(matrix[i][j] >= 1 && matrix[i][j] <= 10);
				}
			}
		}

		TEST_METHOD(Test_Delete_Column)
		{
			Matrix matrix(3, 3);
			matrix[0] = { 1, 2, 3 };
			matrix[1] = { 4, 5, 6 };
			matrix[2] = { 7, 8, 9 };

			matrix.deleteColumn(1);
			Assert::AreEqual(2, matrix.getCols());
			Assert::AreEqual(3, matrix[0][1]);
			Assert::AreEqual(6, matrix[1][1]);
			Assert::AreEqual(9, matrix[2][1]);
		}
	};

	TEST_CLASS(ExerciseTests)
	{
	public:
		TEST_METHOD(Test_Task1)
		{
			std::ostringstream output;
			auto generator = std::make_unique<RandomGenerator>(1, 10);
			Exercise exercise(3, 3, std::move(generator), output);

			Matrix matrix(3, 3);
			matrix[0] = { -1, 2, -3 };
			matrix[1] = { 4, -5, 6 };
			matrix[2] = { -7, 8, -9 };

			exercise.Task1();

			Assert::AreEqual(0, matrix[0][0]);
			Assert::AreEqual(2, matrix[0][1]);
			Assert::AreEqual(0, matrix[0][2]);
			Assert::AreEqual(0, matrix[1][1]);
		}

		TEST_METHOD(Test_Task2)
		{
			std::ostringstream output;
			auto generator = std::make_unique<RandomGenerator>(1, 10);
			Exercise exercise(3, 3, std::move(generator), output);

			Matrix matrix(3, 3);
			matrix[0] = { 5, 1, 2 };
			matrix[1] = { 10, 3, 4 };
			matrix[2] = { 15, 6, 7 };

			exercise.Task2();

			Assert::AreEqual(1, matrix.getCols()); // Ожидается, что останется только 1 столбец
			Assert::AreEqual(1, matrix[0][0]);     // Проверяем, что остались правильные элементы
			Assert::AreEqual(3, matrix[1][0]);
			Assert::AreEqual(6, matrix[2][0]);
		}
	};
}
