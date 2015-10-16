#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)
#define elf(var, end, start) for (ll var = end; var >= start; --var)
#define lf(var, end, start) for (ll var = end - 1; var >= start; --var)
#define dump(container)                                                        \
  for (auto e : (container))                                                   \
    cout << e << endl;

template <class T> T gcd(T a, T b) {
  if (a < b)
    swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

int main() {
  ll n;
  cin >> n;

  set<ll, greater<ll>> factor;
  factor.insert(1);
  factor.insert(n);

  elf(i, floor(sqrt(n)), 2) {
    if (n % i == 0) {
      factor.insert(i);
      factor.insert(n / i);
    }
  }
  for (auto a : factor) {
    bool good = true;
    fle(i, 2, floor(sqrt(n))) {
      if (a % (i * i) == 0) {
        good = false;
        break;
      }
    }
    if (good) {
      cout << a << endl;
      return 0;
    }
  }
  return 0;
}
