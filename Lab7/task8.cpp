static const int MAX=30;
//////////////////////////////////////////////////////////////////
class bMoney
{
private:
    long double money;
public:
    bMoney()
    {money=0.0;}
    explicit bMoney(long double m):money(m)//преобразование long double в bMoney
    {}
    operator long double()//преобразование bMoney в long double
    {return money;}
    void getmoney();
    void putmoney();
    double InD(char ch[]);
    bMoney operator+(bMoney m2)
    {return bMoney(money+m2.money);}
    bMoney operator-(bMoney m2)
    {return bMoney(money-m2.money);}
    bMoney operator*(long double cet)//цена за единицу времени, затраченного на изделие
    {return bMoney(money*cet);}
    long double operator/(bMoney m2)//общая цена, деленная на цену за изделие
    {return (money/m2.money);}
    bMoney operator/(long double cet)//общая цена, деленная на количество изделий
    {return bMoney(money/cet);}
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
//////////////////////////////////////////////////////////////////
double bMoney::InD(char ch[])
{
    double rez, rez1;
    int t, o, tt, bb;
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
 
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    char ch='a';
    do{
        bMoney m, m1, m2;
        
        long double z=0, p=0;
        m1.getmoney();
        m2.getmoney();
        cout <<"Введите число с плавающей точкой: "; cin >>z;
        m=m1+m2;
        cout <<"Сумма " <<m1 <<" и " <<m2 <<" равна: " <<m <<endl;
        m=m1-m2;
        cout <<"Разность " <<m1 <<" и " <<m2 <<" равна: " <<m <<endl;
        m=m1*z;
        cout <<"Цена за единицу времени, затраченного на изделие (" <<m1 <<"*" <<z <<"): " <<m <<endl;
        p=m1/m2;
        cout <<"Общая цена, деленная на цену за изделие (" <<m1 <<"/" <<m2 <<"): " <<p <<endl;
        m=m1/z;
        cout <<"Общая цена, деленная на количество изделий (" <<m1 <<"/" <<z <<"): " <<m <<endl;
        cout <<"Еще раз?(y/n)";
        cin >>ch;
    }while(ch!='n');
    return 0;
}
