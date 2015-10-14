#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll a[100];

int main() {
  ll n;
  cin >> n;
  fl(i, 0, n) cin >> a[i];

  ll max = 0;
  ll max_i = 0;
  fl(i, 0, n) {
    if (a[i] >= max) {
      max = a[i];
      max_i = i;
    }
  }
  ll sol = 0;
  while (max_i != 0) {
    a[max_i]--;
    a[0]++;
    sol++;
    max = -1;
    max_i = -1;
    fl(i, 0, n) {
      if (a[i] >= max) {
        max = a[i];
        max_i = i;
      }
    }
  }
  cout << sol << endl;

  return 0;
}
