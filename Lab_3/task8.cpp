#include <iostream>

using namespace std;

struct fraction
{
    int verx;
    int niz;
};

int main()
{
    setlocale (0, "");
    char ch;
    fraction d1, d2, d3;

    cout <<"Введите две дроби: "; cin >>d1.verx >>ch >>d1.niz >>d2.verx >>ch >>d2.niz;

    d3.verx = d1.verx * d2.niz+d1.niz*d2.verx;
    d3.niz = d1.niz * d2.niz;

    cout <<"Результат a/b + c/d равен: " <<d3.verx <<ch <<d3.niz <<endl;

    system ("pause");
    return 0;
}
