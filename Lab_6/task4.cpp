#include <iostream>
using namespace std;

static int n=0;

int maxint(int mas[])
{
    int max=0;//переменная для максимального значения массива
    static int ind=0;//перемення для значения индекса массива, содержащего макс элемент
    for(int j=0; j<n; j++)
    {if(mas[j]>max){max=mas[j];ind=j;}}
    return ind;
}

int main()
{
    setlocale(0,"");
    int chsl[100];
    char ch;
    do{
        cout <<"Введите элемент массива: ";
        cin >>chsl[n++];
        cout <<"Еще (y/n)?";
        cin >>ch;
    }while(ch != 'n');
    int d=maxint(chsl);
    cout <<"Максимальный элемент: " <<chsl[d] <<" его индекс:" <<d <<endl;
    system("pause");
}
