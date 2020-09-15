#include <iostream>
#include "Matrix.h"
#include "Matrix.cpp"
#include <vector>

int main()
{
    Matrix<int> nowa(4, 3, 2);
    Matrix<int> nowa2(5,2,1);
    unsigned tmp = nowa2(2,1);
    std::cout << "Testujemy matryce "<<tmp<<" \n";
    nowa.print();
    nowa2.print();
    nowa2 = nowa;
    nowa2(3, 2) = 18;
    nowa2.print();
    std::cout << nowa2(1, 1);
    std::cin >> tmp;
}
