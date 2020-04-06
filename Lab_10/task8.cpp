#include <iostream>
#include <cstring>                   //for strlen(), etc
#include <stdlib.h> 
using namespace std;
const int LEN = 80;    //length of expressions, in characters
const int MAX = 40;    //size of stack
////////////////////////////////////////////////////////////////
  class Token                      // Абстрактный базовый класс
    {
    public:
      virtual void showOperNumber()=0; // чистая виртуальная
      virtual char getOperator()=0;             // функция
      virtual float getNumber()=0; 
 
      
    };
////////////////////////////////////////////////////////////////
  class Operator : public Token
    {
    private:
      char oper;             // Операторы +, –, *, /
    public:
      Operator(char c): oper(c)      // конструктор устанавливает значение
        {}
      void showOperNumber()    // получить значение
        {cout<<oper<<endl; }
      virtual float getNumber()
        { return 0.f; }
      char getOperator()
        {return oper;}
     
    };
////////////////////////////////////////////////////////////////
  class Number : public Token
    {
    private:
      float fnum;            // число
    public:
      Number(float f): fnum(f)         // конструктор устанавливает значение
         {}
      void showOperNumber()     // получить значение
        {cout<<fnum<<endl;}
      float getNumber()
        {return fnum;}
      virtual char getOperator()
        { return 0.f; }
    };
////////////////////////////////////////////////////////////////////
class Stack
   {
   private:
      Token* atoken[100];    //содержит типы Operator* и Number*                  
      int top;                       //number of top of stack
   public:
      Stack()                        //constructor
         { top = 0; }
      void push(Token* var)            //put char on stack
         { atoken[++top] = var; }
      Token* pop()                     //take char off stack
         { return atoken[top--]; }
      int gettop()                   //get top of stack
         { return top; }
   };
////////////////////////////////////////////////////////////////
class express
{
    private:
        Stack s;
        char* pStr;
        int len;
    public:
        express (char* ptr)
        {
            pStr=ptr;
            len =strlen(pStr);
        }
        void parse ();     // разбор выражения
        float solve ();      // получение результата
};
//--------------------------------------------------------------
void express::parse()
{
    char chifra [LEN];    //символы из строки
    float lastval;        // последнее значение
    char lastop;          // последний оператор
    Number* ptrN;
    Operator* ptrO;
    float n;
    char Ch;  
    int j=0;
     
 
    for(j; j<len; j++)          //для всех символов в строке
    {
        if (pStr[j]>='0' && pStr[j]<='9' || pStr[j]==',')
        {
            int i=0;
            while (pStr[j]>='0' && pStr[j]<='9' || pStr[j]==',')  // получаем число 
            {
                chifra [i]=pStr[j];
                j++; i++;
            }
            j--;
            chifra [i]='\0';
            n = atof(chifra);
            ptrN = new Number(n);
            s.push(ptrN);                                       // заносим  в стек
        }
        else if(pStr[j]=='+' || pStr[j]=='-' || pStr[j]=='*' || pStr[j]=='/')
        {
            Ch = pStr[j];
            if (s.gettop()==1)                                    // если это первый оператор, то помещаем в стек
            {
                ptrO = new Operator(Ch);
                s.push(ptrO);   
            }
            else
            {
                lastval=s.pop()->getNumber();                //получение предыдущего числа
                lastop=s.pop()->getOperator();              //получение предыдущего оператора
                // если это * или / , а предыдущий был + или -, то
                if( (pStr[j]=='*' || pStr[j]=='/') && (lastop=='+' || lastop=='-') )
                {
                    ptrO = new Operator(lastop);   //отменяем последние два взятия из стека
                    s.push(ptrO);   
                    ptrN = new Number(lastval);
                    s.push(ptrN);   
               }
               else                     //помещаем в стек текущий оператор 
               {
               switch(lastop)        
                  {                  
                  case '+': ptrN = new Number(s.pop()->getNumber() + lastval); s.push(ptrN); break;
                  case '-': ptrN = new Number(s.pop()->getNumber() - lastval); s.push(ptrN); break;
                  case '*': ptrN = new Number(s.pop()->getNumber() * lastval); s.push(ptrN); break;
                  case '/': ptrN = new Number(s.pop()->getNumber() / lastval); s.push(ptrN); break;
                  default:  cout << "\nUnknown oper"; exit(1);
                  }  
               }  
            ptrO = new Operator(pStr[j]);
            s.push(ptrO);              //помещаем в стек текущий оператор 
            }  
         }  
   
      else                           //что-то левое
         { cout << "\nUnknown input character"; exit(1); }
   }
}
//-------------------------------------------------------------
float express::solve ()  //убираем данные из стека
{
    float lastval;              
    while(s.gettop() > 1)
      {
      lastval = s.pop()->getNumber();               //предыдущее значение 
      Number* ptrN;
      switch( s.pop()->getOperator() )              //получение предыдущего оператора
         {                           //do operation, push answer
         case '+': ptrN = new Number(s.pop()->getNumber() + lastval); s.push(ptrN); break;
         case '-': ptrN = new Number(s.pop()->getNumber() - lastval); s.push(ptrN); break;
         case '*': ptrN = new Number(s.pop()->getNumber() * lastval); s.push(ptrN); break;
         case '/': ptrN = new Number(s.pop()->getNumber() / lastval); s.push(ptrN); break;
         default:  cout << "\nUnknown operator"; exit(1);
         }  
      }  
   return float (s.pop()->getNumber());//последний оператор в стеке это результат
}
////////////////////////////////////////////////////////////////
 
int main()
   {
   setlocale (LC_ALL, "russian");
   char ans;            // 'д' или 'н'
   //char stroka [LEN]="12,05+13,05+14,05*2";                          //char from input string
   char stroka [LEN];
   cout << "\nВведите арифметическое выражение в виде 2+3*4/3-2"
          "\nЧисла должны быть из одной цифры"
          "\nНе используйте пробелы и скобки";
 
   do
   {
       cout << "\nВыражение: ";
       cin >> stroka;                          // вводим строку
       express* eptr = new express (stroka);
       eptr->parse();
       cout <<"\nРезультат: "
           << eptr->solve();
       delete eptr;
       cout << "Еще одно выражение (y/n)? ";
    cin >> ans;
   }
   while ( ans == 'y' );
   system("pause");
   return 0;
   }
