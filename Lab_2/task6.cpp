#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    unsigned int n;
    unsigned long fact = 1;

   do//Для цикличного спроса чисел, и высчитывания факториалов
   {
        cout << "Введите число: ";
        cin >> n;
        if (n > 0)
        {
            for (int j = n; j > 0; j--)//Высчитывает факториал
            {
                fact *= j;
            }
            cout << "Факториал : " << fact << endl;
            fact = 1;
        }
        else return 0;//Условие выхода из цикла, если переменная == ноль
   }
   while (fact > 0);

   system("pause");
   return 0;
}
