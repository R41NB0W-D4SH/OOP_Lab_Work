#include <iostream>

using namespace std;

struct date
{
    int day;
    int month;
    int year;
};

int main()
{
    setlocale(0, "");
    int dd, mm, yyyy;
    char ch;

    cout << "Введите день, месяц и год в формате dd/mm/yyyy." << endl;
    cin >> dd >> ch >> mm >> ch >> yyyy;

    date a = {dd, mm, yyyy};
    cout <<a.day <<ch <<a.month <<ch <<a.year <<endl;

    system("pause");
    return 0;
}
