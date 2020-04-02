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
      void set_angle ()
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

class ship
{
   private:
      angle shirota, dolgota;
      int nomer;
      static int vsego;
   public:
      ship()
        {vsego++; nomer = vsego;}
      void set_ship ();
      void show_ship ()const;

};

int ship::vsego = 0;

void ship::set_ship ()
    {
        cout<<"Широта: "; shirota.set_angle();
        cout<<"Долгота: "; dolgota.set_angle();
    }

void ship::show_ship()const
    {
        cout << "Порядковый номер корабля: " <<nomer<<endl;
        cout << "Координаты." <<endl;
        cout << "Широта: "; shirota.show_angle();
        cout << "Долгота: "; dolgota.show_angle();
    }

int main()
{
setlocale (0, "");
ship s1, s2, s3;
s1.set_ship ();
s2.set_ship ();
s1.show_ship();
s2.show_ship();
system("pause");
return 0;
}
