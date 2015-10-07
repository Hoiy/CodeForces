#include <iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

#define MODZ (1000000007UL)

int main() {
  ULL n;
  cin >> n;
  ULL t = 1;
  ULL l = 1;
  FOR(i, 1, n) {
    t = (t * 7) % MODZ;
    l = (l * 27) % MODZ;
  }
  cout << (MODZ + l - t) % MODZ << endl;
  return 0;
}
