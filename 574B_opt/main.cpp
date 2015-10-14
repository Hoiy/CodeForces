#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <iostream>
#include <cstring>
using namespace std;

typedef unsigned long long ull;
typedef int ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

vector<ll> adj[4000];
bool isAdj[4000];
ll cou[4000];
int main() {

  ll n, m;
  scanf("%d", &n);
  scanf("%d", &m);

  fl(i, 0, m) {
    ll x, y;
    scanf("%d %d", &x, &y);
    --x;
    --y;
    if (x > y)
      swap(x, y);
    adj[x].push_back(y);
    // adj[y].push_back(x);
    ++cou[x];
    ++cou[y];
  }

  ll mini = 5000 * 3;
  fl(i, 0, n) {
    ll a = i;
    memset(isAdj, 0, sizeof(isAdj));
    fl(k, 0, (ll)adj[a].size()) isAdj[adj[a][k]] = true;
    fl(j, 0, (ll)adj[a].size()) {
      ll b = adj[a][j];
      // a < b for sure
      fl(l, 0, (ll)adj[b].size()) {
        ll c = adj[b][l];
        // b < c for sure
        if (isAdj[c]) {
          mini = min(mini, cou[a] + cou[b] + cou[c]);
        }
      }
    }
  }

  if (mini == 5000 * 3) {
    puts("-1");
  } else {
    printf("%d\n", mini - 6);
  }
  return 0;
}
