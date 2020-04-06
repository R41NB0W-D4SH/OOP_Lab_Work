#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
struct link   // один элемент списка
{
  int data;   // некоторые данные
  link* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////
class linklist // список
{
  private:
    link* first;
    link* last;
  public:
    linklist ( )            // конструктор без параметров
      { first=last = NULL; }     // первого элемента пока нет
    ~linklist()
    {
        link* current=NULL;
        link* next=first;
        while(next)
        {
            current=next;
            next=next->next;
            
            delete current;
        }
        
    }
    void additem ( int d ); // добавление элемента
    void display ( );       // показ данных
};
///////////////////////////////////////////////////////////
void linklist::additem ( int d ) // добавление элемента
{
    link* newlink = new link; // выделяем память
    newlink->next=NULL;
    newlink->data=d;
    if(first==NULL) 
    {
        first=newlink;
        last=newlink;}
    else
    {
        last->next=newlink;
        last=newlink;
    }
  
  
}
///////////////////////////////////////////////////////////
void linklist::display ( )
{
  link* current = first;           // начинаем с первого элемента
  while( current )                 // пока есть данные
  {
    cout << current->data << endl; // печатаем данные
    current = current->next;       // двигаемся к следующему элементу
  }
}
///////////////////////////////////////////////////////////
int main ( )
{
  linklist li;       // создаем переменную-список
 
  li.additem ( 25 ); // добавляем туда несколько чисел
  li.additem ( 36 );
  li.additem ( 49 );
  li.additem ( 64 );
 
  li.display ( );    // показываем список
system("pause");
  return 0;
}
