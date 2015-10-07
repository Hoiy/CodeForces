#include <iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int main() {
  int n, t;
  cin >> n >> t;

  if (n == 1) {
    if (t == 10)
      cout << -1 << endl;
    else
      cout << t << endl;
    return 0;
  }
  int a = 1;
  for (int i = 0; i < n - 1; i++) {
    a *= (10 % t);
    a %= t;
  }
  cout << 1;
  for (int i = 0; i < n - 2; i++) {
    cout << 0;
  }
  cout << (t - a) % t << endl;

  return 0;
}
