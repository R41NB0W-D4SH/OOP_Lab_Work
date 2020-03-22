#include <iostream>

using namespace std;

struct time
{
    int hour;
    int min;
    int sec;
};

int main()
{
    setlocale (0, "");
    time t1;

    cout <<"Введите часы, минуты и секунды: "; cin >>t1.hour >>t1.min >>t1.sec;

    long totalsec =t1.hour*3600+t1.min*60+t1.sec;

    cout <<"Количество секунд: " <<totalsec <<endl;

    system ("pause");
    return 0;
}
