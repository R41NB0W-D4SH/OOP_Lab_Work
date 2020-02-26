#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    setlocale(0, "");
    char ch;
    unsigned long total = 0;

    cout << "Введите число: ";

    while( (ch=getche()) != '\r' )
        total = total*10 + ch-'0';
    cout << "\nЧисло: " << total << endl;

    system("pause");
    return 0;
}
