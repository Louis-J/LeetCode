#include <iostream>

int main() {
    size_t n, W;
    std::cin >> n >> W;
    size_t w[n], v[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> w[i] >> v[i];
    
    size_t value[W+1];

    for(size_t i = 0; i < std::min(W, w[0]); i++)
        value[i] = 0;
    for(size_t i = w[0]; i <= W; i++)
        value[i] = v[0];

    for(size_t i = 1; i < n-1; i++) {
        if(w[i] > W)//此物品无法放入
            continue;
        for(size_t j = W; j >= w[i]; j--)//从后往前，否则历史记录被覆盖
            value[j] = std::max(value[j], v[i] + value[j-w[i]]);
    }
    size_t finalV = (W >= w[n-1]) ? std::max(value[W], v[n-1] + value[W-w[n-1]]);
    std::cout << finalV;
    return 0;
}
