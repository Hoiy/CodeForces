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

int main() {
  ll n, s;
  cin >> n >> s;

  map<ll, ll, greater<ll>> buy;
  map<ll, ll> sell;

  fl(i, 0, n) {
    char c;
    cin >> c;
    bool isBuy = (c == 'B');
    ll p, q;
    cin >> p >> q;
    if (isBuy)
      buy[p] += q;
    else
      sell[p] += q;
  }

  // for (auto a : sell)
  //  cout << a.first << " " << a.second << endl;

  ll s_p[1000];
  ll s_q[1000];

  ll i = 0;
  for (auto a : sell) {
    s_p[i] = a.first;
    s_q[i] = a.second;
    i++;
    if (i == s)
      break;
  }
  for (ll j = i-1; j >= 0; j--) {
    cout << "S " << s_p[j] << " " << s_q[j] << endl;
  }
  i = 0;
  for (auto a : buy) {
    cout << "B " << a.first << " " << a.second << endl;
    i++;
    if (i == s)
      break;
  }
  return 0;
}
