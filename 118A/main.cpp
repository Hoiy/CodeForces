#include<iostream>

using namespace std;

int main() {
	string s;
	getline(cin, s);
	char ns[500] = {0};
	int j = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(	s[i] == 'A' ||
			s[i] == 'a' ||
			s[i] == 'O' ||
			s[i] == 'o' ||
			s[i] == 'Y' ||
			s[i] == 'y' ||
			s[i] == 'E' ||
			s[i] == 'e' ||
			s[i] == 'U' ||
			s[i] == 'u' ||
			s[i] == 'I' ||
			s[i] == 'i')
		{
			continue;
		}
		else {
			ns[j++] = '.';
			ns[j++] = 'a' <= s[i] && s[i] <= 'z' ? s[i] : s[i] - ('A'-'a');
		}
	}
	cout << ns << endl;
    return 0;
}
