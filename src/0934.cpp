#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static void dfs1to2(vector<vector<int>>& A, int m, int n, int x, int y) {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return;
        if(A[x][y] != 1)
            return;
        A[x][y] = 2;
        dfs1to2(A, m, n, x-1, y);
        dfs1to2(A, m, n, x+1, y);
        dfs1to2(A, m, n, x, y-1);
        dfs1to2(A, m, n, x, y+1);
    }

    static void dfsdis(vector<int> &arr, int m, int n, int x, int y, int val) {
        if(x < 0 || x >= m || y < 0 || y >= n)
            return;
        if(arr[x*n+y] <= val && val != 0)
            return;
        arr[x*n+y] = val;
        dfsdis(arr, m, n, x-1, y, val+1);
        dfsdis(arr, m, n, x+1, y, val+1);
        dfsdis(arr, m, n, x, y-1, val+1);
        dfsdis(arr, m, n, x, y+1, val+1);
    }
    
public:
    int shortestBridge0(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int x = 0, y = 0;;) {
            if(A[x][y] == 1) {
                dfs1to2(A, m, n, x, y);
                break;
            } else if(++y == m) {
                x++;
                y = 0;
            }
        }
        vector<int> arr(m*n, 200);
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++)
                if(A[x][y] != 0) {
                    if(A[x][y] == 1) {
                        arr[x*n+y] = 0;
                    }
                }
        }
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(arr[x*n+y] == 0)
                    dfsdis(arr, m, n, x, y, 0);
            }
        }
        int ret = 201;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(A[x][y] == 2)
                    ret = min(ret, arr[x*n+y]);
            }
        }
        return ret-1;
    }
    int shortestBridge(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        for(int x = 0, y = 0;;) {
            if(A[x][y] == 1) {
                dfs1to2(A, m, n, x, y);
                break;
            } else if(++y == m) {
                x++;
                y = 0;
            }
        }
        vector<tuple<int, int, int>> que;
        for(int x = 0; x < m; x++) {
            for(int y = 0; y < n; y++) {
                if(A[x][y] == 1) {
                    // que.emplace_back(x, y, 0);
                    A[x][y] = 0;
                    que.emplace_back(x-1, y, -1);
                    que.emplace_back(x+1, y, -1);
                    que.emplace_back(x, y-1, -1);
                    que.emplace_back(x, y+1, -1);
                }
            }
        }
        for(int i = 0; i < que.size(); i++) {
            int tx = get<0>(que[i]);
            int ty = get<1>(que[i]);
            int tv = get<2>(que[i]);
            if(tx >= 0 && tx < m && ty >= 0 && ty < n) {
                if(A[tx][ty] == 2)
                    return -1-tv;
                else if(A[tx][ty] < tv || A[tx][ty] == 0) {
                    A[tx][ty] = tv;
                    que.emplace_back(tx-1, ty, tv-1);
                    que.emplace_back(tx+1, ty, tv-1);
                    que.emplace_back(tx, ty-1, tv-1);
                    que.emplace_back(tx, ty+1, tv-1);
                }
            }
        }
        return 200;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> A = {
            {0,1},
            {1,0},
        };
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> A = {
            {0,1,0},
            {0,0,0},
            {0,0,1},
        };
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << "3:" << endl;
    {
        vector<vector<int>> A = {
            {1,1,1,1,1},
            {1,0,0,0,1},
            {1,0,1,0,1},
            {1,0,0,0,1},
            {1,1,1,1,1},
        };
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << "4:" << endl;
    {
        vector<vector<int>> A = {
            {1,1,0,0,0},
            {1,0,0,0,0},
            {1,0,0,0,0},
            {0,0,0,1,1},
            {0,0,0,1,1},
        };
        cout << Solution().shortestBridge(A) << endl;
    }
    cout << "5:" << endl;
    {
        vector<vector<int>> A = {
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0},
            {0,0,0,0,1,1,0,0},
            {0,0,0,1,1,0,1,0},
            {0,0,0,0,0,1,1,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
            {0,0,0,0,0,0,0,0},
        };
        cout << Solution().shortestBridge(A) << endl;
    }
    return 0;
}
#endif