#include <iostream>
using namespace std;
int main ( )
{
    const int n=10;
    int a0[n]={0,10,20,30,40,50,60,70,80,90};
    int a1[n]={0,10,20,30,40,50,60,70,80,90};
    int a2[n]={0,10,20,30,40,50,60,70,80,90};
    int a3[n]={0,10,20,30,40,50,60,70,80,90};
    int a4[n]={0,10,20,30,40,50,60,70,80,90};
    int a5[n]={0,10,20,30,40,50,60,70,80,90};
    int a6[n]={0,10,20,30,40,50,60,70,80,90};
    int a7[n]={0,10,20,30,40,50,60,70,80,90};
    int a8[n]={0,10,20,30,40,50,60,70,80,90};
    int a9[n]={0,10,20,30,40,50,60,70,80,90};
    int* ap[n]={a0,a1,a2,a3,a4,a5,a6,a7,a8,a9};
    for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
            cout<<ap[j][k]<<endl;
system("pause");
  return 0;
}
