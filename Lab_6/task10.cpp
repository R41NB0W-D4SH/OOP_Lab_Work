#include <iostream>
using namespace std;

class matrix
{
private:
    int str, stlb;
    int mass[10][10];
public:
    matrix(int r, int b) : str(r), stlb(b){}
    void putel(int i1, int i2, int n)
    {
        if(((i1<0)||(i1>str))||((i2<0)||(i2>stlb)))
        {cout <<"Введен некорректный индекс массива!"; getchar(); exit(1);}
        mass[i1][i2]=n;
    }
    int getel(int i1, int i2)
    {
        if(((i1<0)||(i1>str))||((i2<0)||(i2>stlb)))
        {cout <<"Введен некорректный индекс массива!"; getchar(); exit(1);}
        return mass[i1][i2];
    }
};

int main()
{
    setlocale(0,"");
    matrix m1 (3, 4);
    int temp=12345;
    m1.putel(7, 4, temp);
    temp=m1.getel(7, 4);
    cout <<"Значение равно: " <<temp <<endl;
    system("pause");
}
