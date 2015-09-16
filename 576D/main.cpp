#include <iostream>
#include <set>
#include <bitset>

using namespace std;

void matMul(int n, const int m1[][150], const int m2[][150],
            int(&res)[150][150]) {
  bitset<150> a[150];
  bitset<150> b[150];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      a[i][j] = m1[i][j];
      b[j][i] = m2[i][j];
    }
  }

  int temp[150][150] = {{0}};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      temp[i][j] = (a[i] & b[j]).any() ? 1 : 0;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = temp[i][j];
    }
  }
}

void matMulVec(int n, const int mat[][150], const int vec[], int(&res)[150]) {
  int temp[150] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mat[i][j] * vec[j]) {
        temp[i] = 1;
        continue;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    res[i] = temp[i];
  }
}

void matPow(int n, const int mat[][150], long p, int(&res)[150][150]) {
  int m[150][150] = {{0}};
  int temp[150][150] = {{0}};
  for (int i = 0; i < n; i++) {
    temp[i][i] = 1;
    for (int j = 0; j < n; j++) {
      m[i][j] = mat[i][j];
    }
  }

  while (p > 0) {
    if ((p & 1) == 1) {
      matMul(n, m, temp, temp);
    }

    matMul(n, m, m, m);
    p >>= 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      res[i][j] = temp[i][j];
    }
  }
}

long findSol(int n, long min, long max, const int step[][150], const int minV[],
             int *temp = nullptr) {
  if (min == max) {
    return min;
  }
  if (minV[n - 1]) {
    return min;
  }
  int res[150][150] = {{0}};
  int v[150] = {0};
  matPow(n, step, max - min, res);
  matMulVec(n, res, minV, v);

  if (!v[n - 1]) {
    if (temp) {
      for (int i = 0; i < n; i++) {
        temp[i] = v[i];
      }
    }
    return -1;
  }

  long mid = (max - min) / 2;
  matPow(n, step, mid, res);
  matMulVec(n, res, minV, v);

  if (v[n - 1]) {
    long rv = findSol(n, min, min + mid, step, minV);
    return rv;
  } else {
    matMulVec(n, step, v, v);
    long rv = findSol(n, min + mid + 1, max, step, v);
    return rv;
  }
}

int main() {

  int n, m = 0;
  cin >> n >> m;

  int adj[150][150];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      adj[i][j] = -1;
    }
  }

  std::set<long> dmap;
  adj[n - 1][n - 1] = 0;
  for (int i = 0; i < m; i++) {
    int a, b, d = 0;
    cin >> a >> b >> d;
    dmap.insert(d);
    adj[b - 1][a - 1] = d;
  }

  long step = 0;
  int city[150] = {1};
  for (auto itr = dmap.begin(); itr != dmap.end(); itr++) {
    long d = *itr;
    if (step < d) {
      break;
    }
    int a[150][150];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        a[i][j] = 0;
        if (d >= adj[i][j] && adj[i][j] >= 0) {
          a[i][j] = 1;
        }
      }
    }

    long nextD;
    itr++;
    if (itr == dmap.end()) {
      nextD = d + 25600;
    } else {
      nextD = *itr;
    }
    itr--;

    int tempCity[150];
    long sol = findSol(n, d, nextD, a, city, tempCity);
    step = sol < 0 ? nextD : sol;
    if (sol >= 0) {
      cout << sol << endl;
      return 0;
    }

    for (int i = 0; i < n; i++) {
      city[i] = tempCity[i];
    }
  }
  cout << "Impossible" << endl;

  return 0;
}
