#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    // struct Baline {
    //     vector<vector<pair<int, int>>> table{{0, 0}};
    //     void update(Baline &b, int off) {
    //         for(auto &i : b) {
    //             auto it = amap.lower_bound(i.first);
    //             if(it == amap.end()) {
    //                 it = amap.emplace_hint(it, i.first, i.second);
    //                 int val = i.second;
    //                 it--;
    //                 do {
    //                     if(it->second < val)
    //                         it 
    //                 }
    //             }
    //         }
    //         heheheh
    //     }
    // };
public:
    //超时
    int calculateMinimumHP0(vector<vector<int>>& dungeon) {
        const size_t m = dungeon.size(), n = dungeon[0].size();
        vector<vector<pair<int, int>>> hp(n, vector<pair<int, int>>{{0, 0}});
        hp[0][0].first = hp[0][0].second = dungeon[0][0];
        for(size_t i = 1; i < n; i++) {
            hp[i][0].first = hp[i-1][0].first + dungeon[0][i];
            hp[i][0].second = min(hp[i][0].first, hp[i-1][0].second);
        }
        for(size_t i = 1; i < m; i++) {
            hp[0][0].first += dungeon[i][0];
            hp[0][0].second = min(hp[0][0].first, hp[0][0].second);
            for(size_t j = 1; j < n; j++) {
                hp[j].insert(hp[j].end(), hp[j-1].begin(), hp[j-1].end());
                for(auto &k : hp[j]) {
                    k.first += dungeon[i][j];
                    k.second = min(k.first, k.second);
                }
            }
        }
        int ret = numeric_limits<int>::min();
        for(auto &i : hp[n-1]) {
            ret = max(ret, min(i.first, i.second));
        }
        return max(1, 1-ret);
    }
    //较慢
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        const size_t m = dungeon.size(), n = dungeon[0].size();
        vector<vector<pair<int, int>>> hp(n, vector<pair<int, int>>{{0, 0}});
        hp[0][0].first = hp[0][0].second = dungeon[0][0];
        for(size_t i = 1; i < n; i++) {
            hp[i][0].first = hp[i-1][0].first + dungeon[0][i];
            hp[i][0].second = min(hp[i][0].first, hp[i-1][0].second);
        }
        for(size_t i = 1; i < m; i++) {
            hp[0][0].first += dungeon[i][0];
            hp[0][0].second = min(hp[0][0].first, hp[0][0].second);
            for(size_t j = 1; j < n; j++) {
                vector<pair<int, int>> newhp;
                size_t k1 = 0, k2 = 0;
                int dolim = numeric_limits<int>::min();

                while(k1 < hp[j-1].size() && k2 < hp[j].size()) {
                    if(hp[j-1][k1].first == hp[j][k2].first) {
                        if(max(hp[j-1][k1].second, hp[j][k2].second) > dolim) {
                            dolim = max(hp[j-1][k1].second, hp[j][k2].second);
                            newhp.emplace_back(hp[j-1][k1].first, dolim);
                        }
                        k1++;
                        k2++;
                    } else if(hp[j-1][k1].first >= hp[j][k2].first) {
                        if(hp[j-1][k1].second > dolim) {
                            dolim = hp[j-1][k1].second;
                            newhp.emplace_back(hp[j-1][k1]);
                        }
                        k1++;
                    } else {
                        if(hp[j][k2].second > dolim) {
                            dolim = hp[j][k2].second;
                            newhp.emplace_back(hp[j][k2]);
                        }
                        k2++;
                    }
                }
                if(k1 < hp[j-1].size()) while(k1 < hp[j-1].size()) {
                    if(hp[j-1][k1].second > dolim) {
                        dolim = hp[j-1][k1].second;
                        newhp.emplace_back(hp[j-1][k1]);
                    }
                    k1++;
                } else while(k2 < hp[j].size()) {
                    if(hp[j][k2].second > dolim) {
                        dolim = hp[j][k2].second;
                        newhp.emplace_back(hp[j][k2]);
                    }
                    k2++;
                }
                swap(hp[j], newhp);
                for(auto &k : hp[j]) {
                    k.first += dungeon[i][j];
                    k.second = min(k.first, k.second);
                }
            }
        }
        int ret = numeric_limits<int>::min();
        for(auto &i : hp[n-1]) {
            ret = max(ret, min(i.first, i.second));
        }
        return max(1, 1-ret);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> dungeon = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5},
        };
        cout << Solution().calculateMinimumHP(dungeon) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> dungeon = {
            {100},
        };
        cout << Solution().calculateMinimumHP(dungeon) << endl;
    }
    return 0;
}
#endif