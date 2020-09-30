#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixApp/Matrix.h"
#include "../MatrixApp/Matrix.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(DynamicArrayTest)
	{
	public:
		
		TEST_METHOD(DAEmptyConstructor)
		{
			unsigned length = 0;
			DynamicArray<int> testingArray;
			Assert::AreEqual(length, testingArray.size());
		}
		TEST_METHOD(DASpecifiedSizeConstructor)
		{
			unsigned length = 5;
			DynamicArray<int> testingArray(5);
			Assert::AreEqual(length, testingArray.size());
		}
		TEST_METHOD(DACopyConstructor)
		{
			DynamicArray<int> sourceArray(5);
			DynamicArray<int> testingArray(sourceArray);
			Assert::AreEqual((unsigned)5, testingArray.size());
		}
		TEST_METHOD(DAOperators)
		{
			DynamicArray<int> testingArray(5);
			testingArray[3] = 10;
			Assert::AreEqual(10, testingArray[3]);
			DynamicArray<int> testingAssignment;
			testingAssignment = testingArray;
			Assert::AreEqual(10, testingAssignment[3]);
		}
		TEST_METHOD(DAMethods)
		{
			DynamicArray<int> testingArray(5);
			testingArray[2] = 9;
			Assert::AreEqual((unsigned)5, testingArray.size()); //Check size value
			Assert::AreEqual(9, testingArray[2]);				//Check value of third index
			testingArray.resize(3);
			Assert::AreEqual((unsigned)3, testingArray.size()); //Check size value
			Assert::AreEqual(9, testingArray[2]);				//Check value of third index
		}
	};
	TEST_CLASS(MatrixTest)
	{
		TEST_METHOD(MatrixConstructors)
		{
			Matrix<int> testingMatrix(2, 3, 5);
			Assert::AreEqual(5, testingMatrix(1, 2));	//Check if the matrix is filled, as well as the () operator
			Matrix<int> testingMatrix2(testingMatrix);  //Copy Constructor
			Assert::AreEqual(true, (testingMatrix==testingMatrix2));	//Check results along with == operator
		}
		TEST_METHOD(MatrixMethods)
		{
			Matrix<int> testingMatrix(2, 3, 5);
			Assert::AreEqual((unsigned)2, testingMatrix.getRows());
			Assert::AreEqual((unsigned)3, testingMatrix.getCols());
		}
		TEST_METHOD(MatrixOperations)
		{
			Matrix<int> matrixA(2, 2, 2),
				matrixB(2, 2, 2),
				matrixC(2,2,2),
				resultMatrix(2, 2, 8);
			matrixC = matrixA * matrixB;
			Assert::AreEqual(true, (resultMatrix==matrixC));
			resultMatrix = Matrix<int>(2, 2, 4);
			matrixC = matrixA + matrixB;
			Assert::AreEqual(true, (resultMatrix == matrixC));
			resultMatrix = Matrix<int>(2, 2, 0);
			matrixC = matrixA - matrixB;
			Assert::AreEqual(true, (resultMatrix == matrixC));
			resultMatrix = Matrix<int>(2, 2, 4);
			matrixA += matrixB;
			Assert::AreEqual(true, (resultMatrix == matrixA));
			matrixA -= matrixB;
			Assert::AreEqual(true, (matrixB == matrixA));
			resultMatrix = Matrix<int>(2, 2, 8);
			matrixA *= matrixB;
			Assert::AreEqual(true, (resultMatrix == matrixA));
		}
	};
}
