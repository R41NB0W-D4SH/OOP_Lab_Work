#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int fun1, sh1, pen1, fun2, sh2, pen2, fun, sh, pen, sum1, sum2, raz1, raz2;
    char ans;

    cout << "Для продолжения работы введите на клавиатуре символ (Y)" << endl;
    cout << "Для отказа работы введите на клавиатуре символ (N)" << endl;

    do
    {
        cout << "Введите первую сумму : ";
        cin >> fun1 >> sh1 >> pen1;
        cout << "Введите вторую сумму : ";
        cin >> fun2 >> sh2 >> pen2;

        sum1 = fun1 * 240 + sh1 * 12 + pen1;
        sum2 = fun2 * 240 + sh2 * 12 + pen2;
        sum1 = sum1 + sum2;
        fun = sum1 / 240;
        fun = static_cast<int>(fun);
        fun1 = fun;
        fun = fun * 240;
        raz1 = sum1 - fun;
        sh = raz1 / 12;
        sh = static_cast<int>(sh);
        raz2 = sh * 12;
        pen = raz1 - raz2;

        cout << "Всего: " << fun1 << "." << sh << "." << pen << endl;

        cout << "Продолжить? - (Y/N)" << endl;
        cin >> ans;
    }
    while (ans == 'y' || ans == 'Y');

    system("pause");
    return 0;
}
