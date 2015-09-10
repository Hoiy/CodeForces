#include<iostream>

int main() {
    int n = 0;
    std::cin >> n;
    std::cout << (((n<=2)||(n%2)) ? "NO" : "YES");
    return 0;
}
