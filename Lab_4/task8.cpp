#include <iostream>

using namespace std;

void swap(int&, int&);

int main()
{
    setlocale(0, "");
    int a, b;
    cout <<"Введите первое число: "; cin >>a;
    cout <<"Введите второе число: "; cin >>b;
    swap(a, b);
    cout <<"После обмена значений. Первое число: " <<a <<" второе: " <<b <<endl;
    system("pause");
    return 0;
}
void swap(int& first, int& second)
{
    int temp = first;
    first = second;
    second = temp;
}
