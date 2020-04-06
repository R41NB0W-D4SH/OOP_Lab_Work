#include <iostream>
#include <string>
using namespace std;
///////////////////////////////////////////////////////////
class person            // некоторый человек
{
  protected:
    string name;        // имя
    float salary;
  public:
    void setData ( )    // установка имени
      { cout << "Введите имя: "<<endl;
        cin >> name; 
        cout<<"Введите оклад: "<<endl;
        cin>>salary;
    }
    void printData ( )  // показ имени
      { 
          cout << endl <<"Имя: "<< name; 
          cout<<endl<<"Оклад: "<<salary;
 
    }
    string getName ( )  // получение имени
      { return name; }
    float getSalary ( )  // получение имени
      { return salary; }
 
};
///////////////////////////////////////////////////////////
int main ( )
{
    setlocale(LC_CTYPE,"rus");
  void salsort ( person**, int ); // прототип функции
  person* persPtr [ 100 ];      // массив указателей на person
  int n = 0;                    // количество элементов в массиве
  char choice;                  // переменная для ввода символа
 
  do
  {
    persPtr [ n ] = new person;       // создаем новый объект
    persPtr [ n ]->setData ( );       // вводим имя
    n++;                              // увеличиваем количество
    cout << "Продолжаем ввод (d/н)?"; // спрашиваем, закончен ли ввод
    cin >> choice;
  }
  while ( choice == 'd' );
 
  cout << "\nНеотсортированный список:";
  for ( int j = 0; j < n; j++ ) // покажем неотсортированный список
      persPtr [ j ]->printData ( );
 
  salsort ( persPtr, n );         // отсортируем указатели
 
  cout << "\nОтсортированный список:";
  for (int  j = 0; j < n; j++ )     // покажем отсортированный список
      persPtr [ j ]->printData ( );
  cout << endl;
 
  system("pause");
  return 0;
}
///////////////////////////////////////////////////////////
void salsort ( person** pp, int n )
{
  
  int j, k;                          // переменные для циклов
 
  for ( j = 0; j < n- 1; j++ )      // внешний цикл
    for ( k = j + 1; k < n; k++ )    // внутренний цикл
    if( (*(pp+j))->getSalary ( ) > (*(pp+k))->getSalary ( ) ) // если первая строка больше второй,
  {
    person* tempptr = *(pp+j); // меняем их местами
    *(pp+j) = *(pp+k);
    *(pp+k) = tempptr;
  }
}
