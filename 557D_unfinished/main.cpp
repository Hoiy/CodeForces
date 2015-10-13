#include <iostream>

using namespace std;

#define SIZE (200001)

int n, m;
char s[SIZE];

int ma();

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  ma();
}

int ma() {
  
  long ST[SIZE] = {0}; // ST[n] = LCS of S_n and T_n-1 is n-1
  ST[0] = 0;
  ST[1] = 0; // special case, look out for n == 2
  ST[2] = (s[2] == s[1] ? 1 : 2);
  for (int i = 3; i <= n; ++i) {
    ST[i] = ST[i - 1] + ((s[i - 1] == s[i - 2]) ? 0 : 1);
  }
  long TS[SIZE] = {0}; // TS[n] = LCS of S_n-1 and T_n is n-1
  TS[0] = 0;
  TS[1] = m; // special case, look out for n == 2
  for (int i = 2; i <= n; ++i) {
    TS[i] = TS[i - 1] + (m - 1);
  }

  long repeat[SIZE] = {0};
  repeat[0] = 0;
  repeat[1] = 1;
  for (int i = 2; i <= n; ++i) {
    repeat[i] = (s[i - 1] == s[i - 2] ? repeat[i - 1] + 1 : 1);
  }

  /*
  cout << "Repeat" << endl;
  for(int i = 0; i<=n; ++i) {
    cout << repeat[i] <<endl;
  }
  */

  long alt[SIZE] = {0};
  alt[0] = 0;
  alt[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (s[i - 1] == s[i - 2]) {
      alt[i] = 1;
    } else {
      if (i >= 3 && s[i - 1] == s[i - 3]) {
        alt[i] = alt[i - 1] + 1;
      } else {
        alt[i] = 2;
      }
    }
  }

  cout << "Alt" << endl;
  for (int i = 0; i <= n; ++i) {
    cout << alt[i] << endl;
  }

  long dp[SIZE] = {0}; // dp[n] = LCS of S_n and T_n is n-1
  dp[0] = 0;
  dp[1] = m - 1;
  for (int i = 2; i <= n; ++i) {
    // case last letter matched
    dp[i] = dp[i - 1];

    // case last letter unmatched
    if (s[i - 1] == s[i - 2]) {
      dp[i] += (m - 1) * ST[i];
    } else {
      // case: S: ......ab
      //       T: .......c
      dp[i] += (m - 2) * ST[i];

      dp[i] += ST[i];
      // case: S: ...ab..abab
      //       T: ..........a
      if (m >= 3) {
          dp[i] += (m-3);
        if (repeat[i - 1] >= 1) {
          if (i - repeat[i - 1] - 2 >= 1) {
            dp[i] += TS[i - repeat[i - 1] - 2];
          }else{
            dp[i] +=1;
          }
        } else {
          if (i - alt[i] - 1 >= 1) {
            dp[i] += TS[i - alt[i] - 1];
          }
          else{
            dp[i] +=1;
          }
        }
      }
    }

    cout << i << " ST: " << ST[i] << " TS: " << TS[i - 1] << " dp " << dp[i - 1]
         << " " << dp[i] << endl;
  }

  cout << dp[n] << endl;
  return 0;
}
