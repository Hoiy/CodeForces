#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	getline(cin, s);
	int x=0;
	for(int i = 0; i < n; i++) {
		getline(cin, s);
		char op;
		if(s[0] == 'X') {
			op = s[1];
		}else
		{
			op = s[0];
		}
		if(op == '+') {
			++x;
		}else
		{
			--x;
		}
	}
	cout << x << endl;
    return 0;
}
