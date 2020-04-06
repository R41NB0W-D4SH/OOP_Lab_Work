#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <process.h>
#include <math.h> 
using namespace std;
static const int MAX = 26;
/////////////////////////////////////////////////////////////
class bMoney
{
  private:
    double longMoney;
  public:
    char chMoney[MAX];
    bMoney ():longMoney(0.0) // конструктор
      {chMoney[0]='$';}
    bMoney (double chislo) // конструктор
      {longMoney=chislo;}
 
    void getMoney ()
        {
            cout << "Введите денежную сумму" << endl;
            cin >> longMoney;
            
        }
    double vozvrat ()
        {
            return longMoney;
        }
    double mstold ( char []);
 
    bMoney operator+ (bMoney m2)
        {return bMoney (longMoney + m2.longMoney);}
 
    bMoney operator- (bMoney m2)
        {return bMoney (longMoney - m2.longMoney);}
 
    bMoney operator* (double d2)
        {return bMoney (longMoney * d2);}
 
    friend bMoney operator* (bMoney m1, bMoney m2)
        {return bMoney (m1.longMoney * m2.longMoney);}
 
    friend bMoney operator/ (bMoney m1, bMoney m2)
        {return bMoney (m1.longMoney / m2.longMoney);}
 
    void display ()
      {
           cout<<fixed<<setprecision(2)<<"$"<<longMoney << endl; 
      }           
    bMoney round();
};
//--------------------------------------------------------------------
    bMoney bMoney::round ()
    {
        double fractpart, intpart;
        fractpart = modf(longMoney, &intpart);
        if (fractpart<0.5)
            longMoney = intpart;
        else longMoney = intpart+1;
        return bMoney(longMoney);
            
 
    }
/////////////////////////////////////////////////////////////
int main ( )
{
  setlocale (LC_ALL, "russian");
  bMoney m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, m11;
  double d1;
  char answer = 'y';
  while (answer!='n')
  {
    d1 = 10;
    m1 = 200.45;
    m2 = 10.55;
    m3 = m1 + m2;
    m4 = m1 - m2;
    m5 = m1 * d1;
    m6 = m1 / m2;
    m7 = m1 / d1;
    m8 = 5.5 * m2;
    m9 = 500 / m1;
    m10 = m1.round();
    m11 = m2.round();
    
    m3.display();
    m4.display();
    m5.display();
    m6.display();
    m7.display();
    m8.display();
    m9.display();
    m10.display();
    m11.display();
 
    cout << "Продолжить ввод?" << endl;
    cin >> answer;
 
  } 
  system("pause");
  return 0;
}
