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
  public:
    linklist ( )            // конструктор без параметров
      { first = NULL; }     // первого элемента пока нет
    ~linklist();
    void additem ( int d ); // добавление элемента
    void display ( );       // показ данных
    void operator = (linklist& ); //оператор присваивания
    linklist(linklist&);          //оператор копирования
};
///////////////////////////////////////////////////////////
void linklist::additem ( int d ) // добавление элемента
{
  link* newlink = new link;      // выделяем память
  newlink->data = d;             // запоминаем данные
  newlink->next = first;         // запоминаем значение first
  first = newlink;               // first теперь указывает на новый элемент
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
linklist::~linklist()
    {
        link*current =first;   //установить указатель на первый элемент
        while(current !=NULL ) //выход по достижении последнего элемента
        {
            link*temp =current;  //сохранить указатель на данный элемент
            current =current->next;  //получить ссылку на следующую ссылку
            cout<<"Удаляем"<<endl;
            delete temp;               //удалить эту ссылку
      }
    }
///////////////////////////////////////////////////////////
void linklist::operator = (linklist& l1) //оператор присваивания
{
    link*current =l1.first;   //установить указатель на первый элемент
    while(current !=NULL ) //выход по достижении последнего элемента
        {
            link* newlink = new link;
            newlink->data = current->data;  //сохранить указатель на данный элемент
            newlink->next =first;
            first = newlink;
            current =current->next;  //получить ссылку на следующую ссылку
        }
    cout<<"Оператор присваивания.";
}
///////////////////////////////////////////////////////////
linklist::linklist(linklist& l1)
{
    first = NULL;
    link*current =l1.first;   //установить указатель на первый элемент
    while(current !=NULL ) //выход по достижении последнего элемента
        {
            link* newlink = new link;
            newlink->data = current->data;  //сохранить указатель на данный элемент
            newlink->next =first;
            first = newlink;
            current =current->next;  //получить ссылку на следующую ссылку
        }
      cout<<"Оператор копирования.";
}
 
///////////////////////////////////////////////////////////
int main ( )
{
  setlocale (LC_ALL, "russian");
  linklist* li = new linklist;       // создаем переменную-список
  linklist* list2 = new linklist;
 
  li->additem ( 25 ); // добавляем туда несколько чисел
  li->additem ( 36 );
  li->additem ( 49 );
  li->additem ( 64 );
 
  *list2 = *li; 
  linklist list3 (*li) ;                      // для указателей операторы не перегрузишь, с шаблонами или без них... 
                      // в общем, указатели так и так разыменовывать, 
                      //а для класса можно перегрузить почти любые операторы. 
  delete  li;     
  //li->display ( );    // показываем список
  list2->display ( );    // показываем список
  list3.display ( );    // показываем список
  cout<<"Завершение программы.";
  system("pause");
  return 0;
}
