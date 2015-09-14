#include<iostream>
#include<map>

using namespace std;

int main() {

    long n, m;
    cin >> n;
    cin >> m;

    bool b[1000] = {0};  

    for(long i = 0; i<n; i++) {
        long a;
        cin >> a;
      
        bool c[1000] = {0};
        for(long j = 0; j < m; j++) {
            if(b[j]) {
                c[(a+j)%m] = true;
            }
        }
        c[a % m] = true;
        
        for(long j = 0; j < m; j++) {
            b[j] = c[j] || b[j];
        }

        if(b[0])
        {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    
    return 0;
}
