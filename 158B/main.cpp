#include<iostream>

using namespace std;

int main() {
    int n = 0;
    int s[100000];
    cin >> n;
    for(int i = 0; i<n; i++) {
        cin >> s[i];
    }

    int c = 0;

    for(int i =0; i<n; i++) {
        if(s[i] == 4)
            c++;
    }

    int c1 = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 3) {
            c++;
            c1++;
        }
    }
    
    int c2 = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 2) {
            if(c2 > 0) {
                c2 --;
            } else {
                c ++;
                c2 ++;
            }
        }
    }

    int c3 = 0;
    for(int i=0; i<n; i++) {
        if(s[i] == 1) {
            if(c1 > 0) {
                c1 --;
            } else if(c2 > 0) {
                c2 --;
                c1 ++;
            } else if (c3 > 0){
                c3 --;
                c2 ++;
            } else {
                c ++;
                c3 ++;
            }
        }
    }

    cout << c;



    return 0;
}
