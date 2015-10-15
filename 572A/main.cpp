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

ll a[100000];
ll b[100000];

int main() { 
    ll na, nb;
    cin >> na >> nb;

    ll k, m;
    cin >> k >> m;

    fl(i, 0, na) cin >> a[i];
    fl(i, 0, nb) cin >> b[i];
    if(a[k-1]<b[nb-m]) {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}
