#include <iostream>

using namespace std;

struct Time
{
    int hrs;
    int min;
    int sec;
};

void swap(Time&, Time&);

int main()
{
    setlocale(0, "");
    Time t1, t2;
    cout <<"Введите первое значение времени по типу чч мм сс: ";
    cin >>t1.hrs >>t1.min >>t1.sec;
    cout <<"Введите второе значение времени по типу чч мм сс: ";
    cin >>t2.hrs >>t2.min >>t2.sec;
    swap(t1, t2);
    cout <<"После обмена значений. Первое время: " <<t1.hrs <<':' <<t1.min <<":" <<t1.sec
        <<" второе: " <<t2.hrs <<":" <<t2.min <<":" <<t2.sec <<endl;
    system("pause");
    return 0;
}
void swap(Time& t1, Time& t2)
{
    Time t;
    t.hrs=t1.hrs; t1.hrs=t2.hrs; t2.hrs=t.hrs;
    t.min=t1.min; t1.min=t2.min; t2.min=t.min;
    t.sec=t1.sec; t1.sec=t2.sec; t2.sec=t.sec;
}
