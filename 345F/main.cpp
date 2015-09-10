#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

string normalize(string input) {
    stringstream iss(input);
    stringstream oss;
    while(iss) { string s; iss>>s; oss<<" "<<s; }
    string output = oss.str();
    if (output.length()>0) {
        output.erase(0, 1);
    }
    transform(output.begin(), output.end(), output.begin(), ::tolower);
    return output;
}

typedef map<string, int> Map;

int main() {

    Map map;
    string line;
    string country;
    
    while(getline(cin, line))
    {
        if(line[0] != '*') {
           country = normalize(line);
           continue;
        }

        string sup = normalize(line.erase(0,1));
        map[sup]++; 
    }

    int max = 0;
    for(auto itr = map.begin(); itr != map.end(); itr++) {
        max = (itr->second > max ? itr->second : max);
    }
    for(auto itr = map.begin(); itr != map.end(); itr++) {
        if(itr->second == max) {
            cout << itr->first << endl;
        }
    }
    return 0;
}
