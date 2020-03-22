#include <iostream>

using namespace std;

struct time
{
    int hrs;
    int min;
    int sec;
};

int main()
{
    setlocale(0, "");
    long ttl1, ttl2, ttl;
    time t1, t2, t;

    cout <<"Введите первое значение времени - часы, минуты, секунды: ";
    cin >>t1.hrs >>t1.min >>t1.sec;
    cout <<"Введите второе значение времени - часы, минуты, секунды: ";
    cin >>t2.hrs >>t2.min >>t2.sec;

    ttl1=t1.hrs * 3600 + t1.min * 60+t1.sec;
    ttl2=t2.hrs * 3600 + t2.min * 60 + t2.sec;
    ttl=ttl1 + ttl2;
    t.hrs=ttl / 3600;
    t.min=(ttl - t.hrs * 3600) / 60;
    t.sec=ttl - t.hrs * 3600 - t.min * 60;
    cout <<"Общее время: " <<t.hrs <<" часов " <<t.min <<" минут " <<t.sec <<" секунд" <<endl;

    system ("pause");
    return 0;
}
