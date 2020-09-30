#pragma once
#include "Matrix.h"

using std::make_unique;
using std::unique_ptr;
using std::cout;
using std::cin;
using std::endl;

//////////////////   Dynamic Array starts here 
//Constructor without arguments creates an array of size 0.
template<typename T>
DynamicArray<T>::DynamicArray() {
    _arrayPointer = make_unique<T[]>(0);
    _arraySize = 0;
}
//Copy constructor
template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray& source) {
    _arraySize = source.size();
    _arrayPointer = unique_ptr<T[]>(new T[_arraySize]);
    for (unsigned i = 0;i < _arraySize;++i){
        _arrayPointer[i] = source[i];
    }
}
//Creates an array of specified size.
template<typename T>
DynamicArray<T>::DynamicArray(unsigned size) {
    _arrayPointer = std::make_unique<T[]>(0);
    _arraySize = size;
}
//Destructor does need to worry about deleting, thanks RAII!
template<typename T>
DynamicArray<T>::~DynamicArray() {
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
    _arrayPointer = std::move(unique_ptr<T[]>(new T[_arraySize])); //same as using .reset() on the pointer. 
                                                        //The previous array should get deleted. Cannot use a variable expression for make_unique
    for (unsigned i = 0;i < _arraySize;i++) {
        _arrayPointer[i] = source[i];
    }
    return *this;
}
template<typename T>
const DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& source) {
    if (&source == this) { return *this; }
    _arraySize = source.size();
    _arrayPointer = unique_ptr<T[]>(new T[_arraySize]);
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
    unique_ptr<T[]> newArray(new T[newSize]);
    for (unsigned i = 0;i < newSize && i < _arraySize;++i) {  //Make sure not to copy elements outside of range of existing array
        newArray[i] = _arrayPointer[i];
    }
    for (unsigned i = _arraySize;i < newSize;++i) {   //Ensure eventual new elements are empty
        newArray[i] = newValue;
    }
    _arrayPointer = std::move(newArray);   //Unique pointer automatically calls delete[] upon assigning a new object. Ownership of newArray passed to _arrayPointer.
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

// Constructor for Any Matrix; asking for user value.
template<typename T>
Matrix<T>::Matrix(unsigned rows, unsigned cols) {
    T initialValue;
    cout << "Please provide an initial value for the matrix: ";
    cin >> initialValue;
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
    Matrix<T> resultMatrix(m_rowSize, m_colSize, 0);
    for (unsigned i = 0;i < m_rowSize;++i) {
        for (unsigned j = 0;j < m_colSize;++j) {
            resultMatrix(i, j) = (*this)(i, j) + rhs(i, j);
        }
    }
    return resultMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix& rhs) {
    if (m_colSize != rhs.getCols() || m_rowSize != rhs.getCols()) { //Make sure both matrices are same size.
        throw std::invalid_argument("Both matrices must be of the same size for subtraction!");
    }
    Matrix<T> resultMatrix(m_rowSize, m_colSize, 0);
    for (unsigned i = 0;i < m_rowSize;++i) {
        for (unsigned j = 0;j < m_colSize;++j) {
            resultMatrix(i, j) = (*this)(i, j) - rhs(i, j);
        }
    }
    return resultMatrix;
}
template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& rhs) {
    unsigned i, j, k;
    unsigned rhsCols = rhs.getCols(); //Save time on calling rhs.getCols() multiple times.
    if (m_rowSize != rhsCols) { //Check for validity of matrices for multiplication
        throw std::invalid_argument("First matrix must have the same number of rows as the second matrix columns!");
    }
    Matrix<T> resultMatrix(m_rowSize, rhsCols, 0);
    for (i = 0;i < m_rowSize;++i) {
        for (j = 0;j < rhsCols;++j) {
            for (k = 0;k < m_colSize;++k) {
                resultMatrix(i, j) += (*this)(i,k) * rhs(k,j);
            }
        }
    }
    return resultMatrix;
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
Matrix<T>& Matrix<T>::operator*=(const Matrix& rhs) {  //Doing this operation directly on returned matrix would lose the data needed.
    Matrix <T> resultMatrix = (*this) * rhs;    
    (*this) = resultMatrix;
    return *this;
}
template<typename T>
bool const Matrix<T>::operator == (const Matrix& rhs) {
    if (this->m_rowSize != rhs.getRows() || this->m_colSize != rhs.getCols()) {
        return false;
    }
    if (!this->m_colSize || !this->m_rowSize) {  //Check if the matrix has actual rows and columns. If a size is 0 then both matrices must be same since they hold no value.
        return true;
    }
    for (unsigned i = 0;i < this->m_rowSize;++i){     //Check each value. If there is a single difference then stop the loop and return false.
        for(unsigned j = 0 ;j< this->m_colSize;++j)
            if ((*this)(i, j) != rhs(i, j)) {
                return false;
            }
    }
    return true;
}
template<typename T>
bool const Matrix<T>::operator != (const Matrix& rhs) {
    return !((*this) == rhs);
}

// Print method
template<typename T>
void Matrix<T>::print() const {
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