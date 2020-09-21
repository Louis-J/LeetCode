#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    //时间复杂度O(N*M)
    //空间复杂度O(N*M)
    static inline int MD1(string &word1, string &word2) {
        const auto N = word1.size(), M = word2.size();
        int dis[N+1][M+1];
        dis[0][0] = 0;
        for(size_t i = 1; i <= N; i++)
            dis[i][0] = i;
        for(size_t i = 1; i <= M; i++)
            dis[0][i] = i;
            
        for(size_t i = 1; i <= N; i++) {
            for(size_t j = 1; j <= M; j++) {
                auto d1 = word1[i-1] == word2[j-1] ? dis[i-1][j-1] : dis[i-1][j-1]+1;
                auto d2 = dis[i-1][j]+1;
                auto d3 = dis[i][j-1]+1;
                dis[i][j] = min({d1, d2, d3});
            }
        }
        // for(size_t i = 0; i <= N; i++) {
        //     for(size_t j = 0; j <= M; j++)
        //         cout << dis[i][j] << ' ';
        //     cout << endl;
        // }
        return dis[N][M];
    }
    //时间复杂度O(N*M)
    //空间复杂度O(M)
    static inline int MD2(string &word1, string &word2) {
        auto N = word1.size(), M = word2.size();
        int dis1ori[M+1], dis2ori[M+1];
        int *dis1 = dis1ori, *dis2 = dis2ori;

        for(size_t i = 0; i <= M; i++)
            dis1[i] = i;
            
        for(size_t i = 1; i <= N; i++) {
            dis2[0] = i;
            for(size_t j = 0; j < M; j++) {
                auto d1 = word1[i-1] == word2[j] ? dis1[j] : dis1[j]+1;
                auto d2 = dis1[j+1]+1;
                auto d3 = dis2[j]+1;
                dis2[j+1] = min({d1, d2, d3});
            }
            swap(dis1, dis2);
        }
        return dis1[M];
    }
public:
    int minDistance(string word1, string word2) {
        if(word1.size() == 0 || word2.size() == 0) {
            if(word1.size() == 0)
                return word2.size();
            else
                return word1.size();
        }
        return MD2(word1, word2);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        cout << Solution().minDistance("a", "b") << endl;
    }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {2, 2, 2, 0, 1};
    //     cout << Solution().findMin(nums) << endl;
    // }
    cout << "3:" << endl;
    {
        cout << Solution().minDistance("horse", "ros") << endl;
    }
    // cout << "4:" << endl;
    // {
    //     vector<int> nums = {1, 2, 3, 3, 3, 2, 1};
    //     cout << Solution().candy(nums) << endl;
    // }
    
    return 0;
}
#endif