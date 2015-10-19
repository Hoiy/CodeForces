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
#include <stack>
#include <set>
#include <tuple>

#ifdef _WIN32
#define lls "%I64d"
#define sll(n) scanf(lls, &(n));
#else
#define lls "%lld"
#define sll(n) scanf(lls, &(n))
#endif

#define modz 1000000007

typedef unsigned long long ull;
typedef int ll;
#define fle(var, start, end) for (ll var = (start); var <= (end); ++var)
#define fl(var, start, end) for (ll var = (start); var < (end); ++var)
#define elf(var, end, start) for (ll var = (end); var >= (start); --var)
#define lf(var, end, start) for (ll var = (end)-1; var >= (start); --var)
#define dump(container)                                                        \
  fl(auto e : container) cout << e << " ";                                     \
  cout << endl;

template <class T> T gcd(T a, T b) {
  if (a < b)
    swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

using namespace std;

char c[500][500];
ll dp[2][500][500] = {{{}}};
ll n, m;
bool valid(ll r1, ll c1, ll r2, ll c2) {
  return r2 >= r1 && c2 >= c1 && r1 >= 0 && c1 >= 0 && r2 < n && c2 < m;
}
int main() {
  cin >> n >> m;
  fl(i, 0, n) fl(j, 0, m) { cin >> c[i][j]; }

  ll r1, r2, c1, c2;
  r1 = (n - 1) / 2;
  r2 = (n - 1) / 2 + (n - 1) % 2;
  c1 = (m - 1) / 2;
  c2 = (m - 1) / 2 + (m - 1) % 2;
  ll z = max(n, m);

  r1 = 0;
  c1 = (n + m - 2) / 2;
  r2 = 0;
  c2 = (n + m - 2) / 2 + (n + m - 2) % 2;

  for (c1 = (n + m - 2) / 2; c1 >= 0; c1--, c2++) {
    ll cur = c1 % 2;
    ll last = (c1 + 1) % 2;
    fle(s1, 0, z) {
      ll rr1 = r1 + s1;
      ll cc1 = c1 - s1;
      fle(rd, 0, c2 - c1) {
        ll rr2 = rr1 + (c2 - c1) - rd;
        ll cc2 = cc1 + rd;
        if (valid(rr1, cc1, rr2, cc2)) {
          ll dist = cc2 - cc1 + rr2 - rr1;
          if (dist == 0) {
            dp[cur][cc1][cc2] = 1;
            continue;
          }
          // at least 2 square
          if (c[rr1][cc1] != c[rr2][cc2]) {
            dp[cur][cc1][cc2] = 0;
            continue;
          }
          // same character at front and end
          if (dist == 1) {
            dp[cur][cc1][cc2] = 1;
          } else if (rr1 == rr2) { // same row
            dp[cur][cc1][cc2] = dp[last][cc1 + 1][cc2 - 1];
          } else if (c1 == c2) { // same col
            dp[cur][cc1][cc2] = dp[last][cc1][cc2];
          } else { // rectangle
            ll v = 0;
            v += dp[last][cc1 + 1][cc2];
            v %= modz;
            v += dp[last][cc1][cc2];
            v %= modz;
            v += dp[last][cc1 + 1][cc2 - 1];
            v %= modz;
            v += dp[last][cc1][cc2 - 1];
            v %= modz;
            dp[cur][cc1][cc2] = v;
          }
        }
      }
    }
  }
  cout << dp[0][0][m - 1] << endl;
  return 0;
}
