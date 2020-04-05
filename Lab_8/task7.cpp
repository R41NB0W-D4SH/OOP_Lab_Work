using namespace std;
 
//////////////////////////////////////////////////////////////////
class Counter//базовый класс
{
protected:
    unsigned int count;//счетчик
public:
    Counter():count(0)
    {}
    Counter(int c):count(c)
    {}
    unsigned int get_count()const
    {return count;}//возвращает з начение счетчика
    Counter operator++()//увеличивает значение счетчика
    {return Counter(++count);}
 
};
////////////////////////////////////////////////////////////////
class CountDn:public Counter//производный класс
{
public:
    CountDn():Counter()//конструктор без параметров
    {}
    CountDn(int c):Counter(c)//конструктор с одним параметром
    {}
    CountDn operator--()//уменьшает значение счетчика
    {return CountDn(--count);}
};
////////////////////////////////////////////////////////////////
class CountPosx:public CountDn
{
public:
    CountPosx():CountDn()
    {}
    CountPosx(int c):CountDn(c)
    {}
    CountDn::operator++;
    CountDn::operator--;
    CountPosx operator++(int)
    {return CountPosx(count++);}
    CountPosx operator--(int)
    {return CountPosx(count--);}
};
////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    CountPosx c1;//объекс с1
    CountPosx c2(100);
    cout <<"\n c1=" <<c1.get_count();//вывод на печать
    cout <<"\n c2=" <<c2.get_count();//вывод на печать
    ++c1; ++c1; c1++;//увеличиваем три раза с1
    cout <<"\n c1=" <<c1.get_count();//выводим на печать
    --c2; --c2;//уменьшаем два раза с2
    cout <<"\n c2=" <<c2.get_count();//выводим на печать
    CountDn c3=c2--;//создаем переменную с3 на основе с2
    cout <<"\n c3=" <<c3.get_count();//выводим на печать
    cout <<endl;
    system("pause");
    return 0;
}
