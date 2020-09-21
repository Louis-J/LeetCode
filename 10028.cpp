#include <iostream>

int main() {
    size_t n, W, C;
    std::cin >> n >> W >> C;
    size_t w[n], c[n], v[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> w[i] >> c[i] >> v[i];
    
    size_t value[W+1][C+1] = {{0}};

    for(size_t i = w[0]; i <= W; i++)
        for(size_t j = c[0]; j <= C; j++)
            value[i][j] = v[0];

    for(size_t i = 1; i < n-1; i++) {
        if(w[i] > W || c[i] > C)//此物品无法放入
            continue;
        //从后往前，否则历史记录被覆盖
        for(size_t j = W; j >= w[i]; j--)
            for(size_t k = C; k >= c[i]; k--)
                value[j][k] = std::max(value[j][k], v[i] + value[j-w[i]][k-c[i]]);
    }
    size_t finalV = (W >= w[n-1] && C >= c[n-1]) ? std::max(value[W][C], v[n-1] + value[W-w[n-1]][C-c[n-1]]) : value[W][C];
    std::cout << finalV;
    return 0;
}
