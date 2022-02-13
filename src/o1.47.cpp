#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxValue0(vector<vector<int>>& grid) {
        for (int i = 1; i < grid[0].size(); i++)
            grid[0][i] += grid[0][i - 1];
        for (int i = 1; i < grid.size(); i++)
            grid[i][0] += grid[i - 1][0];
        for (int i = 1; i < grid.size(); i++)
            for (int j = 1; j < grid[i].size(); j++)
                grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
    int maxValue(vector<vector<int>>& grid) {
        int dp[grid[0].size()];
        dp[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); i++)
            dp[i] = dp[i - 1] + grid[0][i];
        for (int i = 1; i < grid.size(); i++) {
            dp[0] += grid[i][0];
            for (int j = 1; j < grid[i].size(); j++)
                dp[j] = grid[i][j] + max(dp[j], dp[j - 1]);
        }
        return dp[grid[0].size() - 1];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> grid = {
            {1,3,1},
            {1,5,1},
            {4,2,1},
        };
        cout << Solution().maxValue(grid) << endl;
    }
    cout << " 2:" << endl;
    {
    }
    return 0;
}
#endif