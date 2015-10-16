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

  string s;
  getline(cin, s);
  getline(cin, s);

  ll res = 0;
  fl(i, 0, n) {
    if (s[i] == '.') {
      i++;
      while (i < n && s[i] == '.') {
        res++;
        i++;
      }
    }
  }

  fl(i, 0, m) {
    ll pos;
    char c;
    cin >> pos >> c;

    if (n == 1) {
      cout << 0 << endl;
      continue;
    }
    pos --;

    if ((s[pos] == '.' && c == '.') || (s[pos] != '.' && c != '.')) {
      cout << res << endl;
      continue;
    }

    ll ndot = 0;
    if (pos == 0) {
      ndot += s[pos + 1] == '.';
    } else if (pos == n - 1) {
      ndot += s[pos - 1] == '.';
    } else {
      ndot += s[pos + 1] == '.';
      ndot += s[pos - 1] == '.';
    }
    if (c == '.') {
      res += ndot;
    } else {
      res -= ndot;
    }
    cout << res << endl;
    s[pos] = c;
  }
  return 0;
}
