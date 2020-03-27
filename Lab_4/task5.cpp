#include <iostream>
#include <clocale>

using namespace std;

char ch;
long hms_to_sec(int, int, int);

int main()
{
    int h, m, s;
    setlocale(0, "");
    while(ch !='n')
    {
        cout <<"Введите время (ЧЧ:ММ:СС): "; cin >> h >> m >> s;
        cout <<"Общее время в секундах: " << hms_to_sec(h, m, s) <<endl;
        cout <<"Еще раз? (y/n): "; cin >> ch;
    }
    system("pause");
    return 0;
}
long hms_to_sec(int hours, int min, int sec)
{
    return hours*3600+min*60+sec;
}
