#include <iostream>
#include <algorithm>
using namespace std;

#define LL long long
#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

#define SIZE (2000001)
#define MODZ (1000000007)

ULL L[SIZE] = {0}; // layer node sum
ULL sum[SIZE] = {0};
ULL C[SIZE] = {0}; // n+1 choose k
ULL D[SIZE] = {0};
ULL S[SIZE] = {0};

ULL inv(ULL a, ULL n) {
  LL t = 0;
  LL newt = 1;
  LL r = n;
  LL newr = a;
  while (newr != 0) {
    LL q = r / newr;

    LL temp = newt;
    newt = t - q * temp;
    t = temp;

    temp = newr;
    newr = r - q * temp;
    r = temp;
  }
  if (t < 0)
    t = t + n;
  return t;
}

int main() {

  ULL n;
  cin >> n;

  C[n] = 1;
  FOR(i, n + 1, 2 * n) {
    C[i] = (((C[i - 1] * i) %MODZ) * inv(i - n, MODZ)) % MODZ;
    //cout << C[i] << endl;
  }

  FOR(k, 0, 2 * n) {
    if (k == 0) {
      L[k] = 1;
      D[k] = 1;
      S[k] = 0;
      sum[k] = 1;
    } else if (k < n) {
      L[k] = (L[k - 1] * 2) % MODZ;
      D[k] = L[k];
      S[k] = 0;
      sum[k] = (sum[k - 1] + L[k]) % MODZ;
    } else {
      L[k] = (2 * D[k - 1] + S[k - 1]) % MODZ;
      // single sibling
      S[k] = (2 * C[k]) % MODZ;
      // double sibling
      D[k] = (L[k] > S[k] ? L[k] - S[k] : L[k] + MODZ - S[k]);
      sum[k] = (sum[k - 1] + L[k]) % MODZ;
    }

    //cout << "k " << k << " L:" << L[k] << " Sum:" << sum[k] << " D: " << D[k]
    //     << " S: " << S[k] << " C: " << C[k] << endl;
  }

  cout << sum[2 * n] << endl;

  return 0;
}
