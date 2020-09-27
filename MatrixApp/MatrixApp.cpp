#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <vector>

template <typename T>
void StartCalc(char &);

template <typename T>
void EditMatrix(Matrix<T> &);

int main()
{
	char programControlKey = ' ';
	char matrixTypeChoice;
	do {
		system("CLS");
		cout << "Please specify the type of matrix you want to be working on by pressing a key."<<
			"\nf-float d-double i-int -u unisgned -l long: ";
		cin.get(matrixTypeChoice);

		switch (matrixTypeChoice)//This switch is really messy but right now i just don't know how to make it that much cleaner...
		{
			case 'f': {
				StartCalc<float>(programControlKey);
				break;
			}
			case 'd':{
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
	} while (programControlKey != 'q');
}


template <typename T>
void StartCalc(char & controlKey) {
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
		switch(controlKey){
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
			c = a + b;
			try { a *= b; }
			catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
			break;
		case'5':
			try { a -= b; }
			catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
			break;
		case'6':
			try { c = a - b;}
			catch (const std::invalid_argument& e) { cout << e.what() << '\n'; }
			break;
		case'7':
			cout << "1: Copy a matrix | 2: Edit matrix values | 3: Switch matrix places\n";
			cin.ignore();
			cin.get(controlKey);
			switch (controlKey)
			{
			case '1':
				cout << "1: a=b | 2: a=c | 3: b=a | 4: b=c | 5: c=a | 6: c=b: ";
				cin.ignore();
				cin.get(controlKey);
				switch (controlKey)
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
				break;
			case '2':
				cout << "a - edit A | b - edit B | c - edit C";
				cin.ignore();
				cin.get(controlKey);
				switch (controlKey){
				case 'a':
					EditMatrix(a);
					break;
				case 'b':
					EditMatrix(b);
					break;
				case 'c':
					EditMatrix(c);
					break;
				default:
					break;
				}
				break;
			case '3':
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
				break;
			}
			break;
		default:
			break;
		}

	} while (controlKey != 'r' && controlKey != 'q');
}

template <typename T>
void EditMatrix(Matrix<T>& EditedMatrix)
{
	unsigned row, col;
	T value;
	char controlKey;
	do {
		system("CLS");
		EditedMatrix.print();
		cout << "Indexing starts from 0. Please input row column and value divided by single spaces\n";
		cin.ignore();
		cin >> row >> col >> value;
		EditedMatrix(row, col) = value;
		cout << "q to exit: ";
		cin.ignore();
		cin.get(controlKey);
	} while (controlKey != 'q');
}