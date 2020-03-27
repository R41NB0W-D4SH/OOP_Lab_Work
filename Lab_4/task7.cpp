#include <iostream>

using namespace std;

int n, otv=1;
static int p;
char ch;
long lo, otv_lo=1;
float fl, dur=1;

void power(char, int);
int power(int, int);
long power(long, int);
float power(float, int);

int main()
{
    setlocale(0, "");
    power(fl=3.6, 7);
    cout <<"Число 6.2 в степени 3 равно: " <<power(fl, p) <<endl;
    power(6, 3);
    cout <<"Число 2 в степени 4 равно: " <<power(n, p) <<endl;
    cout <<"17 символов *: "; power('x', 17);
    power(lo=6969, 2);
    cout <<"Число 6969 в степени 2 равно: " <<power(lo, p) <<endl;
    system("pause");
    return 0;
}
void power(char ch, int p)
{
    for (int j=1; j<=p; j++)
        cout <<ch;
    cout <<endl;
}
int power(int chislo, int stepen)
{
    for (int j=1; j<=stepen; j++)
        otv*=chislo;
    return otv;
}
long power(long chislo, int stepen)
{
    for (int j=1; j<=stepen; j++)
        otv_lo*=chislo;
    return otv_lo;
}
float power(float flo, int pe)
{
    for (int j=1; j<=pe; j++)
        dur*=flo;
    return dur;
}
