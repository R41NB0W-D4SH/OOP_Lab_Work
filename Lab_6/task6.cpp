#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };
// от 2 до 10 обычные числа
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;

class card
{
  private:
    int number;
    Suit suit;
  public:
    card ( ) // конструктор
      { }
    void set ( int n, Suit s ) // установка значения
      { suit = s; number = n; }
    void display ( );          // показ карты
};

void card::display ( )
{
  if ( number >= 2 && number <= 10 )
    cout << number;
  else
  {
    switch ( number )
    {
      case jack: cout << 'J'; break;
      case queen: cout << 'Q'; break;
      case king: cout << 'K'; break;
      case ace: cout << 'A'; break;
    }
  }
  switch ( suit )
  {
    case clubs: cout << static_cast<char>( 5 ); break;
    case diamonds: cout << static_cast<char>( 4 ); break;
    case hearts: cout << static_cast<char>( 3 ); break;
    case spades: cout << static_cast<char>( 6 ); break;
  }
}

int main ()
{
  setlocale (0, "");
  card deck [ 52 ];
  const int MAX = 13;
  card p1 [MAX], p2 [MAX], p3 [MAX], p4 [MAX];
  int j;

  cout << endl;
  for ( j = 0; j < 52; j++ )   // создаем упорядоченную колоду карт
  {
    int num = ( j % 13 ) + 2;
    Suit su = Suit ( j / 13 );
    deck [ j ].set ( num, su );
  }
  // показываем исходную колоду
  cout << "Исходная колода:\n";
  for ( j = 0; j < 52; j++ )
  {
    deck [ j ].display ( );
    cout << "  ";
    if ( !( ( j + 1 ) % 13 ) ) // начинаем новую строку после каждой 13-й карты
      cout << endl;
  }
  srand ( time ( NULL ) );     // инициализируем генератор случайных чисел
  for ( j = 0; j < 52; j++ )
  {
    int k = rand ( ) % 52;     // выбираем случайную карту
    card temp = deck [ j ];    // и меняем ее с текущей
    deck [ j ] = deck [ k ];
    deck [ k ] = temp;
  }
  cout << endl;
  int i;
  cout << "После перемешивания.\n"<< endl;;
  cout << "Карты первого игрока:\n";
  for ( j = 0, i = 0; j < 13; i++, j++ )
  {
        p1 [i] = deck [ j ];
        p1 [i].display ( );
        cout << "  ";
  }
  cout << endl;
  cout << "\nКарты второго игрока:\n";
  for ( j = 13, i = 0; j < 26; i++, j++ )
  {
        p2 [i] = deck [ j ];
        p2 [i].display ( );
        cout << "  ";
  }
  cout << endl;
  cout << "\nКарты третьего игрока:\n";
  for ( j = 26, i = 0; j < 39; i++, j++ )
  {
        p3 [i] = deck [ j ];
        p3 [i].display ( );
        cout << "  ";
  }
  cout << endl;
  cout << "\nКарты четвертого игрока:\n";
  for ( j = 39, i = 0; j < 52; i++, j++ )
  {
        p4 [i] = deck [ j ];
        p4 [i].display ( );
        cout << "  ";
  }
  cout << endl;
  system("pause");
  return 0;
}
