#include<iostream>

using namespace std;

int main() {
    int n, k = 0;
    cin >> n;
    cin >> k;

    int nr = 0;
    int ak = 0;
    for(int i = 1; i<=n; i++) {
        int a = 0;
        cin >> a;

        if(i == k) {
            ak = a;
        }

        if (a == 0 || (i>k && a < ak)){
            break;
        } else {
            nr++;
        }
    }

    cout << nr;

    return 0;
}
