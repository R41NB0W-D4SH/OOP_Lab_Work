#include <iostream>

using namespace std;

enum etype {laborer, secretary, manager, accountant, executive, researcher};

int main()
{
    setlocale (0, "");
    char ch;
    etype sm;
    cout <<"Введите первую букву должности (laborer, secretary, manager, accountant, executive, researcher) : ";
    cin >>ch;
    switch(ch)
    {
    case 'l': sm = laborer; break;
    case 's': sm = secretary; break;
    case 'm': sm = manager; break;
    case 'a': sm = accountant; break;
    case 'e': sm = executive; break;
    case 'r': sm = researcher; break;
    }
    cout <<"Полное название должности: ";
    switch(sm)
    {
    case 0: cout <<"laborer"; break;
    case 1: cout <<"secretary"; break;
    case 2: cout <<"manager"; break;
    case 3: cout <<"accountant"; break;
    case 4: cout <<"executive"; break;
    case 5: cout <<"researcher"; break;
    }

    cout << endl;

    system ("pause");
    return 0;
}
