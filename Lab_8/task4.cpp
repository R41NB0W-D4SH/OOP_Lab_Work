using namespace std;
 
///////////////////////////////////////////////////////////////
class publication
{
private:
    string name;
    float price;
public:
    publication():name("N/A"), price(0.0)
    {}
    publication(string n, float p):name(n), price(p)
    {}
    void getdata()
    {
        cout <<"\nВведите название книги: "; cin >>name;
        cout <<"Введите цену книги: "; cin >>price;
    }
    void putdata()
    {
        cout <<"\nНазвание книги: " <<name;
        cout <<"\nЦена книги: " <<price;
    }
};
////////////////////////////////////////////////////////////////
class sales
{
private:
    static const int MAX=3;
    float summ[MAX];
public:
    sales():summ()
    {}
    sales(float su):summ()
    {}
    void getdata()
    {
        for(int j=0; j<MAX; j++){
            cout <<"Введите суммарную прибыль за " <<j+1 <<"-й месяц: ";
            cin >>summ[j];
        }
    }
    void putdata()
    {
        for(int j=0; j<MAX; j++){
            cout <<"\nСуммарная прибыль за " <<j+1 <<"-й месяц: " <<summ[j] <<" рубл.";
        }
    }
};
////////////////////////////////////////////////////////////////
class book:private publication, private sales
{
private:
    int number_pages;
public:
    book():publication(), sales(), number_pages(0)
    {}
    book(string n, float p, int np, float su):publication(n, p), sales(su), number_pages(np)
    {}
    void getdata()
    {
        publication::getdata();
        cout <<"Введите количество страниц: "; cin >>number_pages;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout <<"\nКоличество страниц: " <<number_pages;
        sales::putdata();
    }
};
////////////////////////////////////////////////////////////////
class type:private publication, private sales
{
private:
    float time_rec;
public:
    type():publication(), sales(), time_rec(0.0)
    {}
    type(string n, float p, float tr, float su):publication(n, p), sales(su), time_rec(tr)
    {}
    void getdata()
    {
        publication::getdata();
        cout <<"Введите время записи аудиокниги в минутах: "; cin >>time_rec;
        sales::getdata();
    }
    void putdata()
    {
        publication::putdata();
        cout <<"\nВремя записи аудиокниги в минутах: " <<time_rec;
        sales::putdata();
    }
};
////////////////////////////////////////////////////////////////
class disk:private publication
{
private:
    enum disc_type{cd, dvd};
public:
    disc_type d1;
    char dd;
    void getdata()
    {
        publication::getdata();
        cout <<"Введите тип диска, на котором находится книга(c/d):";
        cin >>dd;
    }
    void putdata()
    {
        publication::putdata();
        if(dd=='c'){d1=cd;}
        if(dd=='d'){d1=dvd;}
        switch (d1){
        case 0: cout <<"\nТип диска CD"; break;
        case 1: cout <<"\nТип диска DVD"; break;
        }
    }
};
////////////////////////////////////////////////////////////////        
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    book b;
    type t;
    disk d;
    cout <<"\nВведите данные на книгу";
    b.getdata();
    cout <<"\nВведите данные на аудиокнигу";
    t.getdata();
    cout <<"\nВведите данные на диск";
    d.getdata();
    cout <<"\nДанные на книгу";
    b.putdata();
    cout <<"\nДанные на аудиокнигу";
    t.putdata();
    cout <<"\nДанные на диск";
    d.putdata();
    cout <<endl;
    system("pause");
    return 0;
}
