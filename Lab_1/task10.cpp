#include <iostream>

using namespace std;

int main()
{
    setlocale (0, "");
    int f1, s, p1;
    double f2;
    cout << "Введите фунты : ";
    cin >> f1;
    cout << "Введите шиллинги : ";
    cin >> s;
    cout << "Введите пенсы : ";
    cin >> p1;

    f2 = f1 * 240 + s * 12 + p1;

    cout << "Старый формат фунтов стерлингов: " << f1 <<"." << s << "." << p1 << endl;
    cout << "Новый формат фунтов стерлингов: " << f2 / 240 << endl;

	system("pause");
	return 0;
}
