#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(0, "");
    unsigned long n;

    cout << "Введите число: ";
    cin >> n;

    for(int j = 1; j <= 200; j++)
        {
        cout << setw(5) << j * n << "  ";
        if(j % 10 == 0)
            cout << endl;
        }

    system("pause");
    return 0;
}
