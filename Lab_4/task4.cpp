#include <iostream>
using namespace std;

struct Distance //јнглийские расстояния
    {
    int feet;
    float inches;
    };
///////////////////////////////////////////////////////////
Distance bigengl(Distance,Distance);//объявления
void engldisp(Distance);
int main()
{
    setlocale(0, "");
    Distance d1,d2,d3;  //определение трех расстояний
                        //получить рассто€ние d1 от пользователя
    cout <<"Введите число футов:";cin >>d1.feet;
    cout <<"Введите число дюймов:";cin >>d1.inches;
                        //получить рассто€ние d2 от пользователя
    cout <<"\nВведите число футов:";cin >>d2.feet;
    cout <<"Введите число дюймов:";cin >>d2.inches;
    d3 =bigengl(d1,d2); //d3 больше, чем d1 и d2
                        //вывести все значения
    cout <<"\nd1=";engldisp(d1);
    cout <<"\nd2=";engldisp(d2);
    cout <<"\nНаибольшее Число ";engldisp(d3);cout <<endl;

    system("pause");
    return 0;
}
//---------------------------------------------------------
//bigengl()
//сравнивает две структуры типа Distance, возвращает
//наибольшую
Distance bigengl(Distance dd1,Distance dd2 )
{
    if(dd1.feet >dd2.feet)    //если число футов различается,
      return dd1;             //вернуть то, которое больше
    if(dd1.feet <dd2.feet)
      return dd2;
    if(dd1.inches >dd2.inches)//если число дюймов
                              // различается,
      return dd1;             //вернуть наибольшее
    else       //дюймы или dd2, если равные значения
      return dd2;
}
//---------------------------------------------------------
//engldisp()
//выводит структуру типа Distance в футах и дюймах
void engldisp(Distance dd )
{
    cout <<dd.feet <<"\'-" <<dd.inches <<"\"";
}
