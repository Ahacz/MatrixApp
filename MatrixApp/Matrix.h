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

using std::vector;
using std::tuple;
template <typename T> class Matrix {
private:
	unsigned m_rowSize;
	unsigned m_colSize;
	vector<vector<T> > m_matrix;
public:
	Matrix(unsigned, unsigned, T);
	Matrix(const char*);
	Matrix(const Matrix&);
	~Matrix();

	// Matrix Operations
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix transpose();


	// Scalar Operations
	Matrix operator+(const T&);
	Matrix operator-(const T&);
	Matrix operator*(const T&);
	Matrix operator/(const T&);

	// Aesthetic Methods
	double& operator()(const unsigned&, const unsigned&);
	void print() const;
	unsigned getRows() const;
	unsigned getCols() const;
};

#include "Matrix.cpp"
#endif /* defined(__MatrixApp_Matrix) */