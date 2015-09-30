#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

#define ULL unsigned long long
#define FOR(var, start, end) for (ULL var = start; var <= end; ++var)

int paint[100][100];

void print(int logo, int x, int y, int width, int height) {
  for (int i = y; i < y + height; i++) {
    for (int j = x; j < x + width; j++) {
      paint[i][j] = logo;
    }
  }
}

int main() {
  int x[3];
  int y[3];
  cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];

  for (int i = 0; i < 3; i++) {
    if (x[i] < y[i]) {
      swap(x[i], y[i]);
    }
    // cout << x[i] << "," << y[i] << endl;
  }

  int res = 0;
  int i = 0;

  for (i = 0; i < 3; i++) {

    int j = (i + 1) % 3;
    int k = (i + 2) % 3;

    print(k, 0, 0, x[i], x[i]);
    print(i, 0, 0, x[i], y[i]);

    if (x[j] != x[i] && x[j] + y[i] != x[i] && y[j] + y[i] != x[i]) {
      continue;
    } else if (x[j] == x[i]) {
      // second board long edge fit first board long edge
      if (x[k] == x[j] && y[k] + y[j] + y[i] == x[i]) {
        print(j, 0, y[i], x[j], y[j]);
        res = 1;
        break;
      }
    } else if (x[j] + y[i] == x[i]) {
      // second board long edge fit lower space short edge
      // cout << x[j] << "    " << y[j] << endl;
      int longer = x[j];
      int shorter = x[i] - y[j];
      if (longer < shorter) {
        swap(longer, shorter);
      }
      if (longer == x[k] && y[k] == shorter) {
        print(j, 0, y[i], y[j], x[j]);
        res = 2;
        break;
      }
    } else if (y[j] + y[i] == x[i]) {
      // second board short edge fit lower space short edge
      print(j, 0, y[i], x[j], y[j]);
      // cout << x[j] << "    " << y[j] << endl;
      int longer = y[j];
      int shorter = x[i] - x[j];
      if (longer < shorter) {
        swap(longer, shorter);
      }
      if (longer == x[k] && y[k] == shorter) {
        print(j, 0, y[i], x[j], y[j]);
        res = 3;
        break;
      }
    }
  }

  if (res) {
    cout << x[i] << endl;
    for (int j = 0; j < x[i]; j++) {
      for (int k = 0; k < x[i]; k++) {
        printf("%c", paint[j][k] + 'A');
      }
      printf("\n");
    }
  } else {
    cout << -1 << endl;
  }

  return 0;
}
