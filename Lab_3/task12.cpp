#include <iostream>

using namespace std;

struct faction
{
    int verx;
    int niz;
};

int main()
{
    setlocale(0, "");
    faction d1, d2, d;
    char chO, ch;
    cout <<"Введите две дроби и знак операции между ними: ";
    cin>>d1.verx >>ch >>d1.niz >>chO >>d2.verx >>ch >>d2.niz;
    switch (chO)
    {
    case '+': d.verx = d1.verx * d2.niz + d1.niz * d2.verx;
        d.niz = d1.niz * d2.niz;
        break;
    case '-': d.verx = d1.verx * d2.niz - d1.niz * d2.verx;
        d.niz = d1.niz * d2.niz;
        break;
    case '*': d.verx = d1.verx * d2.verx; d.niz = d1.niz * d2.niz;
        break;
    case '/': d.verx = d1.verx * d2.niz; d.niz = d1.niz * d2.verx;
        break;
    }
    cout <<"Результат равен: " <<d.verx <<ch <<d.niz <<endl;

    system ("pause");
    return 0;
}
