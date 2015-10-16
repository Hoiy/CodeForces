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

#define MZ (1000000007)

int main() {
	ll n, l, k;
	scanf("%I64d %I64d %I64d\n", &n, &l ,&k);

	vector<ll> a;
	fl(i, 0, n) {
		ll v;
		scanf("%I64d", &v);
		a.push_back(v);
	}
	
	vector<vector<ll>> dp;
	dp.resize(n);	
	fl(i, 0, n) {
		dp[i].resize(k+1);
	}
	fl(i, 0, n) {
		dp[i][1] = 1;
	}
	ll sol = 0;
	// k == 1
	sol += l % MZ;
	// k == 2
	ll rm = l % n;
	ll div = l / n;
	fle(j, 2, k) {
		fl(i, 0, n) {
			dp[i][j] =  
		}
	}
	
	
	
	return 0; 
}
