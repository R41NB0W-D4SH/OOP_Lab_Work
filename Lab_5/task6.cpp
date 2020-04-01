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

class employee
{
   private:
       date D1;
       int nomer;
       float posobie;
       enum etype {laborer, secretary, manager, accountant, executive, researcher};
       etype temp;
   public:
      employee(): nomer(0), posobie(0.0)
      {}
      void get_employee ();
      void show_employee()const;
};

void employee::get_employee ()
      {
            char letter;
            D1.get_date();
            cout<<"Введите номер: "; cin>>nomer;
            cout<<"Введите оклад: "; cin>>posobie;
            cout<<"Введите первую букву должности "<<endl
            <<"(laborer, secretary, manager, accoutant, executive, researcher):";
            cin >> letter;
            switch(letter)
        {
                case 'l': temp = laborer; break;
                case 's': temp = secretary; break;
                case 'm': temp = manager; break;
                case 'a': temp = accountant; break;
                case 'e': temp = executive; break;
                case 'r': temp = researcher; break;
        }
      }

void employee::show_employee()const
{
    cout << "\nДата приема на работу: ";
    D1.show_date();
    cout<<"Номер сотрудника: "<<nomer
    <<"\nОклад: "<<posobie<<"\nДолжность:";
       switch(temp)
    {
                case 0: cout << "laborer" << endl; break;
                case 1: cout <<  "secretary" << endl; break;
                case 2: cout << "manager" << endl; break;
                case 3: cout <<  "accountant" << endl; break;
                case 4: cout << "executive" << endl; break;
                case 5: cout <<  "researcher" << endl; break;
    }
}

int main()
{
setlocale (0, "");
employee x1, x2;
x1.get_employee ();
x1.show_employee();
system("pause");
return 0;
}
