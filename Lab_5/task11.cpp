#include <iostream>
#include<cmath>
using namespace std;

class fraction
{
   private:
      int verx, niz;
   public:
      fraction(): verx(0), niz(0)
        {}
     void set_drobi ()
        {
            char drob;
            cout<< "Введите значение дроби в формате x/y: "<<endl;
            cin>>verx>>drob>>niz;
        }
      void show_drobi()const
        {
            cout<< "Результат  "<< verx<<"/"<<niz<<endl;
        }
      void add_drobi(fraction, fraction);
      void sub_drobi(fraction, fraction);
      void mul_drobi(fraction, fraction);
      void div_drobi(fraction, fraction);
      void lowterms ();
};

void fraction::add_drobi (fraction d1, fraction d2)
    {
        verx = (d1.verx*d2.niz+d1.niz*d2.verx);
        niz = (d1.niz*d2.niz);
    }

void fraction::sub_drobi (fraction d1, fraction d2)
    {
        verx = (d1.verx*d2.niz-d1.niz*d2.verx);
        niz = (d1.niz*d2.niz);
    }

void fraction::mul_drobi (fraction d1, fraction d2)
    {
        verx = (d1.verx*d2.verx);
        niz = (d1.niz*d2.niz);
    }

    void fraction::div_drobi (fraction d1, fraction d2)
    {
        verx = (d1.verx*d2.niz);
        niz = (d1.niz*d2.verx);
    }

    void fraction::lowterms ()
    {
        long tchis, tznam, temp, gcd;
        tchis = labs(verx);
        tznam = labs(niz);
        if (tznam == 0)
            { cout<<"Недопустимый знаменатель!"; exit(1);}
        else if (tchis == 0)
            { verx = 0; niz = 1; return;}
        while(tchis !=0)
            {
                if(tchis < tznam)
                    {temp = tchis; tchis = tznam; tznam = temp;}
                tchis = tchis - tznam;
            }
        gcd = tznam;
        verx = verx/gcd;
        niz = niz/gcd;
    }

int main()
{
setlocale (0, "");
fraction d1, d2, d3;
char ch;
do
    {
       char operacia;
       d1.set_drobi ();
       cout<< "Введите операцию: *,/,+,-."<<endl;
       cin>>operacia;
       d2.set_drobi ();
       switch(operacia)
       {
            case '/': d3.div_drobi (d1,d2); d3.lowterms(); d3.show_drobi(); break;
            case '*': d3.mul_drobi (d1,d2); d3.lowterms(); d3.show_drobi(); break;
            case '+': d3.add_drobi (d1,d2); d3.lowterms(); d3.show_drobi(); break;
            case '-': d3.sub_drobi (d1,d2); d3.lowterms(); d3.show_drobi(); break;
        }
       cout << "\n Еще раз?(y/n):  ";
       cin>>ch;
    }
while (ch != 'n');
system("pause");
return 0;
}
