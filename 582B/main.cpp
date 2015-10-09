#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = (start); var <= (end); ++var)
#define fl(var, start, end) for (ll var = (start); var < (end); ++var)

ll dp_0[100 * 200][300] = {{}};
ll dp_mid[100 * 200][300] = {{}};

int main() {
  ll n, T;
  cin >> n >> T;

  ll a[100] = {0};
  ll c[300] = {0};
  ll mid = -1;
  ll mid_max = -1;
  fl(i, 0, n) {
    cin >> a[i];
    a[i]--;
    c[a[i]]++;
    if (c[a[i]] > mid_max) {
      mid_max = c[a[i]];
      mid = a[i];
    }
  }

  const ll DPT = min(200LL, T);

  fl(tt, 0, DPT) {
    fl(nn, 0, n) {
      ll pos = tt * n + nn;
      fl(aa, 0, 300) {
        dp_0[pos][aa] = (aa == a[nn] ? 1 : 0);
        dp_mid[pos][aa] = (aa >= mid && aa == a[nn] ? 1 : 0);
        if (pos == 0) {
          continue;
        }
        if (aa != a[nn]) {
          dp_0[pos][aa] = dp_0[pos - 1][aa];
          dp_mid[pos][aa] = dp_mid[pos - 1][aa];
        } else {
          fle(bb, 0, aa) {
            dp_0[pos][aa] = max(dp_0[pos][aa], dp_0[pos - 1][bb] + 1);
          }
          fle(bb, mid, aa) {
            dp_mid[pos][aa] = max(dp_mid[pos][aa], dp_mid[pos - 1][bb] + 1);
          }
        }
      }
    }
  }

  ll m_0 = 0;
  ll suf = 0;
  fl(i, 0, 300) {
    m_0 = max(m_0, dp_0[n * DPT - 1][i]);
    suf = max(suf, dp_mid[n * DPT / 2 - 1][i]);
  }

  // cout << mid << endl;
  // cout << mid_max << endl;
  // cout << dp_0[n * DPT - 1][mid] << endl;
  // cout << m_mid << endl;

  if (T <= 200) {
    cout << m_0 << endl;
  } else {
    cout << dp_0[n * 100 - 1][mid] + suf + (T - 200) * mid_max << endl;
  }
  return 0;
}
