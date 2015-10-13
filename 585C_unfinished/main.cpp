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

int main() {
  ll x, y;
  cin >> x >> y;

  // Find a number P relatively prime to N=x+y
  ll N = x + y;
  ll P = 0;
  fl(i, 2, N) {
    if (gcd(N, i) == 1) {
      P = i;
      break;
    }
  }

  // Do extend GCD, for each eq A = kB + C, B = k'C + D
  // the solution is with kAk'B... alternating
  list<ll> l;
  ll A, B = N, C = P, k;
  do {
    A = B;
    B = C;

    k = A / B;
    l.push_back(k);
    C = A % B;
  } while (C != 1);
  if (B == 1) {
    puts("Impossible");
    return 0;
  }
  l.push_back(B - 1);

  // let B = 0, C = 1 and backtrace the ans to determine who first
  B = 0, C = 1;
  for (auto itr = l.rbegin(); itr != l.rend(); itr++) {
    A = *itr * B + C;
    C = B;
    B = A;
  }
  bool AFirst = (A == x) == (l.size() % 2 == 0);
  for (auto itr = l.rbegin(); itr != l.rend(); itr++) {
    printf("%lld%c", *itr, AFirst ? 'A' : 'B');
    AFirst = !AFirst;
  }
  return 0;
}
