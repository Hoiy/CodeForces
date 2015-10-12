#include <iostream>
#include <algorithm>
#include <cassert>
#include <map>
#include <list>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
#define fle(var, start, end) for (ll var = start; var <= end; ++var)
#define fl(var, start, end) for (ll var = start; var < end; ++var)

template <class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

int main() {
  ll t;
  cin >> t;
  fl(T, 0, t) {
    ll n, k;
    cin >> n >> k;
    string row[3];
    getline(cin, row[0]);
    getline(cin, row[0]);
    getline(cin, row[1]);
    getline(cin, row[2]);

    ll time = 0;
    bool pos[3] = {false};
    fl(i, 0, 3) if (row[i][0] == 's') pos[i] = true;
    while (time < n - 1) {

      bool lastpos[3] = {false};
      fl(i, 0, 3) {
        lastpos[i] = pos[i];
        pos[i] = false;
      }

      time += 1;
      // moved right
      fl(i, 0, 3) {
        if (lastpos[i] && row[i][time] == '.') {
          pos[i] = true;
        }
      }

      fl(i, 0, 3) { lastpos[i] = pos[i]; }
      // move up down
      if (lastpos[0] && row[1][time] == '.') {
        pos[1] = true;
      }
      if (lastpos[1] && row[0][time] == '.') {
        pos[0] = true;
      }
      if (lastpos[1] && row[2][time] == '.') {
        pos[2] = true;
      }
      if (lastpos[2] && row[1][time] == '.') {
        pos[1] = true;
      }

      if (time == n - 1) {
        break;
      }
      if (time == n - 2 || time == n - 3) {
        continue;
      }

      // move train
      time += 2;
      fl(i, 0, 3) {
        if (row[i][time] != '.' || row[i][time - 1] != '.') {
          pos[i] = false;
        }
      }
    }

    cout << (pos[0] || pos[1] || pos[2] ? "YES" : "NO") << endl;
  }
  return 0;
}
