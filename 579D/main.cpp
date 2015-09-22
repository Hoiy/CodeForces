#include <iostream>

using namespace std;

int main() {
  long n, k, x;
  cin >> n >> k >> x;

  long a[200000] = {0};
  long pre[200001] = {0};
  long post[200001] = {0};
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  pre[0] = 0;
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] | a[i - 1];
  }
  post[n] = 0;
  for (int i = 1; i <= n; ++i) {
    post[n - i] = post[n - i + 1] | a[n - i];
  }
  long long max = 0;
  for (int i = 0; i < n; ++i) {
    long long v = a[i];
    for (int j = 0; j < k; ++j) {
      v *= x;
    }
    long long ans = v | pre[i] | post[i + 1];
    if (ans > max) {
      max = ans;
    }
  }
  cout << max << endl;

  return 0;
}
