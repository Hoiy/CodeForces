#include <iostream>
#include <map>
using namespace std;

struct Pair {
  int i;
  int j;
};

int main() {

  long n;
  cin >> n;

  std::map<long, Pair, std::greater<long>> score;

  for (int i = 2; i <= 2 * n; ++i) {
    for (int j = 1; j < i; ++j) {
      long v;
      cin >> v;
      score[v] = {i, j};
    }
  }

  long a[1000] = {0};
  for (auto itr : score) {
    if (!a[itr.second.i] && !a[itr.second.j]) {
      a[itr.second.i] = itr.second.j;
      a[itr.second.j] = itr.second.i;
    }
  }

  for (int i = 1; i <= 2 * n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  return 0;
}
