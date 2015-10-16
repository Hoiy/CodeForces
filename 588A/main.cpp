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

template<class T> T gcd(T a, T b) {
	if (a < b)
		swap(a, b);
	return b ? gcd(b, a % b) : a;
}
template<class T> T lcm(T a, T b) {
	return a / gcd(a, b) * b;
}

int main() {
	ll n;
	cin >> n;
	
	ll lastP = 0;
	ll sol = 0;
	fl(i, 0, n) {
		ll pr;
		ll a;
		cin >> a >> pr;
		if(i == 0) {
			sol += pr *a;		
			lastP = pr;
		}else{
			if(lastP < pr) {
				sol += lastP *a;				
			}else{
				sol += pr*a;
				lastP = pr;
			}
		}
	}
	cout << sol << endl;
	
	return 0;
}
