#include <iostream>
using namespace std;
double power(double n,int p = 2);//p has default value 2
int main()
{
    setlocale(0, "");
    double number,answer;
    int pow;
    char usl;
    cout <<"Введите число : ";//get number
    cin >>number;
    cout <<"Будете вводить степень (y/n)?" << endl;
    cin >> usl;
    if(usl == 'Y' || usl == 'y')//пользователю нужен не квадрат числа?
    {
        cout <<"Введите степень : ";
        cin >> pow;
        answer = power(number,pow);//возвести число в степень
    }
    else
    {
        answer = power(number);//квадрат числа
    }
    cout <<"Ответ : " <<answer <<endl;
    return 0;
}

double power(double n, int p)
{
    double result = 1.0;//начать с 1
    for(int j = 0;j < p; j++)//умножить на n
    result *= n;//p раз
    return result;
}
