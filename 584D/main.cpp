#include <iostream>
#include <cmath>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

bool isPrime(ULL n) {
  if (n == 2)
    return true;

  if (n == 3)
    return true;

  if (n % 2 == 0)
    return false;

  for (ULL i = 3; i < sqrt(n) + 1; i += 2) {
    if (n % i == 0) {
      return false;
    }
  }

  return true;
}

int main() {
  ULL n;
  cin >> n;
  if (n == 3) {
    cout << 1 << endl << 3 << endl;
    return 0;
  }
  if (n == 5) {
    cout << 1 << endl << 5 << endl;
    return 0;
  }
  cout << 3 << endl;
  cout << 3 << " ";
  if (isPrime(2) && isPrime(n - 3 - 2)) {
    cout << 2 << " " << n - 3 - 2 << endl;
    return 0;
  }
  for (ULL i = 3; i < n - 3; i += 2) {
    if (isPrime(i) && isPrime(n - 3 - i)) {
      cout << i << " " << n - 3 - i << endl;
      return 0;
    }
  }
  return 0;
}
