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

#ifdef _WIN32
#define lls "%I64d"
#define sll(n) scanf(lls, &(n));
#else
#define lls "%lld"
#define sll(n) scanf(lls, &(n))
#endif

#define modz 1000000007

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = (start); var <= (end); ++var)
#define fl(var, start, end) for (ll var = (start); var < (end); ++var)
#define elf(var, end, start) for (ll var = (end); var >= (start); --var)
#define lf(var, end, start) for (ll var = (end)-1; var >= (start); --var)

template <class T> T gcd(T a, T b) {
  if (a < b)
    swap(a, b);
  return b ? gcd(b, a % b) : a;
}
template <class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

using namespace std;

#define MAXNK 1000000
ll a[MAXNK] = {0};
ll sum[MAXNK][2] = {{0, 0}};
int main() {

  ll n, l, k;
  sll(n);
  sll(l);
  sll(k);

  map<ll, vector<ll>> v2p;
  vector<vector<ll>> dp;
  dp.resize(n);
  fl(i, 0, n) {
    sll(a[i]);
    v2p[a[i]].push_back(i);
    dp[i].resize(k + 1);
  }
  ll div = l / n;
  ll rem = l % n;
  //cout << l << " "  << div << endl;
  if (div == 0) {
    printf(lls "\n", l);
    return 0;
  }
  fl(i, 0, n) { dp[i][1] = 1; }
  sum[1][0] = n;
  sum[1][1] = rem;

  vector<ll> order;
  for (auto p : v2p) {
    for (auto pos : p.second) {
      order.push_back(pos);
    }
  }
  // for(auto a: order) {
  //  cout << a << " ";
  //}
  // cout << endl;
  assert(order.size() == n);
  ll maxk = min(k, div + 1);
  fle(j, 2, maxk) {
    ll last = 0;
    ll m = 0;
    ll sum_all = 0;
    fl(i, 0, n) {
      dp[order[i]][j] = last;
      while (m < n && a[order[m]] <= a[order[i]]) {
        dp[order[i]][j] = (dp[order[i]][j] + dp[order[m]][j - 1]) % modz;
        m++;
      }
      last = dp[order[i]][j];
      // cout << i << " " << j << " " << last << endl;
      sum_all = (sum_all + dp[order[i]][j]) % modz;
    }
    sum[j][0] = sum_all;
    sum[j][1] = 0;
    fl(i, 0, rem) { sum[j][1] = (sum[j][1] + dp[i][j]) % modz; }
    // cout << j << " " << sum_all << endl;
    // cout << j << " " << sum[j][1] << endl;
  }

  ll sol = 0;
  fle(j, 1, maxk) {
    sol = (sol + (((div - j + 1)%modz) * (sum[j][0]%modz)) % modz + sum[j][1]) % modz;
  }
  printf(lls "\n", sol);

  return 0;
}
