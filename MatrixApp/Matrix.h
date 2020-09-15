#pragma once

#include <iostream>

template <typename T> class DynamicArray 
{
private:
	T* _arrayPointer;
	unsigned _arraySize;
public:
	//Constructors and destructor
	DynamicArray();
	DynamicArray(unsigned);
	DynamicArray(DynamicArray&);
	~DynamicArray();

	//Operators
	T& operator[] (unsigned);
	const T& operator[] (unsigned) const;
	DynamicArray<T>& operator=(DynamicArray<T>&);
	const DynamicArray<T>& operator=(const DynamicArray<T>&);

	//Size and resize methods
	unsigned size() const;
	void resize(unsigned, T newValue=0);
};
template <typename T> class Matrix 
{
private:
	unsigned m_rowSize;
	unsigned m_colSize;
	DynamicArray<DynamicArray<T> > m_matrix;
public:
	Matrix(unsigned, unsigned, const T&);
	Matrix(const Matrix&);
	~Matrix();


	 //Matrix Operations
	Matrix& operator=(const Matrix&);
	Matrix operator+(const Matrix&);
	Matrix operator-(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix& operator+=(const Matrix&);
	Matrix& operator-=(const Matrix&);
	Matrix& operator*=(const Matrix&);
	Matrix transpose();


	// Aesthetic Methods
	T& operator()(const unsigned&, const unsigned&);
	const T& operator()(const unsigned&, const unsigned&) const;
	void print();			//Jak jest const to wywala b³¹d...
	unsigned getRows() const;
	unsigned getCols() const;
};
