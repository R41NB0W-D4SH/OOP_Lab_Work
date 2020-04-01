#include <iostream>
using namespace std;

class Int //(не то же самое, что int)
{
    private:
    int i;
    public:
    Int()                  //создание Int
    {i =0;}
    Int(int ii)           //создание и инициализаци Int
    {i =ii;}
    void add(Int i2,Int i3) //складывает два значени типа Int
    {i =i2.i +i3.i;}
    void display()        //вывести Int
    {cout <<i;}
};

int main()
{
    Int Int1(7);          //создать и инициализировать Int
    Int Int2(11);         //создать и инициализировать Int
    Int Int3;             //создать Int
    Int3.add(Int1,Int2);  //сложение двух переменных типа Int
    cout <<"Int3 = ";Int3.display(); //вывести результат
    cout <<endl;
    return 0;
}
