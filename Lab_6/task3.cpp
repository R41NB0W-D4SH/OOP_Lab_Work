#include <iostream>
using namespace std;

class Distance //класс  английских расстояний
    {
    private:
      int feet;
      float inches;
    public:
      Distance()               //конструктор (без аргументов)
        {feet =0;inches =0;}
      Distance(int ft,float in)//конструктор (2 аргумента)
        {feet =ft;inches =in;}
      void getdist()           //получить расстояние
                               //от пользователя
        {
        cout <<"\nВведите футы:";cin >>feet;
        cout <<"Введите дюймы:";cin >>inches;
        }
      void showdist()          //вывод расстояния
        {cout <<feet <<"\'-" <<inches <<'\"';}
      void add_dist(Distance,Distance );//объявления
      void div_dist(Distance,int );
    };

void Distance::add_dist(Distance d2,Distance d3)
    {
    inches =d2.inches +d3.inches; //сложить дюймы
    feet =0;                      //(для возможного переноса)
    if(inches >=12.0)             //если сумма превышает 12.0,
      {//уменьшить число дюймов
      inches -=12.0;              //на 12.0 и
      feet++;                     //увеличить число футов
      }                           //на 1
    feet +=d2.feet +d3.feet;      //сложить футы
    }

void Distance::div_dist(Distance d2,int divisor)
    {
    float fltfeet =d2.feet +d2.inches/12.0;//преобразовать
                                           //в формат float
    fltfeet /=divisor;                     //выполнить деление
    feet =int(fltfeet);              //получить футовую часть
    inches =(fltfeet-feet)*12.0;     //получить дюймовую часть
    }

int main()
    {
    setlocale(0, "");
    Distance distarr [100];       //массив из 100 объектов типа
                                  // Distance
    Distance total(0,0.0),average;// прочие расстояния
    int count =0;        //считает количество введенных значений
    char ch;             //признак ответа пользователя
    do {
      cout <<"Введите расстояние "; //получить значения
      distarr [count++].getdist();    //от оператора,занести
      cout <<"\nПродолжить (y/n)?";   //их в массив
      cin >>ch;
      }while(ch != 'n');
    for(int j=0;j<count;j++)  //сложить все расстояния
    total.add_dist(total,distarr [j] ); //в total
    average.div_dist(total,count );      //разделить на число
    cout <<"\nСреднее:";     //вывести среднее значение
    average.showdist();
    cout <<endl;
    system("pause");
    return 0;
    }
