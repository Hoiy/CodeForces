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

#define MAX_CAR (100000)
ll pos[MAX_CAR];

int main() { 
    ll n;
    sll(n);
    fl(i, 0, n) {
        ll a;
        sll(a);
        pos[a-1] = i;
    }
    ll m = 1;
    ll count = 1;
    ll last = pos[0];
    fl(i, 1, n) {
        if(pos[i] >= last) {
            count++;
        }
        if(pos[i] < last || i == n-1) {
            m = max(m, count);
            count = 1;
        }
        last = pos[i];
    }
    cout << n - m << endl;

    return 0; 
}
