#include <iostream>
#include <string>
#include <iomanip>
// #include <stdlib.h>

using namespace std;

int main() {
  int h;
  int m;
  int d;
  cin >> h >> m;
  cin >> d;

  m += d; 
  h = ( h + m / 60 ) % 24;
  m %= 60;

  cout << setw(2) << setfill('0') << h << " ";
  cout << setw(2) << setfill('0') << m << endl;
  return 0;
}