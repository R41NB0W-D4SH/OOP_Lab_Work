using namespace std;
const int LEN=80;
////////////////////////////////////////////////////////////////////
class employee
{
private:
    char name[LEN];//имя сотрудника
    unsigned long number;//номер сотрудника
public:
    void getdata()
    {
        cout <<"\nВведите фамилию: "; cin >>name;
        cout <<"Введите номер: "; cin >>number;
    }
    void putdata()
    {
        cout <<"\nФамилия: " <<name;
        cout <<"\nНомер: " <<number;
    }
};
///////////////////////////////////////////////////////////////////
class compensation
{
private:
    double compensations;
    enum period{hrs, week, mnts};
public:
    period per;
    char ch;
    void getdata()
    {
        cout <<"Введите вознаграждение за работу: "; cin >>compensations;
        cout <<"Введите тип оплаты (h/w/m)"; cin >>ch;
    }
    void putdata()
    {
        cout <<"\nВознаграждение за работу составляет: " <<compensations <<" руб.";
        cout <<"\nТип оплаты: ";
        if(ch=='h'){per=hrs;}
        else if(ch=='w'){per=week;}
        else if(ch=='m'){per=mnts;}
        switch(per){
        case 0: cout <<"почасовая"; break;
        case 1: cout <<"еженедельная"; break;
        case 2: cout <<"ежемесячная"; break;
        }
    }
};
///////////////////////////////////////////////////////////////////
class manager:public employee//менеджер
{
private:
    char title[LEN];//должность, например вице-президент
    double dues;//сумма взносов в гольф-клуб
public:
    void getdata()
    {
        employee::getdata();
        cout <<"Введите должность: "; cin >>title;
        cout <<"Введите сумму взносов в гольф-клуб: "; cin >>dues;
    }
    void putdata()
    {
        employee::putdata();
        cout <<"\nДолжность: " <<title;
        cout <<"\nСумма взносов в гольф-клуб: " <<dues;
    }
};
///////////////////////////////////////////////////////////////////
class scientist:public employee
{
private:
    int pubs;//количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        cout <<"Введите количество публикаций: "; cin >>pubs;
    }
    void putdata()
    {
        employee::putdata();
        cout <<"\nКоличество публикаций: " <<pubs;
    }
};
//////////////////////////////////////////////////////////////////
class laborer:public employee//класс рабочий
{
};
//////////////////////////////////////////////////////////////////
class manager2: private manager, private compensation
{
public:
    void getdata()
    {
        manager::getdata();
        compensation::getdata();
    }
    void putdata()
    {
        manager::putdata();
        compensation::putdata();
    }
};
/////////////////////////////////////////////////////////////////
class scientist2: private scientist, private compensation
{
public:
    void getdata()
    {
        scientist::getdata();
        compensation::getdata();
    }
    void putdata()
    {
        scientist::putdata();
        compensation::putdata();
    }
};
//////////////////////////////////////////////////////////////////
class laborer2: private laborer, private compensation
{
public:
    void getdata()
    {
        laborer::getdata();
        compensation::getdata();
    }
    void putdata()
    {
        laborer::putdata();
        compensation::putdata();
    }
};
//////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    manager2 m1, m2;
    scientist2 s1;
    laborer2 l1;
    //введем информацию о нескольких сотрудниках
    cout <<endl;
    cout <<"Ввод информации о первом менеджере";
    m1.getdata();
    cout <<"\nВвод информации о втором менеджере";
    m2.getdata();
    cout <<"\nВвод информации о первом ученом";
    s1.getdata();
    cout <<"\nВвод информации о первом рабочем";
    l1.getdata();
    //выведем полученую информацию на экран
    cout <<"\nИнформация о первом менеджере";
    m1.putdata();
    cout <<"\nИнформация о втором менеджере";
    m2.putdata();
    cout <<"\nИнформация о первом ученом";
    s1.putdata();
    cout <<"\nИнформация о первом рабочем";
    l1.putdata();
    system("pause");
    return 0;
}
