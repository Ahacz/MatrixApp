#include <iostream>
#include "Matrix.cpp"

int main()
{
    Matrix<int> nowa(4, 3, 2);
    Matrix<int> nowa2(5,2,1);
    unsigned tmp = nowa2(2,1);
    cout << "Testujemy matryce "<<tmp<<" \n";
    nowa.print();
    nowa2.print();
    nowa2 = nowa;
    //cout << nowa2.getRows() << endl;
    nowa2.print();
    cin >> tmp;
}
