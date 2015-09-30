#include<iostream>

using namespace std;

#define ULL unsigned long long
#define FOR(var,start,end) for(ULL var = start; var < end; ++var) 

int main() {
    int a, b;
    cin >> a >> b;
    if(a > b) {
        swap(a, b);
    }
    cout << a << " " << (b-a)/2 << endl;
    return 0;
}
