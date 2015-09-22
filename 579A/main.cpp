#include <iostream>

using namespace std;

int main() {
  long x;
  cin >> x;
  int y = 0;
  while (x > 0) {
    y += (x & 1) ? 1 : 0;
    x >>= 1;
  }
  cout << y << endl;
  return 0;
}
