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

#define WMAX (1001000)
ll we[WMAX] = { 0 };

int main() {
	ll n;
	scanf("%I64d\n", &n);

	fl(i, 0, n)
	{
		ll weight;
		scanf("%I64d\n", &weight);
		we[weight]++;
	}
	fl(i, 0, WMAX)
	{
		while (we[i] > 1) {
			ll a = 1;
			ll j = 0;
			while (a <= we[i]) {
				a *= 2;
				j++;
			}
			a /= 2;
			j--;
			if (j > 0) {
				we[i] -= a;
				we[i + j] += 1;
				//cout << i<< we[i]<< we[i+j]<< endl;
			}
		}
	}

	ll sol = 0;
	fl(i, 0, WMAX)
	{
		if (we[i] == 1)
			sol++;
	}
	cout << sol << endl;
	return 0;
}
