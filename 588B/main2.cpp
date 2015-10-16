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

  ll sol = 1;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i)
      continue;
    sol *= i;
    while (n % i == 0)
      n /= i;
  }
  cout << sol *n << endl;
  return 0;
}
