#include <iostream>

using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

struct date
{
    int day;
    int mon;
    int year;
};

struct employee
{
    int number;
    float posobie;
    date data;
    etype prof;
};

int main()
{
    setlocale (0, "");
    char ch, ch1, ch2, ch3;
    employee s1, s2, s3;
    cout <<"Введите номер сотрудника, заработную плату, должность, дату приема на работу\n";
    cin >>s1.number >>s1.posobie >>ch1 >>s1.data.day >>ch >>s1.data.mon >>ch >>s1.data.year;
    cin >>s2.number >>s2.posobie >>ch2 >>s2.data.day >>ch >>s2.data.mon >>ch >>s2.data.year;
    cin >>s3.number >>s3.posobie >>ch3 >>s3.data.day >>ch >>s3.data.mon >>ch >>s3.data.year;
    switch(ch1)
    {
    case 'l': s1.prof =laborer; break;
    case 's': s1.prof =secretary; break;
    case 'm': s1.prof =manager; break;
    case 'a': s1.prof =accountant; break;
    case 'e': s1.prof =executive; break;
    case 'r': s1.prof =researcher; break;
    }
    cout <<"Вывод данных:" <<endl;
    cout <<s1.number <<" " <<s1.posobie <<" ";
    switch (s1.prof)
    {
    case laborer: cout <<"laborer"; break;
    case secretary: cout <<"secretary"; break;
    case manager: cout <<"manager"; break;
    case accountant: cout <<"accountant"; break;
    case executive: cout <<"executive"; break;
    case researcher: cout <<"researcher"; break;
    }
    cout <<" " <<s1.data.day <<ch <<s1.data.mon <<ch <<s1.data.year <<endl;
    switch(ch2)
    {
    case 'l': s2.prof =laborer; break;
    case 's': s2.prof =secretary; break;
    case 'm': s2.prof =manager; break;
    case 'a': s2.prof =accountant; break;
    case 'e': s2.prof =executive; break;
    case 'r': s2.prof =researcher; break;
    }
    cout <<s2.number <<" " <<s2.posobie <<" ";
    switch (s2.prof)
    {
    case laborer: cout <<"laborer"; break;
    case secretary: cout <<"secretary"; break;
    case manager: cout <<"manager"; break;
    case accountant: cout <<"accountant"; break;
    case executive: cout <<"executive"; break;
    case researcher: cout <<"researcher"; break;
    }
    cout <<" " <<s2.data.day <<ch <<s2.data.mon <<ch <<s2.data.year <<endl;
    switch(ch3)
    {
    case 'l': s3.prof =laborer; break;
    case 's': s3.prof =secretary; break;
    case 'm': s3.prof =manager; break;
    case 'a': s3.prof =accountant; break;
    case 'e': s3.prof =executive; break;
    case 'r': s3.prof =researcher; break;
    }
    cout <<s3.number <<" " <<s3.posobie <<" ";
    switch (s3.prof)
    {
    case laborer: cout <<"laborer"; break;
    case secretary: cout <<"secretary"; break;
    case manager: cout <<"manager"; break;
    case accountant: cout <<"accountant"; break;
    case executive: cout <<"executive"; break;
    case researcher: cout <<"researcher"; break;
    }
    cout <<" " <<s3.data.day <<ch <<s3.data.mon <<ch <<s3.data.year <<endl;

    system ("pause");
    return 0;
}
