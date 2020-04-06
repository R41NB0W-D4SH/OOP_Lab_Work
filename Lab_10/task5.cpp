#include <iostream>
using namespace std;
const int LEN = 80;
////////////////////////////////////////////////////////////////////////////////
class publication
{
   private:
       char name[LEN]; 
       float price;
   public:
    virtual void getdata ()
      {
            cout<<"\nВведите имя: ";  cin>>name; 
            cout<<"Введите цену: "; cin>>price; 
      } 
    virtual void putdata ()
      {
            cout<<"\n Название: "<<name;   
            cout<<"\n Цена: "<<price; 
      } 
    virtual bool isOverersize()=0;
};
////////////////////////////////////////////////////////////////////////////////
class book: public publication
{
   private:
       int pages; 
   public:
    void getdata ()
      {
            publication::getdata();
            cout<<"Введите количество страниц: ";  cin>>pages; 
      } 
    void putdata ()
      {
            publication::putdata();
            cout<<"\n Количество страниц: "<<pages;   
      }
    virtual bool isOverersize()
      {return (pages>800)? true : false;}
};
////////////////////////////////////////////////////////////////////////////////
class type: public publication
{
   private:
       float min; 
   public:
    void getdata ()
      {
            publication::getdata();
            cout<<"Введите длительность аудиозаписи в минутах: ";  cin>>min; 
      } 
    void putdata ()
      {
            publication::putdata();
            cout<<"\n Общая длительность в минутах: "<<min;   
      } 
    virtual bool isOverersize()
      {return (min>90)? true : false;}
};
////////////////////////////////////////////////////////////////////////////////
int main()
{
setlocale (LC_ALL, "russian");
publication* pointer[100];
int n = 0;
char choice;
do {
    cout<<"Книга (b) или запись (r)?  ";
    cin>>choice;
    if (choice=='b')
        pointer[n]=new book;
    else
        pointer[n]=new type;
    pointer[n++]->getdata();
    cout<<"Продолжить ввод (y/n)? ";
    cin>>choice;
    } while (choice=='y');
for (int j=0; j<n; j++)
    {
    pointer[j]->putdata ();
    if(pointer[j]->isOverersize ())
        cout<<"Превышение размера! ";
    }
system("Pause");
return 0;
}
