#include <iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int main() {
  ULL n, k;
  cin >> n >> k;
  ULL re[10] = {0};
  ULL rating = 0;
  FOR(i, 0, n - 1) {
    int ai;
    cin >> ai;

    int c = ai / 10;
    int r = ai % 10;

    rating += c;
    if (r) {
      ++re[ai % 10];
    }
    re[0] += (10 - c - (r ? 1 : 0));
    //cout << ai << "," << re[0] << " ";
  }
  /*
  for (int i = 0; i < 10; i++) {
    cout << re[i] << endl;
  }
  */

  for (int i = 9; i >= 0; --i) {

    ULL c = k / (10 - i);
    ULL r = k % (10 - i);

    // cout << i << " " << c << " " << r << " " << k << endl;

    if (c >= re[i]) {
      rating += re[i];
      c -= re[i];
    } else {
      rating += c;
      c = 0;
    }

    k = r + c * (10 - i);
  }

  cout << rating << endl;

  return 0;
}
