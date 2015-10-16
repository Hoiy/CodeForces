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

int main() {
  ll n, m;
  cin >> n >> m;
  ll can[100] = {0};
  ll max_idx = -1;
  ll max = -1;
  fl(i, 0, m) {
    ll winner_vote = -1;
    ll winner_idx = -1;
    fl(j, 0, n) {
      ll vote;
      cin >> vote;
      if (vote > winner_vote) {
        winner_vote = vote;
        winner_idx = j;
      }
    }
    can[winner_idx]++;
    if (can[winner_idx] > max || (can[winner_idx]==max && winner_idx < max_idx)) {
      max_idx = winner_idx;
      max = can[winner_idx];
    }
  }
  cout << max_idx + 1 << endl;
  return 0;
}
