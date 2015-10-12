#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

ll a[2][49];
ll sum[2][49];
ll b[50];

int main() { 
    ll n;
    cin >> n;

    fl(i, 0, n-1) cin >> a[0][i];
    fl(i, 0, n-1) cin >> a[1][i];
    fl(i, 0, n) cin >> b[i]; 
   
    sum[0][0] = a[0][0];
    sum[1][n-2]  = a[1][n-2];
    fl(i, 1, n-1) sum[0][i] = sum[0][i-1] + a[0][i];
    for(ll i = n-3; i >= 0; i--) sum[1][i] = a[1][i] + sum[1][i+1];
    priority_queue<ll, vector<ll>, greater<ll>> q;

    fl(i, 0, n) {
        ll up = (i == 0?0:sum[0][i-1]);
        ll down = (i==n?0:sum[1][i]);
        //cout << i << up << b[i] << down << endl;
        q.push(up + b[i] + down);
    }
    ll ans = q.top();
    //cout << ans << endl;
    q.pop();
    ans += q.top();
    cout << ans << endl;

    return 0; 
}
