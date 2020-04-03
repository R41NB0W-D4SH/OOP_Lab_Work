#include <iostream>
using namespace std;
static char ch;

class fraction
{
private:
    int chsl, znam;
public:
    fraction(){chsl=0, znam=0;}
    void getin()
    {cout <<"Введите числитель и знаменатель дроби: "; cin >>chsl >>ch >>znam;}
    void smm(fraction mass, fraction mas)
    {
        chsl=mass.chsl*mas.znam+mass.znam*mas.chsl;
        znam=mass.znam*mas.znam;
    }
    void dev(fraction smm, int sch)
    {
        fraction devi;
        devi.chsl=sch;
        devi.znam=1;
        chsl=smm.chsl*devi.znam;
        znam=smm.znam*devi.chsl;
    }
    void show()
        {cout <<"Среднее значение дроби: " <<chsl <<ch <<znam <<endl;}
};

int main()
{
    setlocale(0,"");
    const int max=100;
    int n=0;
    char piu='a';
    fraction fr[max], summ;;
    do{
        fr[n++].getin();
        cout <<"Еще раз (y/n)?";
        cin >>piu;
    }while(piu!='n');
    for(int j=0; j<n; j++)
    {if(j>0)summ.smm(fr[j], fr[j-1]);}
    summ.dev(summ, n);
    summ.show();
    system("pause");
}
