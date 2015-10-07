#include <iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int main() {
  int n, t;
  cin >> n >> t;

  string s1, s2;
  getline(cin, s1);
  getline(cin, s1);
  getline(cin, s2);

  string s3 = s1;
  int reqMatch = n - t;
  bool balance = true;
  bool set[100000] = {false};
  for (int i = 0; i < n; i++) {
    if (s1[i] == s2[i]) {
      if (reqMatch) {
        // 0 mismatch
        s3[i] = s1[i];
        reqMatch--;
        set[i] = true;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      if (reqMatch) {
        // 1 mismatch for either one
        s3[i] = balance ? s1[i] : s2[i];
        balance = !balance;
        set[i] = true;
        if (balance) {
          reqMatch--;
        }
      }
    }
  }
  if (reqMatch != 0) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (!set[i]) {
      s3[i] = (((s1[i] - 'a') + 1) % 26) + 'a';
      if (s3[i] == s2[i]) {
        s3[i] = (((s2[i] - 'a') + 1) % 26) + 'a';
      }
    }
  }

  cout << s3 << endl;
  return 0;
}
