#include <iostream>
#include <set>
#include <bitset>
#include <vector>
using namespace std;

#define ULL unsigned long long

const ULL SIZE = 18;
ULL dp[1UL<<SIZE][SIZE];

int main() {
  ULL n, m, k;
  cin >> n >> m >> k;

  ULL a[SIZE] = {0};
  for (ULL i = 0; i < n; ++i) {
    cin >> a[i];
  }

  ULL rule[SIZE][SIZE] = {{0}};
  for (ULL i = 0; i < k; ++i) {
    ULL x, y;
    cin >> x >> y; 
    cin >> rule[x - 1][y - 1];
  }

  for (ULL i = 0; i < (1UL<<SIZE); ++i) {
    for (ULL j = 0; j < SIZE; ++j) {
      dp[i][j] = 0;
    }
  }

  ULL g_max = 0;
  for (ULL j = 1; j <= m; ++j) {
    for (ULL i = 0; i < (1UL << n); ++i) {
      bitset<18> config(i);
      // cout << "i" << i << endl;
      if (config.count() == j) {
        // cout << config << endl;
        // filling dp[i][k] such that i has j bits
        for (ULL q = 0; q < n; ++q) {

          if (!config.test(q)) {
            continue;
          }

          if (j == 1) {
            dp[i][q] = a[q];
            // cout << a[q] << endl;
          } else {
            bitset<18> subconfig = config;
            subconfig.set(q, false);

            ULL max = 0;
            for (ULL l = 0; l < n; ++l) {
              if (!subconfig.test(l)) {
                continue;
              }
              ULL sum = dp[subconfig.to_ullong()][l] + rule[l][q] + a[q];

              // cout << "sum" << sum << endl;

              if (sum > max) {
                max = sum;
              }
            }
            dp[i][q] = max;
          }

          if (j == m && dp[i][q] > g_max) {
            g_max = dp[i][q];
          }
        }
      }
    }
  }

  cout << g_max << endl;

  return 0;
}
