#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if(n%2==0 || m%2==0 || n == 1 || m == 1) {
		cout << m*n/2 << endl;
	}
	else {
		cout << (m-1)*n/2 + n/2 << endl;
	}
	
    return 0;
}
