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

int main() {

  ll n;
  cin >> n;
  ll ans = 0;
  bool a[100] = {false};
  ll start = -1;
  ll end = -1;
  fl(i, 0, n) { cin >> a[i]; }
  fl(i, 0, n) {
    if (a[i]) {
      start = i;
      break;
    }
  }
  if(start == -1) {
    cout << 0 << endl;
    return 0;
  }

  for (ll i = n - 1; i >= 0; i--) {
    if (a[i]) {
      end = i;
      break;
    }
  }

  if(start == end) {
    cout << 1 << endl;
    return 0;
  }

  ans = 1;
  bool school = true;
  fle(i, start, end - 1) {
    if (a[i]) {
      ans++;
      school = true;
      continue;
    }

    if (!school) {
      continue;
    } else {
      if (!a[i + 1]) {
        school = false;
      } else {
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
