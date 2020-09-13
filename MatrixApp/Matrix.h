#ifndef __MatrixApp_Matrix
#define __MatrixApp_Matrix

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

template <typename T> class DynamicArray {
private:
	T* _arrayPointer;
	unsigned _arraySize;
public:
	//Constructors and destructor
	DynamicArray();
	DynamicArray(unsigned);
	~DynamicArray();
	DynamicArray(DynamicArray&);

	//Operators
	T& operator[] (unsigned);
	DynamicArray<T>& operator=(DynamicArray<T>&);

	//Size and resize methods
	unsigned size();
	void resize(unsigned, T newValue=0);
};
template <typename T> class Matrix {
private:
	unsigned m_rowSize;
	unsigned m_colSize;
	DynamicArray<DynamicArray<T> > m_matrix;
public:
	Matrix(unsigned, unsigned, const T&);
	//Matrix(const char*);
	//Matrix(const Matrix&);
	~Matrix();

	// //Matrix Operations
	//Matrix operator+(const Matrix&);
	//Matrix operator-(const Matrix&);
	//Matrix operator*(const Matrix&);
	//Matrix& operator+=(const Matrix&);
	//Matrix& operator-=(const Matrix&);
	//Matrix& operator*=(const Matrix&);
	//Matrix transpose();


	//// Scalar Operations
	//Matrix operator+(const T&);
	//Matrix operator-(const T&);
	//Matrix operator*(const T&);
	//Matrix operator/(const T&);

	//// Aesthetic Methods
	//T& operator()(const unsigned&, const unsigned&);
	//void print() const;
	//unsigned getRows() const;
	//unsigned getCols() const;
};
#endif /* defined(__MatrixApp_Matrix) */