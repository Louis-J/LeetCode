#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n, W, C;
    std::cin >> n >> W >> C;
    size_t w[n], c[n], v[n];
    for(size_t i = 0; i < n; i++)
        std::cin >> w[i] >> c[i] >> v[i];
    
    size_t value[W+1][C+1] = {{0}};

    for(size_t i = w[0]; i <= W; i++)
        for(size_t j = c[0]; j <= C; j++)
            value[i][j] = std::min(i/w[0], j/c[0])*v[0];

    for(size_t i = 1; i < n; i++) {
        //从前往后
        for(size_t j = w[i]; j <= W; j++)
            for(size_t k = c[i]; k <= C; k++)
                value[j][k] = std::max(value[j][k], v[i] + value[j-w[i]][k-c[i]]);
    }
    size_t finalV = value[W][C];
    std::cout << finalV;
    return 0;
}
