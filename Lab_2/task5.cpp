#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (int i = 0; i < 20; i++)
    {
        cout << string(i, 'X') << endl;
    }

    system("pause");
    return 0;
}
