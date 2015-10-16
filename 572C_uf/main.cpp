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

  ll sol = 0;
  bool deg = isDeg(e[0], e[1], e[2]);

  if (e[0] > e[1]) {
    swap(e[0], e[1]);
  }
  if (e[0] > e[2]) {
    swap(e[0], e[2]);
  }
  if (e[1] > e[2]) {
    swap(e[1], e[2]);
  }

  ll way = 0;
  // do nth
  if (!deg) {
    sol++;
  } else {
    // deg at start, make it into non deg
    ll inc = e[2] + 1 - e[1] - e[0];
    // way to split inc to e[1] and e[0]
    way = inc - 1;
  }

  // increase 1 edge
  fl(i, 0, 3) {
    ll remain = l;
    if (deg) {
      // if e[i] long edge, nth to do
      if (i == 3) {
        continue;
      } else {
        // increase until it is non-deg
        ll inc = e[2] + 1 - e[0] - e[1];
        remain = remain - inc;
        sol++;
      }
    }
    // non-deg tri here
    sol += remain;
  }
  // fix one edge
  fl(i, 0, 3) {
    ll remain = l;
  }
  

  return 0;
}
