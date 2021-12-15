#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    vector<int> tag1, tag2;
    int m, n;
    int &get1(int x, int y) {
        return tag1[x*n+y];
    }
    int &get2(int x, int y) {
        return tag2[x*n+y];
    }

    void dfs1(vector<vector<int>>& matrix, int x, int y) {
        // cout << x << ',' << y;
        // cout << 'A';
        if(x > 0 && get1(x-1, y) == 0 && matrix[x][y] <= matrix[x-1][y]) {
            get1(x-1, y) = 1;
            dfs1(matrix, x-1, y);
        }
        // cout << 'B';
        if(x < m-1 && get1(x+1, y) == 0 && matrix[x][y] <= matrix[x+1][y]) {
            get1(x+1, y) = 1;
            dfs1(matrix, x+1, y);
        }
        // cout << 'C';
        if(y > 0 && get1(x, y-1) == 0 && matrix[x][y] <= matrix[x][y-1]) {
            get1(x, y-1) = 1;
            dfs1(matrix, x, y-1);
        }
        // cout << 'D';
        if(y < n-1 && get1(x, y+1) == 0 && matrix[x][y] <= matrix[x][y+1]) {
            get1(x, y+1) = 1;
            dfs1(matrix, x, y+1);
        }
        // cout << 'E';
        // cout << endl;
    }
    
    void dfs2(vector<vector<int>>& matrix, int x, int y) {
        if(x > 0 && get2(x-1, y) == 0 && matrix[x][y] <= matrix[x-1][y]) {
            get2(x-1, y) = 1;
            dfs2(matrix, x-1, y);
        }
        if(x < m-1 && get2(x+1, y) == 0 && matrix[x][y] <= matrix[x+1][y]) {
            get2(x+1, y) = 1;
            dfs2(matrix, x+1, y);
        }
        if(y > 0 && get2(x, y-1) == 0 && matrix[x][y] <= matrix[x][y-1]) {
            get2(x, y-1) = 1;
            dfs2(matrix, x, y-1);
        }
        if(y < n-1 && get2(x, y+1) == 0 && matrix[x][y] <= matrix[x][y+1]) {
            get2(x, y+1) = 1;
            dfs2(matrix, x, y+1);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return vector<vector<int>>{};

        m = matrix.size(), n = matrix[0].size();
        tag1.resize(m*n);
        tag2.resize(m*n);

        // cout << 'A';

        for(int y = 0; y < n; y++)
            get1(0, y) = 1;
        for(int x = 1; x < m; x++)
            get1(x, 0) = 1;
            
        // cout << 'B';

        for(int y = 0; y < n; y++)
            get2(m-1, y) = 1;
        for(int x = 0; x < m-1; x++)
            get2(x, n-1) = 1;

        // cout << 'C';

        for(int y = 1; y < n; y++)
            dfs1(matrix, 0, y);
        for(int x = 1; x < m; x++)
            dfs1(matrix, x, 0);

        // cout << 'D';

        for(int y = 0; y < n-1; y++)
            dfs2(matrix, m-1, y);
        for(int x = 0; x < m-1; x++)
            dfs2(matrix, x, n-1);

        // cout << endl;
        // for(int x = 0; x < m; x++) {
        //     for(int y = 0; y < n; y++) {
        //         cout << get1(x, y);
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        
        // for(int x = 0; x < m; x++) {
        //     for(int y = 0; y < n; y++) {
        //         cout << get2(x, y);
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        vector<vector<int>> ret;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(get1(x, y) && get2(x, y))
                    ret.emplace_back(vector<int>{x, y});
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix  = {
            {1,2,2,3,5},
            {3,2,3,4,4},
            {2,4,5,3,1},
            {6,7,1,4,5},
            {5,1,1,2,4},
        };
        cout << Solution().pacificAtlantic(matrix) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix  = {
            {1,2,2,3,5},
            {3,2,3,4,4},
            {2,4,5,3,1},
            {6,7,1,4,5},
            {5,1,1,2,4},
        };
        cout << Solution().pacificAtlantic(matrix) << endl;
    }
    return 0;
}
#endif