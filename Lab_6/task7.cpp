#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

class money
{
private:
    long double cash;
    char in[80];
    char out[80];
public:
    money(){cash=0.0;}
    money(long double d):cash(d){}
    void input()
    {
        cout <<"Введите сумму: "; cin >>in;
    }
    void outg()
    {
        cout <<setiosflags(ios::fixed) <<setprecision(2) <<mstold(in) <<endl;
    }
    long double mstold(char mass[])
    {
        int n=0;
        for(int j=0; j<strlen(mass); j++)
        {
            if((mass[j]=='$')||(mass[j]==','))
                continue;
            out[n++]=mass[j];
        }
        double cash=atof(out);//возвращение дабл хоть както
        return cash;
    }
};

int main()
{
    setlocale(0,"");
    int n=0;
    char ch;
    money m[100];
    do{
        m[n++].input();
        cout <<"Еще раз (y/n)?";
        cin >>ch;
    }while(ch != 'n');
    for(int j=0; j<n; j++)
        m[j].outg();
    system("pause");
}
