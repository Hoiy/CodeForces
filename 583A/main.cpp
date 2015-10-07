#include<iostream>

using namespace std;

#define ULL unsigned long long
#define SLL long long
#define FOR(var,start,end) for(SLL var = start; var <= end; ++var) 

int main() {
    SLL n;
    cin >> n;
    bool asp[50][2] = {{0,0}};
    FOR(i, 0, n*n-1) {
        SLL h, v;
        cin >> h >> v;
        h--;
        v--;
        if(!asp[h][0] && !asp[v][1]) {
            cout << i+1 << " ";
            asp[h][0] = true;
            asp[v][1] = true;
        }
    }
    cout << endl;
    return 0;
}
