#include <iostream>

size_t digui0(size_t N, char *mat, size_t x, size_t y) {
    if(mat[x * N + y] != '#')
        return 0;
    mat[x * N + y] = '0';
    size_t sum = 1;
    if(x > 0)
        sum += digui0(N, mat, x-1, y);
    if(y > 0)
        sum += digui0(N, mat, x, y-1);
    if(x < N-1)
        sum += digui0(N, mat, x+1, y);
    if(y < N-1)
        sum += digui0(N, mat, x, y+1);
    return sum;
}
int main0() {
    std::ios_base::sync_with_stdio(false);
    size_t N;
    std::cin >> N;
    char mat[N][N];
    for(auto &i : mat)
        for(auto &j : i)
            std::cin >> j;

    size_t maxN = 0;
    for(size_t i = 0; i < N; i++)
        for(size_t j = 0; j < N; j++)
            maxN = std::max(digui0(N, &(mat[0][0]), i, j), maxN);
    std::cout << maxN;

    return 0;
}

size_t digui1(size_t N, char *mat, size_t x, size_t y) {
    mat[x * N + y] = '0';
    size_t sum = 1;
    if(x > 0 && mat[x * N - N + y] == '#')
        sum += digui1(N, mat, x-1, y);
    if(y > 0 && mat[x * N + y - 1] == '#')
        sum += digui1(N, mat, x, y-1);
    if(x < N-1 && mat[x * N + N + y] == '#')
        sum += digui1(N, mat, x+1, y);
    if(y < N-1 && mat[x * N + y + 1] == '#')
        sum += digui1(N, mat, x, y+1);
    return sum;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t N;
    std::cin >> N;
    char mat[N][N];
    for(auto &i : mat)
        for(auto &j : i)
            std::cin >> j;

    size_t maxN = 0;
    for(size_t i = 0; i < N; i++)
        for(size_t j = 0; j < N; j++)
            if(mat[i][j] == '#')
                maxN = std::max(digui1(N, &(mat[0][0]), i, j), maxN);
    std::cout << maxN;

    return 0;
}
