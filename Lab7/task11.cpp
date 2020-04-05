using namespace std;
static char ch='.';
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
    sterling(double FT)
    {
       ft=(long)FT;
       sh=(int)((FT-ft)*20);
       pn=(int)((((FT-ft)*20)-sh)*12);
    }
    sterling(long f, int s, int p):ft(f), sh(s), pn(p)
    {}
    operator double()
    {return (ft*240+sh*12+pn)/240.0;}
    void getsterling()
    {
        cout <<"Введите значения фунтов, шиллингов и пенсов: \x9C";
        cin >>ft >>ch >>sh >>ch >>pn;
    }
    void putsterling()
    {cout <<"\x9C" <<ft <<ch <<sh <<ch <<pn ;}
    sterling operator+(sterling s2)
    {return sterling(double(sterling(ft,sh,pn))+double(s2));}
    sterling operator-(sterling s2)
    {return sterling(double(sterling(ft,sh,pn))-double(s2));}
    sterling operator*(double s2)
    {return sterling(double(sterling(ft,sh,pn))*s2);}
    sterling operator/(sterling s2)
    {return sterling(double(sterling(ft,sh,pn))/double(s2));}
    sterling operator/(double s2)
    {return sterling(double(sterling(ft,sh,pn))/s2);}
};
//////////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    sterling s, s1(4,5,7), s2(2,9,8);
    double d=3.1254;
    //s1.getsterling();
    //s2.getsterling();
    s=s1+s2;
    cout <<"Сумма "; s1.putsterling(); cout <<" и "; s2.putsterling();  cout <<" равна: "; s.putsterling(); cout <<endl;
    s=s1-s2;
    cout <<"Разность "; s1.putsterling(); cout <<" и "; s2.putsterling();  cout <<" равна: "; s.putsterling(); cout <<endl;
    s=s1*d;
    cout <<"Произведение "; s1.putsterling(); cout <<" на " <<d <<" равно: "; s.putsterling(); cout <<endl;
    s=s1/s2;
    cout <<"Деление "; s1.putsterling(); cout <<" на "; s2.putsterling();  cout <<" равно: "; s.putsterling(); cout <<endl;
    s=s1/d;
    cout <<"Деление "; s1.putsterling(); cout <<" на " <<d <<" равно: "; s.putsterling(); cout <<endl;
    system("pause>>void");
    return 0;
}
