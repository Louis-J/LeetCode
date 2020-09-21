#include <iostream>

using s64 = long long;
using u64 = unsigned long long;
constexpr s64 ModN = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n, p, m;
    std::cin >> n >> p >> m;
    u64 A[n][p];
    u64 B[p][m];

    for(auto &i : A)
        for(auto &j : i) {
            s64 temp;
            std::cin >> temp;
            if(temp < 0)
                j = temp % ModN + ModN;
            else
                j = temp % ModN;
        }
    for(auto &i : B)
        for(auto &j : i) {
            s64 temp;
            std::cin >> temp;
            if(temp < 0)
                j = temp % ModN + ModN;
            else
                j = temp % ModN;
        }
    for(size_t i = 0; i < n; i++) {
        for(size_t j = 0; j < m; j++) {
            u64 sum = 0;
            for(size_t k = 0; k < p; k++)
                sum += A[i][k]*B[k][j] % ModN;
            sum %= ModN;
            std::cout << sum;
            if(j != m-1)
                std::cout << ' ';
        }
        if(i != n-1)
            std::cout << '\n';
    }
    return 0;
}
