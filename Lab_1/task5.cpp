#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");

	char a;
	cout << "Введите символ(букву) : ";
	cin >> a;

	if (islower(a)) cout << "1" << endl;
	else cout << "0" << endl;

	system("pause");
	return 0;
}
