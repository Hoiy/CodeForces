#include<iostream>
#include<map>
#include<list>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var,start,end) for(ll var = start; var <= end; ++var) 
#define fl(var,start,end) for(ll var = start; var < end; ++var) 
#define dump_map(v) {for(auto a:v){cout << a.first << " " << a.second << endl;}}

ll gcd(ll a, ll b) {
    if(a < b) swap(a,b);
    if(b == 1) return 1;
    if(b <= 0) return a;
    return gcd(b, a%b);
}

int main() {
    ll n;
    cin >> n;

    map<ll, ll, std::greater<ll>> m;

    fl(i, 0, n*n) {
        ll k;
        cin >> k;
        m[k]++;
    }
    //dump_map(m);
    list<ll> ans;
    fl(i, 0, n) {
        ll max = m.begin()->first;
        m[max]--;
        if(m[max] == 0) {
            m.erase(m.find(max));
        }
        //dump_map(m);
        cout << max << " ";

        for(auto a:ans) {
            ll f = gcd(a, max);
            m[f] -= 2;
            if(m[f] == 0) {
                m.erase(m.find(f));
            }
        }

        ans.push_back(max);
    }
    cout << endl;
    return 0;
}
