#include "Matrix.h"
#pragma once


using namespace std;

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray& source) {
    _arraySize = source.size();
    _arrayPointer = new T[_arraySize];
}
template<typename T>
DynamicArray<T>::DynamicArray() {
    _arrayPointer = new T[0];
    _arraySize = 0;
}
template<typename T>
DynamicArray<T>::DynamicArray(unsigned size) {
    _arrayPointer = new T[size];
    _arraySize = size;
}
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] _arrayPointer;
}

//Operators
template <typename T>
T& DynamicArray<T>::operator[](unsigned index)
{
    return _arrayPointer[index];
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>& source) {
    _arraySize = source.size();
    _arrayPointer = new T[_arraySize];
    return *this;
}

template <typename T>
unsigned DynamicArray<T>::size()
{
    return _arraySize;
}

template <typename T>
void DynamicArray<T>::resize(unsigned newSize, T newValue)
{
    if (newSize == _arraySize) return;
    T* newArray = new T[newSize];
    for (int i = 0;i < newSize && i < _arraySize;++i)
    {
        newArray[i] = _arrayPointer[i];
    }
    for (int i = _arraySize;i < newSize;++i)    //Ensure eventual new elements are empty
    {
        newArray[i] = newValue;  //Wypierdol konstruktor
    }
    delete[] _arrayPointer;
    _arrayPointer = newArray;
    _arraySize = newSize;
    return;
}

// Constructor for Any Matrix; filled with initial value provided.
template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned cols, const T& initialValue) {

    m_matrix.resize(rows);
    for (unsigned i = 0; i < m_matrix.size(); i++) {
        m_matrix[i].resize(cols, initialValue);
    }
    m_rowSize = rows;
    m_colSize = cols;
}

// Copy constructor
//template<typename T>
//Matrix<T>::Matrix(const Matrix<T>& source) {
//    m_matrix = source.m_matrix;
//    m_rowSize = source.getRows();
//    m_colSize = source.getCols();
//}

// Destructor - no dynamic memory allocation                                                                                                                                                    
template<typename T>
Matrix<T>::~Matrix() {}