#include <iostream>

int main() {
    size_t n, W;
    std::cin >> n >> W;
    size_t w[n], v[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> w[i] >> v[i];
    
    size_t value[W+1];

    for(size_t i = 0; i <= W; i++)
        value[i] = i/w[0]*v[0];

    for(size_t i = 1; i < n; i++) {
        if(w[i] > W)//此物品无法放入
            continue;
        for(size_t j = w[i]; j <= W; j++)//从前往后，就是无数个的情况
            value[j] = std::max(value[j], v[i] + value[j-w[i]]);
    }
    size_t finalV = value[W];
    std::cout << finalV;
    return 0;
}
