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

#define MAXN 100000
ll h[MAXN];
ll l[MAXN];
ll r[MAXN];

int main() {

  ll n;
  cin >> n;
  fl(i, 0, n) cin >> h[i];

  // compute l die time = min(ldie[i-1]+1, h[i]);
  l[0] = h[0] > 0 ? 1 : 0;
  fl(i, 1, n) l[i] = min(l[i - 1] + 1, h[i]);
  //fl(i, 0, n) cout << l[i];
  //cout << endl;

  // compute r die time
  r[n - 1] = h[n - 1] > 0 ? 1 : 0;
  elf(i, n - 2, 0) r[i] = min(r[i + 1] + 1, h[i]);
  //fl(i, 0, n) cout << r[i];
  //cout << endl;
  // die time = min(ldie, rdie)
  ll m = 0;
  fl(i, 0, n) { m = max(m, min(l[i], r[i])); }
  // sol = max(survive time)
  cout << m << endl;
  return 0;
}
