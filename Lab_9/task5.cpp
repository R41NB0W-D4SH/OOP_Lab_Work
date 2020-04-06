#include<iostream>
using namespace std;
 
int main()
{
    setlocale(LC_CTYPE,"rus");
    void addarrays(float*,float*, float*,int);
    const int n=5;
    float a3[n];
    float a1[n]={2.2,5.5,8.6,9.1,7.2};
    float a2[n]={3.3,5.9,6.5,4.4,8.2};
    addarrays(a1,a2,a3,n);
for(int i=0;i<n;i++)
        cout<<*(a3+i)<<endl;
system("pause");
return 0;
}
void addarrays(float* a,float* b, float* c,int n)
{
    for(int i=0;i<n;i++)
        *(c+i)=*(a+i)+*(b+i);
    
}
