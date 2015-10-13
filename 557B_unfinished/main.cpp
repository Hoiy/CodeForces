#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int main() {
  ULL n, w;
  cin >> n >> w;
  map<ULL, ULL> sort;
  FOR(i, 0, 2 * n - 1) {
    ULL ai;
    cin >> ai;
    ++sort[ai];
  }
  ULL gMin = sort.begin()->first;
  ULL bMin = gMin;
  ULL c = 0;
  for (auto itr = sort.cbegin(); itr != sort.cend(); ++itr) {
    c += itr->second;
    if (c < n) {
      continue;
    }
    if (c == n) {
      bMin = (++itr)->first;
    } else {
      bMin = itr->first;
    }
    break;
  }

  cout.precision(99);
  cout << min((long double)w, min(gMin * 3.0L * n, bMin / 2.0L * 3 * n)) << endl;

  return 0;
}
