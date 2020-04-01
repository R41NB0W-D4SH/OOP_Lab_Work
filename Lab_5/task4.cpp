#include <iostream>
using namespace std;

class employee
{
   private:
       int nomer;
       float posobie;
   public:
      employee(): nomer(0), posobie(0.0)
      {}
      void get_employee ()
      {
            cout<<"Введите номер: "; cin>>nomer;
            cout<<"Введите оклад: "; cin>>posobie;
      }
      void show_employee()const
      {cout<<"Номер сотрудника: "<<nomer<<" оклад: "<<posobie<<endl;}
};

int main()
{
setlocale (0, "");
employee x1, x2, x3;
x1.get_employee ();
x2.get_employee ();
x3.get_employee ();
x1.show_employee();
x2.show_employee();
x3.show_employee();
system("pause");
return 0;
}
