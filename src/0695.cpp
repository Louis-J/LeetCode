#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution0 {
    static int digui(vector<vector<int>>& grid, int x, int y) {
        int n = 1;
        grid[x][y] = 0;
        if(x > 0 && grid[x-1][y] == 1)
            n += digui(grid, x-1, y);
        if(y > 0 && grid[x][y-1] == 1)
            n += digui(grid, x, y-1);

        if(x < grid.size()-1 && grid[x+1][y] == 1)
            n += digui(grid, x+1, y);
        if(y < grid[0].size()-1 && grid[x][y+1] == 1)
            n += digui(grid, x, y+1);
        return n;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxa = 0;
        for(int x = 0; x < grid.size(); x++)
            for(int y = 0; y < grid[0].size(); y++)
                if(grid[x][y] == 1)
                    maxa = max(maxa, digui(grid, x, y));
        return maxa;
    }
};

class Solution1 {
    int *agrid = nullptr;
    // vector<int> agrid;
    int W, H;
    int W1, H1;
    inline int &get(int x, int y) {
        return agrid[H*x+y];
    }
    int digui(int x, int y) {
        int n = 1;
        get(x, y) = 0;
        if(x > 0 && get(x-1, y) == 1)
            n += digui(x-1, y);
        if(y > 0 && get(x, y-1) == 1)
            n += digui(x, y-1);

        if(x < W1 && get(x+1, y) == 1)
            n += digui(x+1, y);
        if(y < H1 && get(x, y+1) == 1)
            n += digui(x, y+1);
        return n;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        W = grid.size();
        H = grid[0].size();
        W1 = W-1;
        H1 = H-1;
        agrid = new int[W*H];
        // agrid.resize(W*H);

        for(int x = 0; x < W; x++)
            for(int y = 0; y < H; y++)
                get(x, y) = grid[x][y];

        int maxa = 0;
        for(int x = 0; x < W; x++)
            for(int y = 0; y < H; y++)
                if(get(x, y) == 1)
                    maxa = max(maxa, digui(x, y));
        // delete agrid;
        return maxa;
    }
};

class Solution2 {
    int *agrid = nullptr;
    // vector<int> agrid;
    int W, H;
    inline int &get(int x, int y) {
        return agrid[H*x+y];
    }
    int dfs(int x, int y) {
        if (x < 0 || x >= W || y < 0 || y >= H || get(x, y) == 0)
            return 0;
        // 修改grid为0避免重复遍历
        get(x, y) = 0;
        // 本身点就是面积1
        return 1 + dfs(x+1, y) + dfs(x, y+1) + dfs(x-1, y) + dfs(x, y-1); 
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        W = grid.size();
        H = grid[0].size();
        agrid = new int[W*H];

        for(int x = 0; x < W; x++)
            for(int y = 0; y < H; y++)
                get(x, y) = grid[x][y];

        int maxa = 0;
        for(int x = 0; x < W; x++)
            for(int y = 0; y < H; y++)
                if(get(x, y) == 1)
                    maxa = max(maxa, dfs(x, y));

        return maxa;
    }
};

class Solution {
    vector<vector<int>> agrid;
    int W, H;
    inline int &get(int x, int y) {
        return agrid[x][y];
    }
    int dfs(int x, int y) {
        if (x < 0 || x >= W || y < 0 || y >= H || get(x, y) == 0)
            return 0;
        // 修改grid为0避免重复遍历
        get(x, y) = 0;
        // 本身点就是面积1
        return 1 + dfs(x+1, y) + dfs(x, y+1) + dfs(x-1, y) + dfs(x, y-1); 
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        W = grid.size();
        H = grid[0].size();
        agrid = grid;

        int maxa = 0;
        for(int x = 0; x < W; x++)
            for(int y = 0; y < H; y++)
                if(get(x, y) == 1)
                    maxa = max(maxa, dfs(x, y));

        return maxa;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> grid = {
            {0,0,1,0,0,0,0,1,0,0,0,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,1,1,0,1,0,0,0,0,0,0,0,0},
            {0,1,0,0,1,1,0,0,1,0,1,0,0},
            {0,1,0,0,1,1,0,0,1,1,1,0,0},
            {0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,1,1,0,0,0,0}
        };
        cout << Solution().maxAreaOfIsland(grid) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> grid = {
            {1,0,1},
            {1,1,1},
            {0,0,1},
        };
        cout << Solution().maxAreaOfIsland(grid) << endl;
    }
    return 0;
}
#endif