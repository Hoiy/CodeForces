#include<iostream>

int main() {
    long long n, m, a = 0;
    std::cin >> n;
    std::cin >> m;
    std::cin >> a;
    std::cout << ((n/a)+(n%a?1:0))*((m/a)+(m%a?1:0));
    return 0;
}
