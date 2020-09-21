#include <iostream>
#include <vector>

using std::vector;
int main0() {
    std::ios_base::sync_with_stdio(false);
    size_t n, W;
    std::cin >> n >> W;
    vector<size_t> w, v;
    for(size_t i = 0; i < n; i++) {
        size_t w0, v0, c0;
        std::cin >> w0 >> v0 >> c0;//需假设输入c0不为0

        //将c个物品分为1, 2, 4...个物品组合，然后使用前述方法
        //保证这些物品若全选，则数量等于c
        for(size_t j = 1; j <= c0 && w0*j <= W; j *= 2) {
            w.emplace_back(w0*j);
            v.emplace_back(v0*j);
            c0 -= j;
        }
        if(c0 != 0 && w0*c0 <= W) {
            w.emplace_back(w0*c0);
            v.emplace_back(v0*c0);
        }
    }
    
    n = w.size();
    size_t value[W+1] = {0};
    for(size_t i = w[0]; i <= W; i++)
        value[i] = v[0];

    for(size_t i = 1; i < n-1; i++) {
        for(size_t j = W; j >= w[i]; j--)//从后往前，否则历史记录被覆盖
            value[j] = std::max(value[j], v[i] + value[j-w[i]]);
    }
    size_t finalV = (W >= w[n-1]) ? std::max(value[W], v[n-1] + value[W-w[n-1]]) : value[W];
    std::cout << finalV;
    return 0;
}


using WV = vector<std::pair<size_t, size_t>>;
int main() {
    std::ios_base::sync_with_stdio(false);
    size_t n, W;
    std::cin >> n >> W;
    WV wv;
    wv.reserve(n*5);
    for(size_t i = 0; i < n; i++) {
        size_t w0, v0, c0;
        std::cin >> w0 >> v0 >> c0;//需假设输入c0不为0

        //将c个物品分为1, 2, 4...个物品组合，然后使用前述方法
        //保证这些物品若全选，则数量等于c
        for(size_t j = 1; j <= c0 && w0*j <= W; j *= 2) {
            wv.emplace_back(w0*j, v0*j);
            c0 -= j;
        }
        if(c0 != 0 && w0*c0 <= W) {
            wv.emplace_back(w0*c0, v0*c0);
        }
    }
    
    n = wv.size();
    size_t value[W+1] = {0};
    for(size_t i = wv[0].first; i <= W; i++)
        value[i] = wv[0].second;

    for(size_t i = 1; i < n-1; i++) {
        for(size_t j = W; j >= wv[i].first; j--)//从后往前，否则历史记录被覆盖
            value[j] = std::max(value[j], wv[i].second + value[j-wv[i].first]);
    }
    size_t finalV = (W >= wv[n-1].first) ? std::max(value[W], wv[n-1].second + value[W-wv[n-1].first]) : value[W];
    std::cout << finalV;
    return 0;
}
