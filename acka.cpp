#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

//static vector<vector<unsigned long long int> > vals;

int ack( int m, int n, unsigned long long int &highest)
{
  ++highest;

  /*
  if( vals.size() >= m )
    if( vals[m].size() >= n )
    return vals[m-1][n-1];
    */

  if( m == 0 )
//    vals[m-1].push_back( n + 1 );
    return n + 1;

  if( n == 0 )
    return ack( m - 1, 1, highest);

  return ack( m - 1, ack( m, n - 1, highest), highest);
}

int main(int argc, char* argv[] )
{

  if( argc != 3 )
    cerr << "Program must take to integers as arguments." << endl << endl;

  unsigned long long int height = 0;

  cout << endl << "Ackermann(" << argv[1] << ", " << argv[2] << ") is: " << flush <<  ack( atoi( argv[1] ), atoi( argv[2] ), height) << endl << endl;

  cout << endl << "Function was called, recursively, " << height << " times." << endl;
  return 0;
}
