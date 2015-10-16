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

bool decompose(ll a) {
    while(a!=1) {
        if(a%2==0) {
            a /= 2;
        } else if (a%3==0) {
            a /= 3;
        } else {
           return false;
        }
    }
    return true;
}

int main() { 

    ll n;
    cin >> n;
    ll last = 0;
    fl(i, 0, n) {
        ll a;
        cin >> a;
        if(i>=1) {
            // last and a available
            // 1. find their lcm
            ll m = lcm(last, a);
            ll da = m/a;
            ll db = m/last;
            // 2. decompose lcm(x, y)/x and lcm(x, y)/y with 2 and 3
            if(!decompose(da) || !decompose(db)) {
                cout << "No" << endl;
                return 0;
            }
        }
        last = a;
    }
    cout << "Yes" << endl;
    return 0; 
}
