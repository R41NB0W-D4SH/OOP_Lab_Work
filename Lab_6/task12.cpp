#include "stdafx.h"
#include <iostream>
#include <clocale>
 
using namespace std;
static const int MAX=30;
//////////////////////////////////////////////////////////////////
class bMoney
{
private:
    long double money;
public:
    bMoney(){money=0.0;}
    bMoney(char s[]){}
    void madd(bMoney m1, bMoney m2);
    void getmoney();
    void putmoney();
    double InD(char ch[]);
};
//////////////////////////////////////////////////////////////////
void bMoney::getmoney()
{
    char gIN[MAX], gOUT[MAX];
    cout <<"Введите число: "; 
    cin >>gIN;
    int n=0, v=0;
    for(int j=0; j<strlen(gIN); j++){
        if((gIN[j]=='$')||(gIN[j]==',')){
            ++v;
            continue;
        }
        gOUT[n++]=gIN[j];
    }
    gOUT[strlen(gIN)-v]='\0';
    money=InD(gOUT);
}
void bMoney::putmoney()
{
    char pIN[MAX], pOUT[MAX];
    pOUT[0]='$';
    _gcvt_s(pIN, MAX, money, 16);
    int i=strlen(pIN);
        int g;
        int z=0;
        int t=0;
        for(int v=0; v<i; v++){
            if(pIN[v]==','){
                g=v-1;
                break;
            }else{
                g=v;
            }
        }
        for(int j=MAX; (j-z)>0; j--){
                if(i>=0){
                if(i==g+1){
                    pOUT[j-z]='.';
                    i--;
                    continue;
                }
                pOUT[j-z]=pIN[i];
            }else{
                for(int jj=0; jj<=(strlen(pIN)+z); jj++){
                    int temp;
                    temp=pOUT[j-z+jj];
                    pOUT[j-z+jj]=pOUT[j-z+jj+1];
                    pOUT[j-z+jj+1]=temp;
                }
                continue;
            }
            if(i<=g){
                ++t;
                if((t==3)&&(i>0)){
                    ++z;
                    pOUT[j-z]=',';
                    t=0;            
                }
            }
            i--;
        }
    cout <<"Сумма равна: " <<pOUT <<endl;
}
void bMoney::madd(bMoney m1, bMoney m2)
{
    money=m1.money+m2.money;
}
double bMoney::InD(char ch[])
{
    double rez, rez1;
    int t, b, o, tt, bb;
    rez=0.0, rez1=0.0;
    o=0;
    const int n=strlen(ch);
    const int c=48;
    for(int p=0; p<n; p++){
            if(ch[p]=='.'){
                t=p-1;
                tt=n-(p+1)-1;
                bb=n-(p+1);
                break;
            }
            else t=p, tt=n-(p+1)-1, bb=n-(p+1);
    }
    for(int j=0; j<n; j++){
        if(t>=0){
            o=ch[j]-c;
            rez+=o*pow(10,t);
            t--;
        }else if(tt>=0){
            o=ch[j+1]-c;
            rez1+=o*pow(10,tt);
            tt--;
        }
    }
    rez1/=pow(10,bb);
    rez+=rez1;
    return rez;
}
//////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    bMoney s[100];
    int i=0;
    char ch='a';
    do{
        s[i].getmoney();
        if(i>0){
            s[i].madd(s[i], s[i-1]);            
            cout <<"Еещ раз (y/n)?";
            cin >>ch;
        }
        if(ch!='n'){
            i++;
        }
    }while(ch!='n');
    s[i].putmoney();
    system("pause");
    return 0;
}
