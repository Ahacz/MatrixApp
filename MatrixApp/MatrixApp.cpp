#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"

template <typename T>
static void StartCalc(char &);
template <typename T>
static void EditMatrix(Matrix<T> &, Matrix<T>&, Matrix<T>&);
template <typename T>
static void StartMatrixEdition(Matrix<T>&, Matrix<T>&, Matrix<T>&, char &);
template <typename T>
void MatrixAssignment(Matrix<T>&, Matrix<T>&, Matrix<T>&);
template <typename T>
void SwitchPlaces(Matrix<T>&, Matrix<T>&, Matrix<T>&);
template <typename T>
void MatrixOperations(Matrix<T>&, Matrix<T>&, Matrix<T>&, char&);
void MatrixTypeSelection(char&, char&);

int main()
{
	char programControlKey = ' ';
	char matrixTypeChoice;
	do {
		system("CLS");
		cout << "Please specify the type of matrix you want to be working on by pressing a key."<<
			"\nf-float d-double i-int -u unisgned -l long: ";
		cin.get(matrixTypeChoice);
		MatrixTypeSelection(matrixTypeChoice,programControlKey);
	} while (programControlKey != 'q');
}


template <typename T>
static void StartCalc(char & controlKey) {
	unsigned rows, cols;
	T value;
	cout << "Enter the number of rows and columns, along with the value for matrix A, divided by a single space: ";
	cin >> rows >> cols >> value;
	Matrix<T> a = Matrix<T>(rows, cols, value);
	cout << "Enter the number of rows and columns, along with the value for matrix B, divided by a single space: ";
	cin >> rows >> cols >> value;
	Matrix<T> b = Matrix<T>(rows, cols, value);
	Matrix<T> c = Matrix<T>();
	do {
		system("CLS");
		cout << "Matrix A:\n";
		a.print();
		cout << "Matrix B:\n";
		b.print();		
		cout << "Matrix C:\n";
		c.print();
		cout << "r - back to choosing matrix types | q - quit\n"
			<< "1: a=a*b | 2: c=a*b | 3: a=a+b | 4: c=a+b | 5: a=a-b | 6: c=a-b | 7: change matrices\n";
		cin.ignore();
		cin.get(controlKey);
		MatrixOperations(a, b, c, controlKey);
	} while (controlKey != 'r' && controlKey != 'q');
}

template <typename T>
static void EditMatrix(Matrix<T>& a, Matrix<T>& b, Matrix<T>&c){
	char controlKey;
	cout << "a - edit A | b - edit B | c - edit C";
	cin.ignore();
	cin.get(controlKey);
	Matrix<T>* editingTarget = nullptr;	//This raw pointer here does not create new data or delete it - it's simply a handle for a later while loop.
	switch (controlKey) {
	case 'a':
		editingTarget = &a;
		break;
	case 'b':
		editingTarget = &b;
		break;
	case 'c':
		editingTarget = &c;
		break;
	default:
		return;
	}
	unsigned row, col;
	T value;
	do {
		system("CLS");
		editingTarget->print();
		cout << "Indexing starts from 0. Please input row column and value divided by single spaces\n";
		cin >> row >> col >> value;
		(*editingTarget)(row, col) = value;
		cout << "q to exit: ";
		cin.ignore();
		cin.get(controlKey);
	} while (controlKey != 'q');
}

template <typename T>
static void StartMatrixEdition(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, char & controlKey) {
	cout << "1: Copy a matrix | 2: Edit matrix values | 3: Switch matrix places\n";
	cin.ignore();
	cin.get(controlKey);
	switch (controlKey)
	{
	case '1':
		MatrixAssignment(a, b, c);
		break;
	case '2': //Select Matrix to edit.
		EditMatrix(a, b, c);
		break;
	case '3':	//Switch matrix places
		SwitchPlaces(a, b, c);
		break;
	}
}
template <typename T>
void MatrixOperations(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c, char& controlKey)
{
	switch (controlKey) {
	case'1':
		try { a *= b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'2':
		try { c = a * b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'3':
		try { a += b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'4':
		try { c = a + b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'5':
		try { a -= b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'6':
		try { c = a - b; }
		catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
		break;
	case'7':
		StartMatrixEdition(a, b, c, controlKey);
	default:
		break;
	}
}

void MatrixTypeSelection(char& matrixTypeChoice, char& programControlKey)
{
	switch (matrixTypeChoice)//This switch is really messy but right now i just don't know how to make it that much cleaner...
	{
	case 'f': {
		StartCalc<float>(programControlKey);
		break;
	}
	case 'd': {
		StartCalc<double>(programControlKey);
		break;
	}
	case 'i': {
		StartCalc<int>(programControlKey);
		break;
	}
	case 'u': {
		StartCalc<unsigned>(programControlKey);
		break;
	}
	case 'l': {
		StartCalc<long>(programControlKey);
		break;
	}
	default: {
		cout << "No option found for: " << matrixTypeChoice << ". Integer applied as default.\n";
		StartCalc<int>(programControlKey);
		break;
	}
	}
}

template <typename T>
void MatrixAssignment(Matrix<T>& a, Matrix<T>& b, Matrix<T>& c)
{
	char controlKey;
	cout << "1: a=b | 2: a=c | 3: b=a | 4: b=c | 5: c=a | 6: c=b: ";
	cin.ignore();
	cin.get(controlKey);
	switch (controlKey)	//Perform assignment
	{
	case '1':
		a = b;
		break;
	case '2':
		a = c;
		break;
	case '3':
		b = a;
		break;
	case '4':
		b = c;
		break;
	case '5':
		c = a;
		break;
	case '6':
		c = b;
		break;
	default:
		break;
	}
}

template <typename T>
void SwitchPlaces(Matrix<T>&a, Matrix<T>&b, Matrix<T>&c)
{
	char controlKey;
	cout << "1: a<->b | 2: a<->c | 3: b<->c\n";
	cin.ignore();
	cin.get(controlKey);
	Matrix<T> temp = Matrix<T>();
	switch (controlKey)
	{
	case '1':
		temp = a;
		a = b;
		b = temp;
		break;
	case '2':
		temp = a;
		a = c;
		c = temp;
		break;
	case '3':
		temp = b;
		b = c;
		c = temp;
		break;
	default:
		break;
	}
}