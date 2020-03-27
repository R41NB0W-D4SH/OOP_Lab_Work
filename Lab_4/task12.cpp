#include <iostream>

using namespace std;

struct faction
{
    int verx;
    int niz;
};

faction d1, d2, d;

faction fadd(faction, faction);
faction fsub(faction, faction);
faction fmul(faction, faction);
faction fdiv(faction, faction);

int main()
 {
    setlocale(0, "");
    char chO, ch;
    cout <<"Введите две дроби и знак операции между ними: ";
    cin>>d1.verx >>ch >>d1.niz >>chO >>d2.verx >>ch >>d2.niz;
    switch (chO)
    {
    case '+': fadd(d1, d2);
        break;
    case '-': fsub(d1, d2);
        break;
    case '*': fmul(d1, d2);
        break;
    case '/': fdiv(d1, d2);
        break;
    }
    cout <<"Результат равен: " <<d.verx <<ch <<d.niz <<endl;
    system ("pause");
    return 0;
}

faction fadd(faction, faction)
{
    d.verx=d1.verx*d2.niz+d1.niz*d2.verx;
    d.niz=d1.niz*d2.niz;
    return d;
}

faction fsub(faction, faction)
{
    d.verx=d1.verx*d2.niz-d1.niz*d2.verx;
    d.niz=d1.niz*d2.niz;
    return d;
}

faction fmul(faction, faction)
{
    d.verx=d1.verx*d2.verx;
    d.niz=d1.niz*d2.niz;
    return d;
}

faction fdiv(faction, faction)
{
    d.verx=d1.verx*d2.niz;
    d.niz= d1.niz*d2.verx;
    return d;
}
