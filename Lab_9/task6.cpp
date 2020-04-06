#include<iostream>
using namespace std;

int main()
{
    setlocale(LC_CTYPE,"rus");
int compstr(char* , char * );
    char*s="А вдома лучше";
    char*s1="Кот ходит по квартире";
    char*s2="Сегодня на ужин омлет";
 int a=compstr(s,s1);
 cout<<a<<endl;
 a=compstr(s1,s);
 cout<<a<<endl;
 a=compstr(s1,s1);
 cout<<a<<endl;

system("pause");
return 0;
}
int compstr(char*a, char *b)
{
    if(*a<*b)
        return -1;
    else
        if(*a>*b)
        return 1;
    else
        if(*a==*b)
        return 0;


}
