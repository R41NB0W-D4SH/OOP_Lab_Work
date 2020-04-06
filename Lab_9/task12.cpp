#include "stdafx.h"
#include <iostream>
#include "conio.h"
using namespace std;

float fmem[20];
int fmem_top=0;
int pmem[20];

class Float
{int addr;

public:
Float(float f)
{fmem[fmem_top]=f; pmem[fmem_top]=fmem_top; addr=fmem_top;  fmem_top++;}

~Float()
{}

int& operator &()
{return addr;}
};


class ptrFloat
{
    int paddr;

public:
ptrFloat(int a):paddr(a)
{}

~ptrFloat()
{}

float& operator* () const
{
    return fmem[pmem[paddr]];
}

};


int main()
{
Float var1 =1.2;
Float var2 =3.4;
ptrFloat ptr1 =&var1;
ptrFloat ptr2 =&var2;
cout<<"*ptr1= "<<*ptr1;
cout<<"\n*ptr2= "<<*ptr2;
*ptr1=5.6;
*ptr2=7.8;
cout<<"\n*ptr1= "<<*ptr1;
cout<<"\n*ptr2= "<<*ptr2;
    _getch();
}
