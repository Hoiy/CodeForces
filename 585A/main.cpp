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

ll v[4000];
ll d[4000];
ll p[4000];
bool bai[4000] = {false};
ll n;
void vcry(ll next) {
  ll j = 0;
  bai[next] = true;
  fl(i, 0, n) {
    if (bai[i]) {
      continue;
    }
    // remain kids
    p[i] -= (v[next] - j);
    j++;
    if (j == v[next])
      break;
  }
  //cout << p[1] << p[2] << p[3] << p[4] << endl;
  // dcry
  fl(i, 0, n) {
    if (bai[i]) {
      continue;
    }
    // remain kids
    if (p[i] < 0) {
      bai[i] = true;
      // loop after his queue
      
      fl(j, i + 1, n) { p[j] -= d[i]; }
    }
  }
  //cout << p[1] << p[2] << p[3] << p[4] << endl;
}

ll sol[4000];

int main() {
  cin >> n;
  fl(i, 0, n) { cin >> v[i] >> d[i] >> p[i]; }

  ll ans = 0;
  for (ll next = 0; next < n; next++) {
    if (bai[next]) {
      continue;
    }
    // first avaliable kid
    sol[ans] = next + 1;
    ans++;
    vcry(next);
  }

  cout << ans << endl;
  fl(i, 0, ans) { cout << sol[i] << " "; }

  cout << endl;

  return 0;
}
