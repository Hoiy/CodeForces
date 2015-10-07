#include <iostream>

using namespace std;

#define ULL unsigned long long
#define SLL long long
#define FOR(var, start, end) for (SLL var = start; var <= end; ++var)

int main() {
  SLL n;
  cin >> n;
  SLL a[1000] = {0};
  FOR(i, 0, n - 1) { cin >> a[i]; }

  SLL t = 0;
  SLL d = 0;
  SLL pos = 0;
  bool start = 0;
  while (d < n) {
    if (a[pos] >= 0 && a[pos] <= d) {
      d++;
      a[pos] = -1;
      if (d == n) {
        cout << t << endl;
        return 0;
      }
    }
    if (start && (pos == n - 1 || pos == 0)) {
      t++;
    }
    start = true;
    pos += (t % 2 == 0 ? 1 : -1);
  }
  return 0;
}
