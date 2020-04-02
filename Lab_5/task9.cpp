#include <iostream>
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
      void add_drobi (fraction, fraction);      
};

void fraction::add_drobi (fraction d1, fraction d2)
    {
        verx = (d1.verx*d2.niz+d1.niz*d2.verx);
        niz = (d1.niz*d2.niz);  
    }
    

int main()
{
setlocale (0, "");
fraction d1, d2, d3;  
char ch;  
do
    {
       d1.set_drobi ();
       d2.set_drobi ();
       d3.add_drobi (d1,d2);
       d3.show_drobi();
       cout << "\nЕще раз?(y/n):  "; 
       cin>>ch;
    }        
while (ch != 'n');
system("pause");
return 0;
}
