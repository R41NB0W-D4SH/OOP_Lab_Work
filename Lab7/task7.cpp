/////////////////////////////////////////////////////////////////
class fraction
{
private:
    int chsl;
    int znam;
public:
    fraction(): chsl(0), znam(0) {}
    fraction(int c, int z):chsl(c), znam(z)
    {}
    static char sl;
    void get(){
        cout <<"введите числитель и знаменатель: ";
        cin >>chsl >>sl >>znam;
        if((chsl==0)||(znam==0))exit(1);//хз зачем перегружать == и !=
    }
//---------------------OPER---------------------------------------------
    fraction operator+(fraction f2)
    {
        int ch=chsl*f2.znam+znam*f2.chsl;
        int zn=znam*f2.znam;
        lowterms(ch,zn);
        return fraction(ch,zn);
    }
    fraction operator-(fraction f2)
    {
        int ch=chsl*f2.znam-znam*f2.chsl;
        int zn=znam*f2.znam;
        lowterms(ch,zn);
        return fraction(ch,zn);
    }
    fraction operator*(fraction f2)
    {
        int ch=chsl*f2.chsl;
        int zn=znam*f2.znam;
        lowterms(ch,zn);
        return fraction(ch,zn);
    }
    fraction operator/(fraction f2)
    {
        int ch=chsl*f2.znam;
        int zn=znam*f2.chsl;
        lowterms(ch,zn);
        return fraction(ch,zn);
    }
//-----------------------------------------------------------------------
//====================сокращение дробей=============================================
    void lowterms(int &chsl, int &znam)
    {
        long tnum, tden, temp, gcd;
        tnum=labs(chsl);
        tden=labs(znam);
        while(tnum!=0)
        {
            if(tnum<tden){temp=tnum; tnum=tden; tden=temp;}
            tnum-=tden;
        }
        gcd=tden;
        chsl/=gcd;
        znam/=gcd;
    }
//====================END_OF_сокращение дробей)======================================
    void show()
    {cout <<"Ответ: " <<chsl <<sl <<znam <<endl;}
};
/////////////////////////////////////////////////////////////////
char fraction::sl='/';
//---------------------------------------------------------------
 
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    fraction f, f1, f2;
    static char ch;
    cout <<"Чтобы ввести первую дробь, "; f1.get();
    cout <<"Введите символ операции: "; cin >>ch;
    cout <<"Чтобы ввести вторую дробь, "; f2.get();
    switch(ch)
    {
    case '+': f=f1+f2;
        break;
    case '-': f=f1-f2;
        break;
    case '*': f=f1*f2;
        break;
    case '/': f=f1/f2;
        break;
    }
    f.show();
    system("pause");
    return 0;
}
