#include<iostream>

using namespace std;

int done(int* a, int n) {
    for(int i=0; i<n; i++ ) {
        if(a[i] != i) return false;
    }
    return true;
}

void rotate(int*a, int n) {
    int sign = 1;
    for(int i=0; i<n ; i++) {
        a[i] = (a[i] + sign + n) % n;
        sign *= -1;
    }
}

int main() {
    int a[1000];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> a[i];
    }

    if(done(a, n)){
        cout << "YES";
        return 0;
    }

    for(int i = 0; i<n; i++) {
    
        rotate(a, n);

        if(done(a, n)){
            cout << "YES";
            return 0;
        }

    }

    cout << "NO";
    return 0;
}
