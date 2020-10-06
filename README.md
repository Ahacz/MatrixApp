# MatrixApp
An exercise in C++ programming

This program dynamically creates matrices through usage of a smaller class called Dynamic Array. 

Dynamic array class uses smart pointers to mitigate the risk of memory leaks. 

DynamicArray has its own constructors and overloaded operator of accessing the element ( [] ), assignment (=). Two methods of dynamic array are size()- which returns the size of an array, as well as resize(), which changes its size. 

Matrix itself has overloaded operators for addition (+, +=), subtraction (-, -=), multiplication(*, *=), assignment (=), comparison(==,!=), and access for a specified element ( () ). 
Its methods include printing, getting rows and getting columns. ( print(), getRows(), getCols() ).


Technologies used for this program: Smart pointers, operator overloading, class templates.
