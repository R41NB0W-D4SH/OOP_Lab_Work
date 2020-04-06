#include <iostream>
using namespace std;
 
class Massiv
{
private:
 
    int* ap;
    int n;
    int m;
public:
    Massiv(int n_=100, int m_=10): n(n_),m(m_)
    {
    ap=new int[n];
    setValue();
    }
    void setValue()
    {
    for(int k=0;k<n;)
     for(int i=0;i<m;i++)
        *(ap+k++)=i*m;
    }
 
    int& operator[] (int i)
    {
        return ap[i];
    }
    void show(){
for(int i=0;i<n;i++) 
cout<<*(ap+i)<<endl;
    cout<<endl;
}
 
 
 
};
 
int main ( )
{
 
    Massiv m;
    m.show();
system("pause");
  return 0;
}
