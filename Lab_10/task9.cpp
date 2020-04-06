#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stdafx.h"
#include "msoftcon.h"
using namespace std;
const int CPF = 5;
const int maxHorses = 7;

class comtrack;

class comhorse
{
    private:
        const comtrack* ptrcTrack;
        const int horse_number;
        float finish_time;
        float distance_run;
    public:
        comhorse (const int n, const /*track* ptrT*/ comtrack* ptrcT):
        horse_number ( n ),
        ptrcTrack ( ptrcT ),
        distance_run ( 0.0 )
            {}
        void horse_tick ();
        float get_distance_run()
        {return distance_run;}
        void display_comhorse ( const float elapsed_time );
};
///////////////////////////////////////////////////////////
class comtrack
{
    private:
        comhorse* hArray [ maxHorses ];
        int total_horses;
        int horse_count;
        const float track_length;
        float elapsed_time;
    public:
        //comtrack();
        comtrack(float lenT, int nH):
        track_length ( lenT ),
        total_horses ( nH ),
        horse_count ( 0 ),
        elapsed_time ( 0.0 )
        {
            init_graphics ( );
            total_horses = ( total_horses > maxHorses ) ? maxHorses : total_horses; //проверка на количество лошадей
            for ( int j = 0; j < total_horses; j++ )
                hArray [ j ] = new comhorse ( horse_count++, this );
            time_t aTime;
            srand ( static_cast<unsigned>( time ( &aTime ) ) );  //генерирует псевдослучайные числа в зависимости от времени
            display_comtrack ( );                                   //начинает рисовать трек
        }
        ~comtrack ( )
        {}
        void comrun ( );
        void display_comtrack ( );
        float get_comtrack_len ( ) const;
        //friend void horse_tick ( int, comhorse*  );
};
//-----------------------------------------------------------
void comhorse::display_comhorse ( float elapsed_time )
{
  set_cursor_pos ( 1 + int ( distance_run * CPF ), 2 + horse_number * 2 );
  set_color ( static_cast<color>( cBLUE + horse_number ) );
  char horse_char = '0' + static_cast<char>( horse_number );
  _putch ( ' ' );    // выводит на экран символы
  _putch ( '\xDB' ); 
  _putch ( horse_char ); 
  _putch ( '\xDB' );
  if ( distance_run < ptrcTrack->get_comtrack_len ( ) + 1.0 / CPF )
  {       //работает пока пробег!=длинне трека
    if ( rand ( ) % 3 )  //в диапазоне от 0 до 3
      distance_run += 0.2F;//если совпадает, лошадь продвигается на 0.2
    finish_time = elapsed_time;  //учитывает время потраченное лошадью на забег
  }
  else
  {
    int mins = int ( finish_time ) / 60;
    int secs = int ( finish_time ) - mins * 60;
    cout << " Time = " << mins << ":" << secs;
  }
}
//-----------------------------------------------------------
void comtrack::display_comtrack ( ) //отображает вертикальные полоски
{
  clear_screen ( );           //очищает консоль
 
  for ( int f = 0; f <= track_length; f++ )  //рисует вертикальную полосоку 
    for ( int r = 1; r <= total_horses * 2 + 1; r++ ) //в зависимости от 
    {                                                 //количества лошадей   
      set_cursor_pos ( f * CPF + 5, r );
      if ( f == 0 || f == track_length )
        cout << '\xDE';  //толстые полоски
      else
        cout << '\xB3';  //тонкие полоски
    }
}
//-----------------------------------------------------------
float comtrack::get_comtrack_len ( ) const
  { return track_length; }
//-----------------------------------------------------------
void comtrack::comrun ( )      //перемещает лошади по экрану
{                        //и отображает 
   while ( !_kbhit ( ) )  //цикл будет выполняться, пока не нажата клавиша клавиатуры
  {
    elapsed_time += 1.75; //затраченное время
 
    for ( int j = 0; j < total_horses; j++ )
    {
      int z = 0;
      hArray [ j ]->display_comhorse ( elapsed_time );
      if ( hArray [ j ]->get_distance_run() > track_length / 2.01 &&
           hArray [ j ]->get_distance_run() < track_length / 1.9  )
            for ( int k = 0;  k <total_horses; k++)
            {
                if (hArray [ j ]->get_distance_run() >= hArray [ k ]->get_distance_run())
                {
                    z++;
                    if (z==total_horses)
                        hArray [ j ]->horse_tick ();
                }
            }   
    }
    wait ( 500 ); //после прорисовки лошадей ждет 500 
  }
  _getch ( );   //возвращает очередной символ, считанный с консоли, но не выводит этот сим*вол на экран
  cout << endl;
}
///////////////////////////////////////////////////////////
void comhorse::horse_tick ()
{
    set_cursor_pos ( 1 + int ( distance_run * CPF ), 2 + horse_number * 2 );
    set_color ( static_cast<color>( cBLUE + horse_number ) );
    char horse_char = '0' + static_cast<char>( horse_number );
    distance_run += 0.35F;//если совпадает, лошадь продвигается на 0.2
    _putch ( '   ' );    // выводит на экран символы
    _putch ( '\xDB' ); 
    _putch ( horse_char ); 
    _putch ( '\xDB' );
}
///////////////////////////////////////////////////////////
 
int main ( )
{
  //setlocale (LC_ALL, "russian");
  float length;
  int total;
 
  cout << "\nVvedite dlinnu distancii (ot 1 do 12): ";
  cin >> length;
  //length = 5;
  cout << "\nVvesite kolichestvo loshadei (ot 1 do 7): ";
  cin >> total;
  //total = 3;
  comtrack theTrack ( length, total );
  theTrack.comrun ( );
 
  system("Pause");
  return 0;
}
