#include <iostream>
using namespace std;

class time
    {
    private:
    int hrs,mins,secs;
    public:
    time():hrs(0),mins(0),secs(0) //конструктор без аргументов
      {}
          //конструктор с тремя аргументами
    time(int h,int m,int s):hrs(h),mins(m),secs(s)
      {}
    void display()const           //формат 11:59:59
      {cout <<hrs <<":" <<mins <<":" <<secs;}
    void add_time(time t1,time t2)//сложить две переменные
      {
      secs =t1.secs +t2.secs;     //сложить секунды
      if(secs >59 )               //если перебор,
        {secs -=60;mins++;}       //прибавить минуту
      mins +=t1.mins +t2.mins;    //сложить минуты
      if(mins >59 )         //если слишком много минут,
        {mins -=60;hrs++;}  //прибавить час
      hrs +=t1.hrs +t2.hrs; //сложить часы
      }
    };

int main()
    {
    const time time1(5,59,59);   //создание и инициализаци€
    const time time2(4,30,30);   //двух переменных
    time time3;//создать еще одну переменную
    time3.add_time(time1,time2); //сложить две переменные
    cout <<"time3 =";time3.display();//вывести результат
    cout <<endl;
    return 0;
    }
