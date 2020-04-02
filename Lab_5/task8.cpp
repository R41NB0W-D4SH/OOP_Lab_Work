#include <iostream>
using namespace std;

class podscet
{
   private:
      int nomer;
      static int vsego;
   public:
      podscet()
        {vsego++; nomer = vsego;}
      int getpodscet ()
        {return  vsego;}
      void show_podscet()const
        {
            cout << "Мой порядковый номер: " <<nomer<<endl;
            cout << "Всего объектов: " <<vsego<<endl;
        }
};

int podscet::vsego = 0;

int main()
{
setlocale (0 "");
podscet p1, p2, p3;
p1.show_podscet();
p2.show_podscet();
p3.show_podscet();
system("pause");
return 0;
}
