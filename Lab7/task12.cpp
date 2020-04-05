using namespace std;
//////////////////////////////////////////////////////////////////////
class sterling
{
private:
    long ft;
    int sh;
    int pn;
public:
    sterling()
    {ft=0, sh=0, pn=0;}
    sterling(long f, int s, int p):ft(f), sh(s), pn(p)
    {}
    void showster()
    {cout <<"\x9C" <<ft <<"." <<sh <<"." <<pn <<endl;}
    sterling(double FT)//преобразование дабл в стерлинг
    {
        FT/=50;
        ft=(long)FT;
        sh=(int)((FT-ft)*20);
        pn=(int)((((FT-ft)*20)-sh)*12);
    }
    long getFnt()const
    {return ft;}
    int getShg()const
    {return sh;}
    int getPen()const
    {return pn;}
};
//////////////////////////////////////////////////////////////////////
class bMoney
{
private:
    long double money;
public:
    bMoney()
    {money=0.0;}
    bMoney(long double m):money(m)
    {}
    operator long double()//преобразование bMoney в long double
    {return money;}
    void showMoney()
    {cout <<money <<endl;}
    bMoney(sterling ss)//преобразование sterling в bMoney
    {
        long ft=ss.getFnt();
        int sh=ss.getShg();
        int pn=ss.getPen();
        money=((ft*240+sh*12+pn)/240.0)*50;
    }
};
//////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    sterling s(7,8,5);
    bMoney d(371.042);
    bMoney b=s;
    b.showMoney();//вывод преобразования sterling в bMoney
    sterling st=d;
    st.showster();//вывод преобразования bMoney в sterling
    system("pause");
    return 0;
}
