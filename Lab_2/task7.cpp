#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    unsigned int time;
    double per, dep;

    cout << "Введите начальный вклад: ";
    cin >> dep;
    cout << "Введите число лет: ";
    cin >> time;
    cout << "Введите процентную ставку: ";
    cin >> per;

    per /= 100;

    for (int i = 0; i < time; i++)
    {
        dep = dep + (dep * per);
    }

    cout << "Через " << time << " лет вы получите: " << dep << " доллара" << endl;

    system("pause");
    return 0;
}
