#include <iostream>
using namespace std;

class angle
{
   private:
      int grad;
      float min;
      char direct;
   public:
      angle(): grad(0), min(0.0)
      {}
      angle(int g, float m, char d): grad(g), min(m), direct(d)
      {}
      void get_angle ()
      {
      cout<<"Введите координаты."<<endl;
      cout<<"Градусы: ";
      cin>>grad;
      cout<<"Минуты: ";
      cin>>min;
      cout<<"Направление (N, S, E, W): ";
      cin>>direct;
      }
      void show_angle()const
      {cout << grad << '°' << min << "' " <<direct<<endl;}
};

int main()
{
setlocale (0, "");
angle A1(100, 56.8, 'E');
A1.show_angle();
char n;
do
{
    A1.get_angle();
    A1.show_angle();
    cout<<"\nЕще раз?(y/n): ";
    cin>>n;
}
while (n !='n');
system("pause");
return 0;
}
