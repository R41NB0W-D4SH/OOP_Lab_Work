#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    setlocale(0, "");

    char a;
    cin >> a;

    cout << islower(a) << endl;

    system("pause");
    return 0;
}

