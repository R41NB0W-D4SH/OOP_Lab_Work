#include <iostream>
using namespace std;
float circarea(float radius);
int main()
{
    setlocale(0, "");
    double rad;
    cout <<"Введите радиус окружности : ";
    cin >>rad;
    cout <<"Площадь равна : " <<circarea(rad)<<endl;

    system("pause");
    return 0;
}
float circarea(float r)
{
    const float PI = 3.14159F;
    return r *r *PI;
}
