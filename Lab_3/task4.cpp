#include <iostream>

using namespace std;

struct employee
{
   int number;
   float posobie;
};

int main()
{
    setlocale(0, "");
    employee d1, d2, d3;

    cout << "Введите номер первого сотрудника : ";  cin >> d1.number;
    cout << "Введите пособие первого сотрудника : ";  cin >> d1.posobie;
    cout << "Введите номер второго сотрудника : ";  cin >> d2.number;
    cout << "Введите пособие второго сотрудника : ";  cin >> d2.posobie;
    cout << "Введите номер третьего сотрудника : ";  cin >> d3.number;
    cout << "Введите пособие третьего сотрудника : ";  cin >> d3.posobie;

    cout << "У " << d1.number << "-го сотрудника пособие = " << d1.posobie << endl;
    cout << "У " << d2.number << "-го сотрудника пособие = " << d2.posobie << endl;
    cout << "У " << d3.number << "-го сотрудника пособие = " << d3.posobie << endl;


    system("pause");
    return 0;
}
