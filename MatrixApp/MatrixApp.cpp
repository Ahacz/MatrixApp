#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <vector>

int main()
{
	char programControlKey = ' ';
	char matrixTypeChoice;
	unsigned rows, cols;
	IMatrix *a,*b,*c;
	do {
		system("CLS");
		cout << "Please specify the type of matrix you want to be working on by pressing a key."<<
			"\nf-float d-double i-int -u unisgned -l long: ";
		cin.get(matrixTypeChoice);

		switch (matrixTypeChoice)//This switch is really messy but right now i just don't know how to make it that much cleaner...
		{
		case 'f':
			float value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (float): ";
			cin >> value;
			a = new Matrix<float>(rows,cols,value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (float): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<float>();
			break;
		case 'd':
			double value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (double): ";
			cin >> value;
			a = new Matrix<float>(rows, cols, value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (double): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<double>();
			break;
		case 'i':
			int value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (int): ";
			cin >> value;
			a = new Matrix<float>(rows, cols, value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (int): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<int>();
			break;
		case 'u':
			unsigned value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (unsigned): ";
			cin >> value;
			a = new Matrix<float>(rows, cols, value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (unsigned): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<unsigned>();
			break;
		case 'l':
			long value;
			int value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (long): ";
			cin >> value;
			a = new Matrix<float>(rows, cols, value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (long): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<int>();
			break;
			c = new Matrix<long>();
			break;
		default:
			cout << "No option found for: " << matrixTypeChoice << ". Integer applied as default.\n";
			int value;
			int value;
			cout << "Enter the number of rows and columns for matrix A, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix A (int): ";
			cin >> value;
			a = new Matrix<float>(rows, cols, value);
			float value;
			cout << "Enter the number of rows and columns for matrix B, divided by a single space: ";
			cin >> rows >> cols;
			cout << "Enter the initial value to fill matrix B (int): ";
			cin >> value;
			b = new Matrix<float>(rows, cols, value);
			c = new Matrix<int>();
			break;
			c = new Matrix<int>();
		}
		do{

		} while (programControlKey != 'r');
		delete a, b, c;
	} while (programControlKey != 'q');
}
