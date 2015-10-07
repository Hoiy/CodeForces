#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <cstdio>
using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = (start); var <= (end); ++var)

ULL a[2000] = {0};
ULL b[2000] = {0};
ULL ap[2000] = {0};
ULL bp[2000] = {0};
int step[2000000][2] = {{0, 0}};

int main() {
  ULL n;
  cin >> n;
  FOR(i, 0, n - 1) {
    cin >> a[i];
    --a[i];
    ap[a[i]] = i;
  }
  FOR(i, 0, n - 1) {
    cin >> b[i];
    --b[i];
    bp[b[i]] = i;
  }

  ULL cost = 0;
  ULL size = 0;
  for (int j = n - 1; j >= 0; --j) {
    if (a[j] == b[j])
      continue;

    int i = ap[b[j]];
    for (int t = i + 1; t <= j; ++t) {
      int tp = bp[a[t]];
      if (tp <= i) {
        cost += abs(i - t);
        step[size][0] = i + 1;
        step[size][1] = t + 1;
        size++;
        swap(a[i], a[t]);
        swap(ap[a[i]], ap[a[t]]);
        i = t;
      }
    }
  }

  cout << cost << endl;
  cout << size << endl;
  for (ULL i = 0; i < size; i++) {
    // cout << step[i][0] << " " << step[i][1] << " " << endl;
    printf("%d %d\n", step[i][0], step[i][1]);
  }
  return 0;
}
