#include <iostream>
using namespace std;
int main ( )
{
    const int n=10;
    int* ap[n];
    for(int j=0;j<n;j++)
        *(ap+j)=new int[n];
    for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
            *(*(ap+j)+k)=k*10;
    for(int j=0;j<10;j++)
        for(int k=0;k<10;k++)
            cout<<*(*(ap+j)+k)<<endl;
system("pause");
  return 0;
}
