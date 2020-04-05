#include <iostream>
#include <process.h>
using namespace std;

class matrix
{
  private:
    static const unsigned int row = 10;
    static const unsigned int column = 10;
    int limit [row] [column];
  public:
    void putel ( int, int, int);
    int getel ( int, int );
};

    void matrix::putel ( int i, int j, int k)
      {
            if ((i > 0 && i<row) && (j > 0 && j<column))
                limit [i][j] = k;
            else
                {cout << "Вы вышли за границы массива" << endl; exit (1);}
      }

    int matrix::getel ( int i, int j)
      {
            if ((i > 0 && i<row) && (j > 0 && j<column))
                return limit [i][j];
            else
                {cout << "Вы вышли за границы массива" << endl; exit (1);}
      }

int main ()
{
  setlocale (0, "");
  matrix m1;
  int temp;
  int row, column;
  cout << "Введите значение помещаемое в массив:" << endl;
  cin >> temp;
  cout << "Введите индекс строки :" << endl;
  cin >> row;
  cout << "Введите индекс столбца :" << endl;
  cin >> column;
  m1.putel (row, column, temp);
  temp = m1.getel (row, column);
  cout << temp << endl;
  system("pause");
  return 0;
}
