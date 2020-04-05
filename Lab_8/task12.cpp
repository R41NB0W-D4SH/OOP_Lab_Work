using namespace std;
///////////////////////////////////////////////////////////////////
class sterling
{
protected:
    long ft;
    int sh;
    int pn;
public:
    char ch;
    sterling():ft(0L), sh(0), pn(0)
    {}
    sterling(long f, int s, int p):ft(f), sh(s), pn(p)
    {}
    sterling(double FT)
    {
       ft=(long)FT;
       sh=(int)((FT-ft)*20);
       pn=(int)((((FT-ft)*20)-sh)*12);
    }
    operator double()
    {return (ft*240+sh*12+pn)/240.0;}
    void getin()
    {
        cout <<"Введите фунты, шиллинги и пенсы через точку: ";
        cin >>ft >>ch >>sh >>ch >>pn;
    }
    void show()
    {cout <<"Введена сумма: " <<ft <<"." <<sh <<"." <<pn;}
    sterling operator+(sterling s2)
    {return sterling(double(sterling(ft,sh,pn))+double(s2));}
    sterling operator-(sterling s2)const
    {return sterling(double(sterling(ft,sh,pn))-double(s2));}
    sterling operator*(double s2)const
    {return sterling(double(sterling(ft,sh,pn))*s2);}
    sterling operator/(sterling s2)const
    {return sterling(double(sterling(ft,sh,pn))/double(s2));}   
};
//////////////////////////////////////////////////////////////////
class sterfrac:private sterling
{
private:
    int eighths;
    int znam;
public:
    sterfrac():sterling(), eighths(0), znam(0)
    {}
    sterfrac(long f, int s, int p, int e, int z):sterling(f, s, p), eighths(e), znam(z)
    {}
    sterfrac(double FT)
    {
       ft=(long)FT;
       sh=(int)((FT-ft)*20);
       pn=(int)((((FT-ft)*20)-sh)*12);
    }
    operator double()
    {return (ft*240+sh*12+pn)/240.0;}
    void getin()
    {
        sterling::getin();
        cout <<"Введите восьмую часть: ";
        cin >>eighths;
        znam=8;
    }
//-----------------------------------------------------------------------
    sterfrac operator+(sterfrac s2)
    {
        sterfrac  sf=((ft*240+sh*12+pn)/240.0)+s2;
        sf.eighths=eighths*s2.znam+znam*s2.eighths;
        sf.znam=znam*s2.znam;
        return sf;
    }
    sterfrac operator-(sterfrac s2)
    {
        sterfrac  sf=((ft*240+sh*12+pn)/240.0)-s2;
        sf.eighths=eighths*s2.znam-znam*s2.eighths;
        sf.znam=znam*s2.znam;
        return sf;
    }
    sterfrac operator*(double s2)
    {
        sterfrac sf=((ft*240+sh*12+pn)/240.0)*s2;
        sf.eighths=eighths;
        sf.znam=znam;
        return sf;
    }
    sterfrac operator/(sterfrac s2)
    {
        sterfrac sf=((ft*240+sh*12+pn)/240.0)/((s2.ft*240+s2.sh*12+s2.pn)/240.0);
        sf.eighths=eighths*s2.znam;
        sf.znam=znam*s2.eighths;
        return sf;
    }
//-----------------------------------------------------------------------
    void show()
    {
        long tnum, tden, temp, gcd;
        tnum=labs(eighths);
        tden=labs(znam);
        while(tnum!=0){
            if(tnum<tden){temp=tnum; tnum=tden; tden=temp;}
            tnum-=tden;
        }
        gcd=tden;
        int ei=eighths/gcd;
        int zn=znam/gcd;
        if(ei>zn){
            ei=zn-ei;
            pn++;
            if(pn>11){
                pn-=12;
                sh++;
            }
            if(sh>19){
                sh-=20;
                ft++;
            }
        }
        sterling::show();
        cout <<"-"<<ei <<"/" <<zn <<endl;
    }
};
//////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    sterfrac s, s1(4, 5, 6, 7, 8), s2(1, 2, 3, 4, 8);
    double d=3.1254;
    //s1.getin();
    //s2.getin();
    if(s1<s2){exit(1);}
    s=s1+s2;
    s.show();
    s=s1-s2;
    s.show();
    s=s1*d;
    s.show();
    s=s1/s2;
    s.show();
    cout <<endl;
    system("pause");
    return 0;
}
