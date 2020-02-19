#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    double c;

    cout << "Введите градусы по Цельсию : ";
    cin >> c;

    cout << c << " C = " << c * 9 / 5 + 32 << " F" << endl;

    system("pause");
    return 0;
}
