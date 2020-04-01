#include <iostream>
using namespace std;

class date
{
   private:
      int day, mons, year;
   public:
      date(): day(0), mons(0), year(0)
      {}
      void get_date ()
      {
      cout<<"Введите день, месяц и год в формате \"dd/mm/yy\":"<<endl;
      cout<<"день ";
      cin>>day;
      cout<<"месяц: ";
      cin>>mons;
      cout<<"год: ";
      cin>>year;
      }
      void show_date()const
      {cout << day << "/" << mons << "/" <<year<<endl;}
};

int main()
{
setlocale (0, "");
date x1, x2;
x1.get_date();
x2.get_date();
x1.show_date();
x2.show_date();
system("pause");
return 0;
}
