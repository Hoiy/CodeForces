#include <iostream>

using namespace std;

int main() {

  long n, x;
  cin >> n >> x;
  long k = 0;
  for (int i = 1; i <= n; ++i) {
    if (x % i == 0 && x / i <= n) {
      ++k;
    }
  }
  cout << k << endl;

  return 0;
}
