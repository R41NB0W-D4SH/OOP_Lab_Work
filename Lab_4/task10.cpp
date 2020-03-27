#include <iostream>

using namespace std;

void func(int n)
{
    static int t;
    cout <<"Функция вызывалась ранее " <<t <<" раз." <<endl;
    t++;
}

int main()
{
    setlocale(0, "");
    int n;
    start:
    cout <<"Введите количество вызовов функции > 10: ";
    cin >>n;
    if (n < 10) goto start;
    else
    for(int j = 0; j < n; j++) func(n);
    system("pause");
    return 0;
}
