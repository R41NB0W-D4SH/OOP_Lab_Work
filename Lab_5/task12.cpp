#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void starline();

class fraction
{
   private:
      int verx, niz;
   public:
      fraction(): verx(0), niz(0)
        {}
      fraction(int c, int z): verx(c), niz(z)
        {}
     void set_drobi ()
        {
            char drob;
            cout<< "Введите значение дроби в формате x/y: "<<endl;
            cin>>verx>>drob>>niz;
        }
      void show_drobi()const
        {
            cout<< "Результат "<< verx<<"/"<<niz<<endl;
        }
      void add_drobi(fraction, fraction);
      void sub_drobi(fraction, fraction);
      void mul_drobi(fraction, fraction);
      void div_drobi(fraction, fraction);
      void lowterms ();
      void set_znam ();
      void show_drobiVtablice()const;
      void show_drobiShapka()const;
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

void fraction::show_drobiVtablice()const
    {
        cout<<setiosflags(ios::left)<<setw(1)<<verx<<setw(1)<<"/"<<setw(3)<<niz;
    }

        void fraction::set_znam ()
        {
            char drob;
            fraction temp, temp2, rezult;
            cout<< "Введите знаменатель: "<<endl;
            cin>> temp.niz;
            cout<< "     ";
            for (int x = 1; x<temp.niz; x++)
            {
                temp.verx = x;
                temp.show_drobiVtablice();
                temp2.niz=temp.niz;
            }
            cout<< endl;
            starline();
            for (int x = 1; x<temp.niz; x++)
            {
                temp.verx = x;
                temp.show_drobiVtablice();
                temp2.niz=temp.niz;
                for (int x2 = 1; x2<temp2.niz; x2++)
                {
                    temp2.verx = x2;
                    rezult.mul_drobi (temp, temp2);
                    rezult.lowterms();
                    rezult.show_drobiVtablice();
                }
                cout<< endl;
            }
        }

int main()
{
setlocale (0, "");
fraction d1;
d1.set_znam ();
system("pause");
return 0;
}

void starline()
{
    for(int j=0; j<30; j++)
    cout<<'*';
    cout<<endl;
}
