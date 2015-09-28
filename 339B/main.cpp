#include<iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	unsigned long long t = 0;
	unsigned long long last = 1;
	for(int i = 0; i < m; ++i) {
		unsigned long long cur;
		cin >> cur;
		if(last <= cur) {
			t += (cur - last);
		}else {
			t += (cur + n - last);
		}
		last = cur;
	}
	
	cout << t << endl;
	
    return 0;
}
