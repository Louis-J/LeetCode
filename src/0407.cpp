#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static inline void digui0(vector<vector<int>>& hm, vector<vector<int>>& wm,
        const size_t m, const size_t n, const size_t i, const size_t j) {
        int edgemin = min({wm[i-1][j], wm[i+1][j], wm[i][j-1], wm[i][j+1]});
        int newwm = max(hm[i][j], edgemin);
        if(wm[i][j] > newwm) {
            wm[i][j] = newwm;
            if(i-1 > 0 && wm[i][j] < wm[i-1][j])
                digui0(hm, wm, m, n, i-1, j);
            if(i+1 < m && wm[i][j] < wm[i+1][j])
                digui0(hm, wm, m, n, i+1, j);
            if(j-1 > 0 && wm[i][j] < wm[i][j-1])
                digui0(hm, wm, m, n, i, j-1);
            if(j+1 < n && wm[i][j] < wm[i][j+1])
                digui0(hm, wm, m, n, i, j+1);
        }
    }
    static inline void digui1(int *hm, int *wm,
        const size_t m, const size_t n, const size_t i, const size_t j) {
        const size_t posi = i*n+j;
        int edgemin = min({wm[posi-n], wm[posi+n], wm[posi-1], wm[posi+1]});
        int newwm = max(hm[posi], edgemin);
        if(wm[posi] > newwm) {
            wm[posi] = newwm;
            if(i-1 > 0 && wm[posi] < wm[posi-m])
                digui1(hm, wm, m, n, i-1, j);
            if(i+2 < m && wm[posi] < wm[posi+m])
                digui1(hm, wm, m, n, i+1, j);
            if(j-1 > 0 && wm[posi] < wm[posi-1])
                digui1(hm, wm, m, n, i, j-1);
            if(j+2 < n && wm[posi] < wm[posi+1])
                digui1(hm, wm, m, n, i, j+1);
        }
    }
public:
    int trapRainWater0(vector<vector<int>>& heightMap) {
        size_t m = heightMap.size()-1;
        size_t n = heightMap[0].size()-1;
        // vector<vector<int>> wm(heightMap);
        vector<vector<int>> wm(m+1, vector<int>(n+1, INT_MAX));
        for(size_t i = 1; i < m; i++) {
            wm[i][0] = heightMap[i][0];
            wm[i][n] = heightMap[i][n];
        }
        for(size_t i = 0; i <= n; i++) {
            wm[0][i] = heightMap[0][i];
            wm[m][i] = heightMap[m][i];
        }
        // for(size_t i = 1; i < m; i++) {
        //     for(size_t j = 1; j < n; j++) {
        //         if(wm[i][j] < heightMap[i-1][j])
        //             wm[i][j] = heightMap[i-1][j];
        //         if(wm[i][j] < heightMap[i+1][j])
        //             wm[i][j] = heightMap[i+1][j];
        //         if(wm[i][j] < heightMap[i][j-1])
        //             wm[i][j] = heightMap[i][j-1];
        //         if(wm[i][j] < heightMap[i][j+1])
        //             wm[i][j] = heightMap[i][j+1];
        //     }
        // }
        
        // cout << endl;
        // for(size_t i = 1; i < m; i++) {
        //     for(size_t j = 1; j < n; j++)
        //         cout << wm[i][j] << ' ';
        //     cout << endl;
        // }
        for(size_t i = 1; i < m; i++)
            for(size_t j = 1; j < n; j++)
                if(wm[i][j] > heightMap[i][j])
                    digui0(heightMap, wm, m, n, i, j);

        // for(size_t i = 1; i < m; i++) {
        //     for(size_t j = 1; j < n; j++)
        //         cout << wm[i][j] << ' ';
        //     cout << endl;
        // }

        int ret = 0;
        for(size_t i = 1; i < m; i++)
            for(size_t j = 1; j < n; j++)
                ret += wm[i][j] - heightMap[i][j];
        return ret;
    }
    //把多维vector数组换成用一维数组模拟的二维数组，提高性能
    int trapRainWater(vector<vector<int>>& heightMap) {
        size_t m = heightMap.size();
        size_t n = heightMap[0].size();

        int *hm = new int[m*n];
        int *wm = new int[m*n];
        for(size_t i = 0; i < m; i++) {
            for(size_t j = 0; j < n; j++) {
                hm[i*n+j] = heightMap[i][j];
                wm[i*n+j] = INT_MAX;
            }
        }
        for(size_t i = 1; i < m-1; i++) {
            wm[i*n+0] = hm[i*n+0];
            wm[i*n+n-1] = hm[i*n+n-1];
        }
        for(size_t i = 0; i < n; i++) {
            wm[0*n+i] = hm[0*n+i];
            wm[(m-1)*n+i] = hm[(m-1)*n+i];
        }

        // cout << endl;
        // for(size_t i = 1; i < m-1; i++) {
        //     for(size_t j = 1; j < n-1; j++)
        //         cout << wm[i*n+j] << ' ';
        //     cout << endl;
        // }

        for(size_t i = 1; i < m-1; i++)
            for(size_t j = 1; j < n-1; j++)
                if(wm[i*n+j] > hm[i*n+j])
                    digui1(hm, wm, m, n, i, j);

        // for(size_t i = 1; i < m-1; i++) {
        //     for(size_t j = 1; j < n-1; j++)
        //         cout << wm[i*n+j] << ' ';
        //     cout << endl;
        // }
        int ret = 0;
        for(size_t i = 1; i < m-1; i++)
            for(size_t j = 1; j < n-1; j++)
                ret += wm[i*n+j] - hm[i*n+j];
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> heightMap = {
            {1, 4, 3, 1, 3, 2},
            {3, 2, 1, 3, 2, 4},
            {2, 3, 3, 2, 3, 1},
        };
        cout << Solution().trapRainWater(heightMap) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> heightMap = {
            {9, 9, 9, 9, 9},
            {9, 2, 1, 2, 9},
            {9, 2, 8, 2, 9},
            {9, 2, 3, 2, 9},
            {9, 9, 9, 9, 9},
        };
        cout << Solution().trapRainWater(heightMap) << endl;
    }
    // cout << " 3:" << endl;
    // {
    //     cout << Solution().numberToWords(1234567) << endl;
    // }
}
#endif