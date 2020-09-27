#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <vector>

IMatrix* getTypedMatrixPointer(unsigned, unsigned, char);

int main()
{
	char programControlKey = ' ';
	char matrixTypeChoice;
	unsigned rowsA, colsA,rowsB,colsB;
	IMatrix *a,*b,*c;
	do {
		system("CLS");
		cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
		cin >> rowsA >> colsA;
		cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
		cin >> rowsB >> colsB;
		cout << "Please specify the type of matrix you want to be working on by pressing a key."<<
			"\nf-float d-double i-int -u unisgned -l long: ";
		cin.ignore();
		matrixTypeChoice = cin.get();
		a = getTypedMatrixPointer(rowsA, colsA, matrixTypeChoice);
		b = getTypedMatrixPointer(rowsB, colsB, matrixTypeChoice);
		c = getTypedMatrixPointer(0, 0, matrixTypeChoice);
		
		do{
			system("CLS");
			cout << "Matrix A:\n";
			a->print();
			cout << "Matrix B:\n";
			b->print();
			cout << "Matrix C:\n";
			c->print();
			cout << "r - go back to creating new matrices | q - quit the program\n"
				<<"1:C=A+B | 2:A+=B | 3:C=A-B | 4:A-=B | 5:C=A*B | 6:A*=B"
				<<"\n 7:Switch matrices";
			cin.ignore();
			programControlKey = cin.get();
			switch (programControlKey){
				case '1':
					//(*c) = (*a) + (*b);
					break;
				case '2':
					break;
				case '3':
					break;
				case '4':
					break;
				case '5':
					break;
				case '6':
					break;
				case '7':
					break;
				default:
					break;
			}
		} while (programControlKey != 'r'&&programControlKey!='q');
		delete a, b, c;
	} while (programControlKey != 'q');
}
IMatrix* getTypedMatrixPointer(unsigned rows, unsigned cols, char type)
{
	switch (type)//This switch is really messy but right now i just don't know how to make it that much cleaner...
	{
	case 'f': {
		if (rows == 0) return new Matrix<float>();
		return new Matrix<float>(rows, cols);
		break;
	}
	case 'd': {
		if (rows == 0) return new Matrix<double>();
		return new Matrix<double>(rows, cols);
		break;
	}
	case 'i': {
		if (rows == 0) return new Matrix<int>();
		return new Matrix<int>(rows, cols);
		break;
	}
	case 'u': {
		if (rows == 0) return new Matrix<unsigned>();
		return new Matrix<unsigned>(rows, cols);
		break;
	}
	case 'l': {
		if (rows == 0) return new Matrix<long>();
		return new Matrix<long>(rows, cols);
		break;
	}
	default: {
		if (rows == 0) return new Matrix<int>();
		cout << "No option found for: " << type << ". Integer applied as default.\n";
		return new Matrix<int>(rows, cols);
		break;
	}
	}
 }