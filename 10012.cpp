#include <iostream>

int main() {
    unsigned int n, m;
    std::cin >> n >> m;
    unsigned int a[n];
    for(auto &i : a)
        std::cin >> i;
    
    while(m--) {
        unsigned int t;
        std::cin >> t;
        std::cout << a[t-1] << std::endl;
    }
    return 0;
}