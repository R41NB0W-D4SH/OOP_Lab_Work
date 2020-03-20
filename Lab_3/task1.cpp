#include <iostream>
using namespace std;

struct phone
{
   int area;
   int exchange;
   int number;
};

int main()
{
    setlocale(0, "");
    phone ph1 = {212, 767, 8900};
    phone ph2;

    cout << "Введите код города, номер станции, и номер абонента.";
    cout << "\n(Не используйте номера начинающиеся с нуля): ";
    cin >> ph2.area >> ph2.exchange >> ph2.number;

    cout << "\nМой номер : " << '(' << ph1.area << ") " << ph1.exchange << '-' << ph1.number;
    cout << "\nВаш номер : " << '(' << ph2.area << ") " << ph2.exchange << '-' << ph2.number << endl;

	system("pause");
    return 0;
}
