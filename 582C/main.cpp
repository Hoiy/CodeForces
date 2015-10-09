#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <set>
#include <valarray>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll a[2 * 100000];
bool b[2 * 100000];
ll c[2 * 100000 + 1];
ll n;
ll f[2 * 100000];

int main() {
  cin >> n;
  fl(i, 0, n) { cin >> a[i]; }
  fle(i, 1, n - 1) f[i] = gcd(n, i);
  ll sol = 0;
  fl(fac, 1, n) {
    if (n % fac != 0)
      continue;

    fill_n(b, n, false);
    fill_n(c, n, 0);

    // compute b
    fl(st, 0, fac) {
      ll m = 0;
      for (ll pos = st; pos < n; pos += fac) {
        m = max(m, a[pos]);
      }
      for (ll pos = st; pos < n; pos += fac) {
        if (a[pos] == m)
          b[pos] = true;
      }
    }

    // compute c
    bool wrap = b[0] && b[n - 1];
    fl(begin, 0, n) {
      // cout << begin << " " << end << endl;
      if (wrap && b[begin] && begin < n - 1) {
        continue;
      }
      wrap = false;
      if (!b[begin]) {
        continue;
      }
      // found a start
      ll end = (begin + 1) % n;
      ll size = 1;
      // increase end until broken or reach begin;
      while (b[end] && end != begin && size < n) {
        end = (end + 1) % n;
        size++;
        // cout << "b "<< begin<<"e " << end << endl;
      }
      // cout << size << "size" << endl;
      // process size;
      if (size == n)
        fle(j, 1, size) c[j] = size;
      else
        fle(j, 1, size) c[j] += (size - j + 1);

      // if end > begin, begin = end, else end = n;
      begin = end > begin ? end : n;
    }
    // cout << c[0] << c[1] << c[2] << c[3] << endl;

    // compute sol
    fle(i, 1, n - 1) {
      if (f[i] != fac)
        continue;
      sol += c[i];
      // cout << "i"<<i<<"ci" << c[i] << endl;
    }
  }

  cout << sol << endl;
  return 0;
}
