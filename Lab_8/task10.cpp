using namespace std;
const int LEN=80;
////////////////////////////////////////////////////////////////////
class student//сведения об образовании
{
private:
    char scool[LEN];//название учебного заведения
    char degree[LEN];//уровень образования
public:
    void getedu()
    {
        cout <<"Введите название учебного заведения: "; cin >>scool;
        cout <<"Введите степень высшего образования: "; cin >>degree;
    }
    void putedu()
    {
        cout <<"\nУчебное заведение: " <<scool;
        cout <<"\nУченая степень: " <<degree;
    }
};
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
class manager:private employee, private student//менеджер
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
        student::getedu();
    }
    void putdata()
    {
        employee::putdata();
        cout <<"\nДолжность: " <<title;
        cout <<"\nСумма взносов в гольф-клуб: " <<dues;
        student::putedu();
    }
};
///////////////////////////////////////////////////////////////////
class scientist:private employee, private student
{
private:
    int pubs;//количество публикаций
public:
    void getdata()
    {
        employee::getdata();
        cout <<"Введите количество публикаций: "; cin >>pubs;
        student::getedu();
    }
    void putdata()
    {
        employee::putdata();
        cout <<"\nКоличество публикаций: " <<pubs;
        student::putedu();
    }
};
//////////////////////////////////////////////////////////////////
class laborer:public employee//класс рабочий
{
};
//////////////////////////////////////////////////////////////////
class foreman:public laborer//бригадир
{
private:
    float quotas;//норма выработки
public:
    void getdata()
    {
        laborer::getdata();
        cout <<"Введите норму выработки: "; cin >>quotas;
    }
    void putdata()
    {
        laborer::putdata();
        cout <<"Норма выработки: " <<quotas;
    }
};
//////////////////////////////////////////////////////////////////
class executive:private manager
{
private:
    double yr_bonus;
    int n_of_shares;
public:
    void getdata()
    {
        manager::getdata();
        cout <<"Введите годовую премию: "; cin >>yr_bonus;
        cout <<"Введите количество акций: "; cin >>n_of_shares;   
    }
    void putdata()
    {
        manager::putdata();
        cout <<"\nГодовая премия: " <<yr_bonus;
        cout <<"\nКоличество акций: " <<n_of_shares;
    }
};
///////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL,"");
    manager m1;
    scientist s1;
    laborer l1;
    executive ex1;
    //введем информацию о нескольких сотрудниках
    cout <<endl;
    cout <<"Ввод информации о первом менеджере: ";
    m1.getdata();
    cout <<"Ввод информации о первом ученом: ";
    s1.getdata();
    cout <<"Ввод информации о первом рабочем: ";
    l1.getdata();
    cout <<"Ввод информации о управляющем: ";
    ex1.getdata();
 
    //выведем полученую информацию на экран
    cout <<"Информации о первом менеджере: ";
    m1.putdata();
    cout <<"Информации о первом ученом: ";
    s1.putdata();
    cout <<"Информации о первом рабочем: ";
    l1.putdata();
    cout <<"Информация о первом управляющем: ";
    ex1.putdata();
    cout <<endl;
    system("pause");
    return 0;
}
