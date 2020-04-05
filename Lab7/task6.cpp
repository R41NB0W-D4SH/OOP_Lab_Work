///////////////////////////////////////////////////////////////
class Time
{
private:
    int hrs;
    int min;
    int sec;
public:
    Time(): hrs(0), min(0), sec(0) {}
    Time(int(h), int(m), int(s)): hrs(h), min(m), sec(s) {}
    void show()const
    {
        cout <<"Время: ";
        if(hrs<10){cout <<"0";}
        cout <<hrs <<":";
        if(min<10){cout <<"0";}
        cout <<min <<":";
        if(sec<10){cout <<"0";}
        cout <<sec <<endl;}
    Time operator+(Time T2)const
    {
        int h=hrs+T2.hrs;
        int m=min+T2.min;
        if(m>=60) {h++; m-=60;}
        int s=sec+T2.sec;
        if(s>=60) {m++; s-=60;}
        return Time(h,m,s);
    }
    Time operator-(Time T2)const
    {
        int h=hrs-T2.hrs;
        int m=min-T2.min;
        if(m<0) {h--; m+=60;}
        int s=sec-T2.sec;
        if(s<0) {m--; s+=60;}
        return Time(h,m,s);
    }
    Time operator*(Time T2)const
    {
        int h=hrs*T2.hrs;
        int m=min*T2.min;
        if(m>=60) {h+=m/60; m%=60;}
        int s=sec*T2.sec;
        if(s>=60) {m+=s/60; s%=60;}
        return Time(h,m,s);
    }
    Time operator++()
    {
        ++hrs;
        ++min;
        if(min>=60){hrs++; min-=60;}
        ++sec;
        if(sec>=60){min++; sec-=60;}
        return Time(hrs,min,sec);
    }
    Time operator--()
    {
        --hrs;
        --min;
        if(min<0){hrs--; min+=60;}
        --sec;
        if(sec<0){min--; sec+=60;}
        return Time(hrs,min,sec);
    }
    Time operator++(int)
    {
        hrs++;
        min++;
        if(min>=60){hrs++; min-=60;}
        sec++;
        if(sec>=60){min++; sec-=60;}
        return Time(hrs,min,sec);
    }
    Time operator--(int)
    {
        hrs--;
        min--;
        if(min<0){hrs--; min+=60;}
        sec--;
        if(sec<0){min--; sec+=60;}
        return Time(hrs,min,sec);
    }
 
};
////////////////////////////////////////////////////////////////
 
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    const Time t1(10, 15, 45);
    const Time t2(1, 58, 22);
    Time t;
    t=t1+t2;
    t.show();
    ++t;
    t.show();
    t++;
    t.show();
    --t;
    t.show();
    t--;
    t.show();
    t=t1-t2;
    t.show();
    t=t1*t2;
    t.show();
    system("pause");
    return 0;
}
