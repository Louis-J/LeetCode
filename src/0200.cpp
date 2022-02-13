#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int                    num = 0;
        vector<pair<int, int>> que;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    num++;
                    grid[i][j] = '0';
                    que.emplace_back(i, j);
                    while(que.size() != 0) {
                        int x = que.back().first;
                        int y = que.back().second;
                        que.pop_back();
                        if(x > 0 && grid[x - 1][y] == '1') {
                            grid[x - 1][y] = '0';
                            que.emplace_back(x - 1, y);
                        }
                        if(x < grid.size() - 1 && grid[x + 1][y] == '1') {
                            grid[x + 1][y] = '0';
                            que.emplace_back(x + 1, y);
                        }
                        if(y > 0 && grid[x][y - 1] == '1') {
                            grid[x][y - 1] = '0';
                            que.emplace_back(x, y - 1);
                        }
                        if(y < grid[0].size() - 1 && grid[x][y + 1] == '1') {
                            grid[x][y + 1] = '0';
                            que.emplace_back(x, y + 1);
                        }
                    }
                }
            }
        return num;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<char>> grid = {
            {'1', '1', '1', '1', '0'},
            {'1', '1', '0', '1', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '0', '0', '0'},
        };
        cout << Solution().numIslands(grid) << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<char>> grid = {
            {'1', '1', '0', '0', '0'},
            {'1', '1', '0', '0', '0'},
            {'0', '0', '1', '0', '0'},
            {'0', '0', '0', '1', '1'},
        };
        cout << Solution().numIslands(grid) << endl;
    }

    return 0;
}
#endif