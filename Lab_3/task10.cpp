#include <iostream>

using namespace std;

struct sterling
{
    int f;
    int sh;
    int p;
};

int main()
{
    setlocale(0, "");
    double dec;
    cout <<"Введите десятичные фунты: "; cin >>dec;

    sterling st1;
    st1.f = dec;
    st1.sh = (dec-st1.f) * 20;
    st1.p = (((dec-st1.f) * 20)-st1.sh) * 12;

    cout <<"Старый вид: " <<st1.f <<"." <<st1.sh <<"." <<st1.p <<endl;

    system ("pause");
    return 0;
}
