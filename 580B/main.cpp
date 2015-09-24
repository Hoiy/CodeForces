#include <iostream>
#include <map>
#include <list>

using namespace std;

#define ULL unsigned long long
#define FOR(a, b, c) for (ULL a = b; a <= c; ++a)

int main() {

  ULL n, d;
  cin >> n >> d;

  map<ULL, ULL> money;

  FOR(i, 1, n) {
    ULL m, s;
    cin >> m >> s;
    if (money.count(m)) {
      money[m] += s;
    } else {
      money[m] = s;
    }
  }

  ULL max = 0;
  ULL last_factor = 0;
  auto end = money.begin();
  for (auto begin = money.begin(); begin != money.end(); ++begin) {
    while (end != money.end() && end->first - begin->first < d) {
      last_factor += end->second;
      ++end;
    }

    if (last_factor > max) {
      max = last_factor;
    }

    last_factor -= begin->second;
  }

  cout << max << endl;

  return 0;
}
