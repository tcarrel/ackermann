
#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

const int MAX_N = 14;
const int M_STOP = 7;

int ack( int m, int n )
{
  if( m == 0 )
    return n + 1;
  if( n == 0 )
    return ack( m - 1, 1 );

  return ack( m - 1, ack( m, n - 1 ) );
}

int main(int argc, char* argv[] )
{

  char qq = 34;
  cout << endl << "Demonstration of the Ackermann Functions:" << endl;
  cout << "-----------------------------------------" << endl;
  cout << "  This is the code for the Ackermann Function:" << endl << endl;
  cout << "int ack( int m, int n )" << endl;
  cout << "{" << endl;
  cout << "  if( m == 0 )" << endl;
  cout << "    return n + 1;" << endl;
  cout << "  if( n == 0 )" << endl;
  cout << "    return ack( m - 1, 1 ); //recursion" << endl;
  cout << endl;
  cout << "  return ack( m - 1, ack( m, n - 1 ) ); //really bad recursion" << endl;
  cout << "}";
  cout << endl << endl;
  cout << "This program automatically skips values that will take " << qq << "a really long" << qq << " time to calculate." << endl << endl;

  cout << "Ackermann( m, n ): " << endl;
  cout << string( (MAX_N + 2) * 10 + 1, '=') << endl;

  cout << "|" << setw(8) << "| m  n->" << "||";
  for( int q = 0; q <= MAX_N; ++q)
  {
    cout << setw(5) << q << "    |";
  }

  cout << endl << "++ | +===++";

  int prev = 0;

  for( int x = 0; x <= MAX_N ; ++x)
    cout << string(9, '=') << "+"; 
  cout << endl;

  for( int i = 0; i <= M_STOP; ++i)
  {
    prev = 0;
    cout << "|";
    if( !i )
      cout << setw(10) << "| v | 0 ||";
    else
      cout << setw(5) << i << "   ||";

    cout << flush;
    for ( int j = 0; j <= MAX_N; ++j)
    {
      cout << setw(8);

      if( prev > 40000 || 5 < i )
        cout << string(7, ' ');
      else
      {
        prev = ack( i, j );
        cout << prev;
      }

//      prev_calcs[j][i] = prev;
      cout << " |" << flush;
    }
    cout << endl << "+";
    if ( !i )
    {
      cout << "+---+---++";
      for( int x = 0; x <= MAX_N; ++x)
        cout << string(9, '-') <<  "+" ;
    }
    else
      for( int x = 0; x <= MAX_N + 1; ++x)
        cout << ( x == 0 ? "--------++" : "---------+" ); 
    cout << endl;
  }

  return 0;
}
