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
    void putdata()const
    {
        cout <<"\nНазвание книги: " <<name;
        cout <<"\nЦена книги: " <<price;
    }
};
////////////////////////////////////////////////////////////////
class publication2: private publication
{
private:
    int month, day, year;
public:
    char ch;
    publication2(){month=0, day=0, year=0;}
    publication2(int mn, int dy, int yr, string n, float p):month(mn), day(dy), year(yr), publication(n, p)
    {}
    void getdata()
    {
        publication::getdata();
        cout <<"Введите дату издания книги (мм/дд/гггг): ";
        cin >>month >>ch >>day >>ch >>year;
    }
    void putdata()const
    {
        publication::putdata();
        cout <<"\nДата издания книги: " <<month <<ch <<day <<ch <<year;
    }
 
};
///////////////////////////////////////////////////////////////
class book:private publication2
{
private:
    int number_pages;
public:
    book():publication2(), number_pages(0)
    {}
    book(int np, int mn, int dy, int yr, string n, float p):number_pages(np), publication2(mn, dy, yr, n, p)
    {}
    void getdata()
    {
        publication2::getdata();
        cout <<"Введите количество страниц: "; cin >>number_pages;
    }
    void putdata()const
    {
        publication2::putdata();
        cout <<"\nКоличество страниц: " <<number_pages;
    }
};
////////////////////////////////////////////////////////////////
class type:private publication2
{
private:
    float time_rec;
public:
    type():publication2(), time_rec(0.0)
    {}
    type(float tr, int mn, int dy, int yr, string n, float p):time_rec(tr), publication2(mn, dy, yr, n, p) 
    {}
    void getdata()
    {
        publication2::getdata();
        cout <<"Введите время записи аудиокниги в минутах: "; cin >>time_rec;
    }
    void putdata()const
    {
        publication2::putdata();
        cout <<"\nВремя записи аудиокниги в минутах: " <<time_rec;
    }
};
////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    book b;
    type t;
    cout <<"\nВведите данные на книгу";
    b.getdata();
    cout <<"\nВведите данные на аудиокнигу";
    t.getdata();
    cout <<"\nДанные на книгу";
    b.putdata();
    cout <<"\nДанные на аудиокнигу";
    t.putdata();
    cout <<endl;
    system("pause");
    return 0;
}
