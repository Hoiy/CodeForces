#include<iostream>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	
	for(int i = 1; i <= t; ++i) {
		for(int j = 0; j < n-1; ++j) {
			if(s[j] == 'B' && s[j+1] == 'G') {
				swap(s[j], s[j+1]);
				++j;
			}
		}
	}
	cout << s << endl;
    return 0;
}
