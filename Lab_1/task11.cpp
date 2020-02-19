#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    setlocale (0, "");

    cout << "Фамилия" << setw(6) << "Имя" << setw(12) << "Адрес" << setw(14) << "Город" << endl;
    cout << endl << setiosflags(ios::left) << setw(10) << "Петров" << setw(10) << "Василий" << setw(16) << "Кленовая 16" << setw(16) << "Санкт-Петербург" << endl <<
    setw(10) << "Иванов" << setw(10) << "Сергей" << setw(16) << "Осиновая 3" << setw(16) << "Находка" << endl <<
    setw(10) << "Сидоров" << setw(10) << "Иван" << setw(16) << "Березовая 21" << setw(16) << "Калининград" << endl;

	system("pause");
	return 0;
}
