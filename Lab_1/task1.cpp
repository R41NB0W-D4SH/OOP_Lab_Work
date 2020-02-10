#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	float gallons, cufeet;

	cout << "Введите чилсо Галлонов : ";
	cin >> gallons;

	cufeet = gallons / 7.481;

	cout << "Эквивалентный объем в кубических футах : " << cufeet << endl;

	system("pause");
	return 0;
}
