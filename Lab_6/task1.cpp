#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    setlocale(0, "");
    void reversit(char [] );  //прототип
    const int MAX = 80;         //размер массива
    char str [MAX];            //строка
    cout <<"Введите строку:";//получить строку от пользователя
    cin.get(str,MAX);
    reversit(str);             //перевернуть строку
    cout <<"Перевернутая строка : ";//и вывести ее
    cout <<str <<endl;
    system("pause");
    return 0;
}

void reversit(char s[])
{
    int len = strlen(s);        //найти длину строки
    for(int j = 0;j < len / 2; j++) //поменять все символы из первой половины
    {
        char temp = s[j];        //на символы
        s[j] = s [len - j - 1];     //из второй половины
        s[len - j - 1] = temp;
    }
}
