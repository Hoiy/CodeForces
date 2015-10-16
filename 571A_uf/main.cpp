#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)
#define elf(var, end, start) for (ll var = end; var >= start; --var)
#define lf(var, end, start) for (ll var = end - 1; var >= start; --var)

template <class T> T gcd(T a, T b) {
  if (a < b)
    swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

bool isDeg(ll a, ll b, ll c) {
  if (a + b <= c)
    return true;
  if (b + c <= a)
    return true;
  if (a + c <= b)
    return true;
  return false;
}

int main() {
  ll e[3], l;
  cin >> e[0] >> e[1] >> e[2] >> l;

  if (e[0] > e[1]) {
    swap(e[0], e[1]);
  }
  if (e[0] > e[2]) {
    swap(e[0], e[2]);
  }
  if (e[1] > e[2]) {
    swap(e[1], e[2]);
  }

  ll sol = 0;
  fle(i, 0, l) {
    ll le = e[2] + i;
    ll rm = l - i;
    ll ne = 0;
    if (isDeg(e[0], e[1], le)) {
      ll ne = le - i + 1 - e[0] - e[1];
      if (ne > rm)
        break;
      rm -= ne;
    }
    sol += (ne + 1) * (rm - ne + 2) * (rm - ne + 1) / 2;
    cout << sol << " " << ne << "  " << rm << endl;
  }
  cout << sol << endl;
  return 0;
}
