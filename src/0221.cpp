#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maximalSquare0(vector<vector<char>> &matrix) {
        int                          ret = 0;
        vector<tuple<int, int, int>> dp(matrix[0].size());  // weight, height, square
        for(auto &vec : matrix) {
            if(vec[0] == '0')
                get<0>(dp[0]) = 0;
            else
                get<0>(dp[0]) = 1;
            for(int i = 1; i < matrix[0].size(); i++) {
                if(vec[i] == '0')
                    get<0>(dp[i]) = 0;
                else
                    get<0>(dp[i]) = get<0>(dp[i - 1]) + 1;
            }
            for(int i = matrix[0].size() - 1; i > 0; i--) {
                if(vec[i] == '0') {
                    get<1>(dp[i]) = 0;
                    get<2>(dp[i]) = 0;
                } else {
                    get<1>(dp[i])++;
                    get<2>(dp[i]) = min({get<0>(dp[i]), get<1>(dp[i]), get<2>(dp[i - 1]) + 1});
                    ret           = max(ret, get<2>(dp[i]));
                }
            }
            if(vec[0] == '0') {
                get<1>(dp[0]) = 0;
                get<2>(dp[0]) = 0;
            } else {
                get<1>(dp[0])++;
                get<2>(dp[0]) = 1;
                ret           = max(ret, 1);
            }
        }
        return ret * ret;
    }
    int maximalSquare(vector<vector<char>> &matrix) {
        int         ret = 0;
        vector<int> dp1(matrix[0].size());
        vector<int> dp2(matrix[0].size());
        for(auto &vec : matrix) {
            if(vec[0] == '0')
                dp2[0] = 0;
            else {
                dp2[0] = 1;
                ret    = max(ret, 1);
            }
            for(int i = 1; i < matrix[0].size(); i++) {
                if(vec[i] == '0')
                    dp2[i] = 0;
                else {
                    dp2[i] = min({dp2[i - 1], dp1[i - 1], dp1[i]}) + 1;
                    ret    = max(ret, dp2[i]);
                }
            }
            swap(dp1, dp2);
        }
        return ret * ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<vector<char>> matrix = {
    //         {'1', '0', '1', '0', '0'},
    //         {'1', '0', '1', '1', '1'},
    //         {'1', '1', '1', '1', '1'},
    //         {'1', '0', '0', '1', '0'},
    //     };
    //     cout << Solution().maximalSquare(matrix) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<vector<char>> matrix = {
    //         {'0', '1'},
    //         {'1', '0'},
    //     };
    //     cout << Solution().maximalSquare(matrix) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     vector<vector<char>> matrix = {
    //         {'1'},
    //     };
    //     cout << Solution().maximalSquare(matrix) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     vector<vector<char>> matrix = {
    //         {'0'},
    //     };
    //     cout << Solution().maximalSquare(matrix) << endl;
    // }
    cout << "5:" << endl;
    {
        vector<vector<char>> matrix = {
            {'1', '1'},
            {'1', '1'},
        };
        cout << Solution().maximalSquare(matrix) << endl;
    }
    return 0;
}
#endif