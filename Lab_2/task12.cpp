#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	double  a, b, c, d, itog;
	char ans, sign;

	cout << "Для продолжения работы введите на клавиатуре символ (Y)" << endl;
	cout << "Для отказа работы введите на клавиатуре символ (N)" << endl;
	cout << "Пример написания: (первое число) (оператор) (второе число)" << endl;

	do
	{
		cout << "Введите первую дробь : ";
		cin >> a >> b;
		cin >> sign;
		cout << "Введите вторую дробь : ";
		cin >> c >> d;
		
		switch (sign)
		{
			case '+': itog = (a * d + b * c) / (b * d);
				break;
			case '-': itog = (a * d - b * c) / (b * d);
				break;
			case '*': itog = (a * c) / (b * d);
				break;
			case '/': itog = (a * d) / (b * c);
				break;
			default: itog = 0;
		}

		cout << "Итог : " << itog << endl;

		cout << "Продолжить? - (Y/N)" << endl;
		cin >> ans;
	}
	while (ans == 'y' || ans == 'Y');

	system("pause");
	return 0;
}
