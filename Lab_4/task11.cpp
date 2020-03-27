#include <iostream>

using namespace std;

struct sterling
{
    int pounds;
    int shillings;
    int pens;
};

sterling entn();
sterling slojn (sterling, sterling);
void printn (sterling);
int main()
{
    setlocale(0, "");
    sterling st1, st2, st3;
    st1 = entn();
    st2 = entn();
    st3 = slojn (st1, st2);
    printn (st3);
    system("pause");
    return 0;
}

sterling entn()
{
  sterling s;
  cout<< "Введите сумму"<<endl;
  cout<< "Введите количество фунтов : ";
  cin>>s.pounds;
  cout<< "Введите количество шиллингов :";
  cin>>s.shillings;
  cout<< "Введите количество пенсов :";
  cin>>s.pens;
  return s;
}

sterling slojn (sterling s1, sterling s2)
{
    sterling s3;
    s3.pens= s1.pens + s2.pens;
    s3.shillings = 0;
    if (s3.pens >= 12)
       {
       s3.pens -= 12;
       s3.shillings++;
       }

    s3.shillings = s3.shillings + s1.shillings + s2.shillings;
    s3.pounds = 0;
    if (s3.shillings >= 20)
       {
       s3.shillings -= 20;
       s3.pounds++;
       }

    s3.pounds = s3.pounds + s1.pounds + s2.pounds;
    return s3;
}

void printn (sterling s)
{
     cout <<"Сумма первых двух значений равна : " << s.pounds<<"."<<s.shillings<<"."<<s.pens<<endl;
}
