#include <iostream>
#include <vector>

using std::vector;
using VW = vector<std::pair<size_t, size_t>>;
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t N, V;
    std::cin >> N >> V;
    VW vw;
    vw.reserve(N*5);
    for(size_t i = 0; i < N; i++) {
        size_t v0, w0, s0;
        std::cin >> v0 >> w0 >> s0;//需假设输入c0不为0

        //将c个物品分为1, 2, 4...个物品组合，然后使用前述方法
        //保证这些物品若全选，则数量等于c
        for(size_t j = 1; j <= s0 && v0*j <= V; j *= 2) {
            vw.emplace_back(v0*j, w0*j);
            s0 -= j;
        }
        if(s0 != 0 && v0*s0 <= V) {
            vw.emplace_back(v0*s0, w0*s0);
        }
    }
    
    N = vw.size();
    size_t value[V+1] = {0};
    for(size_t i = vw[0].first; i <= V; i++)
        value[i] = vw[0].second;

    for(size_t i = 1; i < N-1; i++) {
        for(size_t j = V; j >= vw[i].first; j--)//从后往前，否则历史记录被覆盖
            value[j] = std::max(value[j], vw[i].second + value[j-vw[i].first]);
    }
    size_t finalV = (V >= vw[N-1].first) ? std::max(value[V], vw[N-1].second + value[V-vw[N-1].first]) : value[V];
    std::cout << finalV;
    return 0;
}
