#include <iostream>

using namespace std;

int main() {

  int n;
  cin >> n;

  int max = 0;
  int seq = 0;
  unsigned long last = 0;
  for (int i = 0; i < n; ++i) {
    unsigned long cur;
    cin >> cur;

    if (cur >= last) {
      ++seq;
    } else {
      seq = 1;
    }
    if (seq > max) {
      max = seq;
    }
    last = cur;
  }
  cout << max << endl;
  return 0;
}
