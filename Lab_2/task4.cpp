#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    double n1, n2, ans;
    char oper, ch;

    do
    {
        cout << "Введите первое число, потом оператор, затем второй число: ";
        cin >> n1 >> oper >> n2;

        switch(oper)
        {
            case '+':  ans = n1 + n2;  break;
            case '-':  ans = n1 - n2;  break;
            case '*':  ans = n1 * n2;  break;
            case '/':  ans = n1 / n2;  break;
            default:   ans = 0;
        }
        cout << "Ответ = " << ans;
        cout << "\nПроводить операции еще? \nВведите 'y' для - Да\nВведите 'n' для - Нет\n";
        cin >> ch;
    }

    while( ch != 'n' );

    system("pause");
    return 0;
}
