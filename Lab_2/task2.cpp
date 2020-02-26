#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int response;
    double temper;

   cout << "1 - для перевода температуры из градусов Фаренгейта в Цельсия,"
	<< "\n2 - для перевода температуры из градусов Цельсия в Фаренгейт : ";

   cin >> response;

   if( response == 1 )
      {
      cout << "Введите температуру в Фаренгейтах : ";
      cin >> temper;
      cout << "В градусах Цельсия : " << 5.0/9.0*(temper-32.0);
      }
   else
      {
      cout << "Введите температуру в Цельсиях : ";
      cin >> temper;
      cout << "В градусах Фаренгейта : " << 9.0/5.0*temper + 32.0;
      }

   cout << endl;

   system("pause");
   return 0;
}
