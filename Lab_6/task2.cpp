#include <iostream>
#include <string>
using namespace std;

class employee
    {
    private:
      string name;
      long number;
    public:
      void getdata()    //получить данные от пользователя
        {
        cout <<"\nВведите имя:";cin >>name;
        cout <<"Введите номер:";cin >>number;
        }
      void putdata()    //вывод данных
        {
        cout <<"\nИмя:" <<name;
        cout <<"\nНомер:" <<number;
        }
    };

int main()
    {
    setlocale(0, "");
    employee emparr [100]; //массив типа employee
    int n =0;              //количество работников
    char ch;               //ответ пользователя
    do
    {                   //получить данные от пользователя
      cout <<"Введите данные о работнике с номером "             <<n+1;
      emparr [n++].getdata();
      cout <<"Продолжить (y/n)?";cin >>ch;
    }
     while(ch != 'n' || ch != 'N');
    for(int j=0;j<n;j++)   //вывести данные из массива
    {
      cout <<"\nНомер работника " <<j+1;
      emparr [j].putdata();
    }
    cout <<endl;
    system("pause");
    return 0;
    }
