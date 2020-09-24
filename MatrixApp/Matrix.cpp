#pragma once
#include "Matrix.h"

using namespace std;

//////////////////   Dynamic Array starts here 
//Constructor without arguments creates an array of size 0.
template<typename T>
DynamicArray<T>::DynamicArray() {
    _arrayPointer = new T[0];
    _arraySize = 0;
}
//Copy constructor
template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray& source) {
    _arraySize = source.size();
    _arrayPointer = new T[_arraySize];
}
//Creates an array of specified size.
template<typename T>
DynamicArray<T>::DynamicArray(unsigned size) {
    _arrayPointer = new T[size];
    _arraySize = size;
}
//Destructor
template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] _arrayPointer;
}

//Operators of DA
template <typename T>
T& DynamicArray<T>::operator[](unsigned index) {
    return _arrayPointer[index];
}
template <typename T>
const T& DynamicArray<T>::operator[](unsigned index) const{
    return _arrayPointer[index];
}
template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray<T>& source) {
    if (&source == this) { return *this; }
    _arraySize = source.size();
    delete[] _arrayPointer;
    _arrayPointer = new T[_arraySize];
    for (unsigned i = 0;i < _arraySize;i++) {
        _arrayPointer[i] = source[i];
    }
    return *this;
}
template<typename T>
const DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& source) {
    if (&source == this) { return *this; }
    _arraySize = source.size();
    delete[] _arrayPointer;
    _arrayPointer = new T[_arraySize];
    for (unsigned i = 0;i < _arraySize;i++) {
        _arrayPointer[i] = source[i];
    }
    return *this;
}

//Gets number of array elements
template <typename T>
unsigned DynamicArray<T>::size() const{
    return _arraySize;
}

//Resizes the array. If size decreases, data outside of new size is lost.
template <typename T>
void DynamicArray<T>::resize(unsigned newSize, T newValue) {
    if (newSize == _arraySize) return;
    T* newArray = new T[newSize];
    for (unsigned i = 0;i < newSize && i < _arraySize;++i) {  //Make sure not to copy elements outside of range of existing array
        newArray[i] = _arrayPointer[i];
    }
    for (unsigned i = _arraySize;i < newSize;++i) {   //Ensure eventual new elements are empty
        newArray[i] = newValue;
    }
    delete[] _arrayPointer; //Clear the old array and replace it with the new one.
    _arrayPointer = newArray;
    _arraySize = newSize;
    return;
}

//////////////////   Matrix starts here

//Empty constructor. Size 0 across both dimensions.
template<typename T>
Matrix<T>::Matrix() {
    m_rowSize = 0;
    m_colSize = 0;
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

//Copy constructor
template<typename T>
Matrix<T>::Matrix(const Matrix<T>& source) {
    m_matrix = source.m_matrix;
    m_rowSize = source.getRows();
    m_colSize = source.getCols();
}

// Virtual Destructor - no dynamic memory allocation needed. Done by DynamicArray                                                                                                                                                   
template<typename T>
Matrix<T>::~Matrix() {}

// Operators
template<typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& rhs) {
    if (&rhs == this){
        return *this;
    }
    m_rowSize = rhs.getRows();
    m_colSize = rhs.getCols();
    m_matrix = rhs.m_matrix;
    return *this;
}
template<typename T>
T& Matrix<T>::operator()(const unsigned& rowNo, const unsigned& colNo){
    return this->m_matrix[rowNo][colNo];
}
template<typename T>
const T& Matrix<T>::operator()(const unsigned& rowNo, const unsigned& colNo) const{
    return this->m_matrix[rowNo][colNo];
}
template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& rhs) {
    if(m_colSize!=rhs.getCols()||m_rowSize!=rhs.getCols()){ //Make sure both matrices are same size.
        throw std::invalid_argument("Both matrices must be of the same size for addition!");
    }
    Matrix<T> resultingMatrix(m_rowSize, m_colSize, 0);
    for (unsigned i = 0;i < m_rowSize;++i) {
        for (unsigned j = 0;j < m_colSize;++j) {
            resultingMatrix(i, j) = (*this)(i, j) + rhs(i, j);
        }
    }
    return resultingMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& rhs) {
    if (m_colSize != rhs.getCols() || m_rowSize != rhs.getCols()) { //Make sure both matrices are same size.
        throw std::invalid_argument("Both matrices must be of the same size for subtraction!");
    }
    Matrix<T> resultingMatrix(m_rowSize, m_colSize, 0);
    for (unsigned i = 0;i < m_rowSize;++i) {
        for (unsigned j = 0;j < m_colSize;++j) {
            resultingMatrix(i, j) = (*this)(i, j) - rhs(i, j);
        }
    }
    return resultingMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& rhs) {

}
template<typename T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& rhs) {
    if (m_colSize != rhs.getCols() || m_rowSize != rhs.getCols()) { //Make sure both matrices are same size.
        throw std::invalid_argument("Both matrices must be of the same size for addition!");
    }
    for (unsigned i = 0;i < m_rowSize;++i) {
        for (unsigned j = 0;j < m_colSize;++j) {
            (*this)(i, j) += rhs(i, j);
        }
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& rhs) {
    unsigned rows = this->getRows();
    unsigned cols = this->getCols();
    if (cols != rhs.getCols() || rows != rhs.getCols()) { //Make sure both matrices are same size.
        throw std::invalid_argument("Both matrices must be of the same size for subtraction!");
    }
    for (unsigned i = 0;i < rows;++i) {
        for (unsigned j = 0;j < cols;++j) {
            (*this)(i, j) -= rhs(i, j);
        }
    }
    return *this;
}
template<typename T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& rhs) {

}


//Transpose method
template<typename T>
Matrix<T> Matrix<T>::transpose() {
}

// Print method
template<typename T>
void Matrix<T>::print() {
    cout << "Matrix: " << endl;
    for (unsigned i = 0; i < m_rowSize; i++) {
        for (unsigned j = 0; j < m_colSize; j++) {
            cout << "[" << m_matrix[i][j] << "] ";
        }
        cout << endl;
    }
}

//getRows and getCols methods
template<typename T>
unsigned Matrix<T>::getRows() const {
    return this->m_rowSize;
}
template<typename T>
unsigned Matrix<T>::getCols() const {
    return this->m_colSize;
}