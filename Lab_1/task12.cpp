#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	float df, all, f, raz1, raz2, s, p;

	cout << "Введите фунты стерлингов в современном формате: ";
	cin >> df;

    all = df * 240;
	df = static_cast<int>(df);
    f = df * 240;
    raz1 = all - f;
    raz1 = static_cast<int>(raz1);
    s = raz1 / 12;
    s = static_cast<int>(s);
    raz2 = s * 12;
    p = raz1 - raz2;

    cout << df << "." << s << "." << p << endl;

	system("pause");
	return 0;
}
