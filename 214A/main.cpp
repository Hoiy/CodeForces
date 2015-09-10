#include<iostream>

using namespace std;

int main() {
    int n, m = 0;
    cin >> n;
    cin >> m;
    int s = 0;
    for(int a = 0; a <= 32; a++) {
        for(int b = 0; b <= 32; b++) {
            if(a*a + b == n && b*b+a==m ) {
                s++;
            }
        }
    }
    cout << s;
    return 0;
}
