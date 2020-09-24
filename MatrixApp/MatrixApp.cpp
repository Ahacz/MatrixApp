#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <vector>

int main()
{
    Matrix<int> nowa(3, 3, 2);
    Matrix<int> nowa2(3,4,1);
    Matrix<int> tmp = nowa + nowa2;
    nowa.print();
    nowa2.print();
    tmp.print();
}
