#include <iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int main() {
  ULL n;
  cin >> n;
  ULL h[100000] = {0};
  ULL a[100000] = {0};
  FOR(i, 0, n - 1) { cin >> h[i]; }

  a[n - 1] = 0;
  ULL max = h[n - 1];
  for (long long i = n - 2; i >= 0; --i) {
    if (h[i] > max) {
      a[i] = 0;
      max = h[i];
    } else {
      a[i] = max - h[i] + 1;
    }
  }

  FOR(i, 0, n - 1) { cout << a[i] << " "; }
  cout << endl;

  return 0;
}
