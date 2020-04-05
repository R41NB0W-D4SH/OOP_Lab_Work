using namespace std;
 
//////////////////////////////////////////////////////////////////
class Stack
{
protected:
    static const int MAX=10;//размер стека
    //enum {MAX=10};
    int st[MAX];//данные, хранящиеся в стеке
    int top;//индекс последнего элемента в стеке
public:
    Stack()//конструктор
    {top=-1;}
    void push(int var)//поместить в стек
    {st[++top]=var;}
    int pop()//взять из стека
    {return st[top--];}
};
/////////////////////////////////////////////////////////////////
class Stack2:public Stack
{
public:
    void push(int var)
    {
        if(top>=MAX-1)//если стек полон, то ошибка
        {cout <<"\nОшибка! Стек полон!"; exit(1);}
        Stack::push(var);//вызов функции push класса Stack
    }
    int pop()//извлечение числа из стека
    {
        if(top<0)//если стек пуст, то ошибка
        {cout <<"\nОшибка! Стек пуст!"; exit(1);}
        return Stack::pop();//вызов функции pop класса Stack
    }
};
//////////////////////////////////////////////////////////////////
class pairStack:private Stack2
{
public:
    void push(int var, int var2)
    {
        Stack2::push(var);
        Stack2::push(var2);
    }
    void pop()
    {cout <<Stack2::pop() <<" " <<Stack2::pop() <<endl;}
};
//////////////////////////////////////////////////////////////////
int _tmain(int argc, _TCHAR* argv[])
{
    pairStack ps;
    ps.push(11, 12);
    ps.push(21, 22);
    ps.push(31, 32);
    ps.pop();
    ps.pop();
    ps.pop();
    system("pause");
    return 0;
}
