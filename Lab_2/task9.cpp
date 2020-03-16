#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");

	int stul, gost, var = 1;

	cout << "Введите количество мест : ";
	cin >> stul;
	cout << "Введите количество гостей : ";
	cin >> gost;

	for (int i = 0; i < stul; i++)
	{
		var = var * gost;
		gost--;
	}

	cout << "Число возможных рассадок : " << var << endl;

	system("pause");
	return 0;
}
