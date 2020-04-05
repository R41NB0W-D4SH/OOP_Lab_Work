#include <iostream>

using namespace std;
const int MAX=10;

class safearray
{
private:
    int LIMIT[MAX];
public:
    safearray(){}
    void putel(int indx, int n)//индекс и значение, и вставлет это значение в массив по данному индексу
    {
        if((indx<0)||(indx>MAX))
        {cout <<"Введен некорректный индекс массива!"; getchar(); exit(1);}
        LIMIT[indx]=n;
    }
    int getel(int indx)//индекс, и возвращет значение элемента по данному индексу
    {
        if((indx<0)||(indx>MAX))
        {cout <<"Введен некорректный индекс массива!"; getchar(); exit(1);}
        return LIMIT[indx];
    }
};

int main()
{
    setlocale(0,"");
    safearray sa1;
    int temp=12345;
    sa1.putel(7,temp);
    temp=sa1.getel(7);
    cout <<"Значение элемента массива: " <<temp <<endl;
    system("pause");
}
