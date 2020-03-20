#include <iostream>

using namespace std;

struct point
{
   int x;
   int y;
};

int main()
{
    setlocale(0, "");
    point p1, p2, p3;

    cout << "Введите координаты для первой точки : ";
    cin >> p1.x >> p1.y;
    cout << "Введите координаты для второй точки : ";
    cin >> p2.x >> p2.y;

    p3.x = p1.x + p2.x;
    p3.y = p1.y + p2.y;

    cout << "Сумма координат первой и второй точек : " << p3.x << ", " << p3.y << endl;

    system("pause");
    return 0;
}
