#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	unsigned long long sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum += (i*(n-i)+1);
	}
	cout << sum << endl;
    return 0;
}