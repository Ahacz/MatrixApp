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
			Assert::AreEqual(5, testingMatrix2(1, 2));
		}
		TEST_METHOD(MatrixMethods)
		{
			Matrix<int> testingMatrix(2, 3, 5);
			Assert::AreEqual((unsigned)2, testingMatrix.getRows());
			Assert::AreEqual((unsigned)3, testingMatrix.getCols());
		}
	};
}
