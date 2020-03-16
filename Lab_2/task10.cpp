#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	unsigned int time = 0;
	double per, dep, dep1;

	cout << "Введите начальный вклад: ";
	cin >> dep;
	cout << "Введите Итоговую сумму вклада: ";
	cin >> dep1;
	cout << "Введите процентную ставку: ";
	cin >> per;

	per /= 100;

	while (dep < dep1)
	{
		dep = dep + (dep * per);
		time++;
	}

	cout << "Через " << time << " лет вы получите: " << dep1 << " доллара" << endl;

	system("pause");
	return 0;
}
