#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(false);
    size_t N, M, Q;
    std::cin >> N >> M >> Q;
    int mat[N][M];
    for(auto &i : mat)
        for(auto &j : i)
            std::cin >> j;
    while(Q--) {
        size_t n1, m1, n2, m2, n, m;
        std::cin >> n1 >> m1 >> n2 >> m2 >> n >> m;
        n1--;
        n2--;
        m1--;
        m2--;
        for(size_t i = 0; i < n; i++)
            for(size_t j = 0; j < m; j++)
                std::swap(mat[n1+i][m1+j], mat[n2+i][m2+j]);
    }
    for(size_t i = 0; i < N; i++) {
        std::cout << mat[i][0];
        for(size_t j = 1; j < M; j++)
            std::cout << ' ' << mat[i][j];
        if(i != N-1)
            std::cout << '\n';
    }
    // for(auto &i : mat) {
    //     for(auto &j : i)
    //         std::cout << j << ' ';
    //     std::cout << '\n';
    // }
    return 0;
}
