#pragma once

#include <iostream>
#include <memory>

template <typename T> class DynamicArray 
{
private:
	std::unique_ptr<T[]> _arrayPointer;
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
	Matrix();
	Matrix(unsigned, unsigned, const T& initialValue);
	Matrix(unsigned, unsigned);
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
	bool const operator == (const Matrix&);
	bool const operator != (const Matrix&);


	// Aesthetic Methods
	T& operator()(const unsigned&, const unsigned&);
	const T& operator()(const unsigned&, const unsigned&) const;
	void print() const;
	unsigned getRows() const;
	unsigned getCols() const;
};
