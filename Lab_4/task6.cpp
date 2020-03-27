#include <iostream>

using namespace std;

struct Time
{
    int hrs;
    int min;
    int sec;
};

char ch;
long vr;
long time_to_sec(Time, Time);
Time secs_to_time(long);

Time t1, t2, t;

int main()
{
    setlocale(0, "");
    cout <<"Введите первое время (чч.мм.сс): "; cin >>t1.hrs >>t1.min >>t1.sec;
    cout <<"Введите второе время (чч.мм.сс): "; cin >>t2.hrs >>t2.min >>t2.sec;
    vr =time_to_sec(t1, t2);
    cout <<"Общее время в секундах: " <<vr <<endl;
    t=secs_to_time(vr);
    cout <<"Возвращенное время: " <<t.hrs <<":"<<t.min <<":"<<t.sec <<endl;
    system("pause");
    return 0;
}
long time_to_sec(Time t1, Time t2)
{
    vr=(t1.hrs*3600+t1.min*60+t1.sec)+(t2.hrs*3600+t2.min*60+t2.sec);
    return vr;
}
Time secs_to_time(long vr)
{
    t.hrs=vr/3600;
    t.min=(vr-t.hrs*3600)/60;
    t.sec=vr-t.hrs*3600-t.min*60;
    return t;
}
