#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    //动态规划
    //思路: 初始第i个省份标记为i, 每次加入一个省, 然后尝试找到和此省连接的所有省, 并将这些省标记改为相同的最小省的值
    //统计时计算标记和本省序列相同的省的数量
    static int dtgh(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<int> prov(len);
        for(int i = 0; i < len; i++)
            prov[i] = i;
        
        for(int i = 1; i < len; i++) {
            for(int j = 0; j < i; j++) {
                if(isConnected[i][j] == 1 && prov[j] != prov[i]) {
                    if(prov[i] == i)
                        prov[i] = prov[j];
                    else {
                        int orig = max(prov[i], prov[j]);
                        int tran = prov[i]+prov[j]-orig;
                        for(int k = 0; k < i; k++) {
                            if(prov[k] == orig)
                                prov[k] = tran;
                        }
                    }
                }
            }
        }
        int ret = 1;
        for(int i = 1; i < len; i++)
            if(prov[i] == i)
                ret++;
        return ret;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        return dtgh(isConnected);
    }
};

class Solution1 {
public:
    void dfs(vector<vector<int>>& isConnected, int r) {
        for(int i = 0; i < isConnected.size(); ++i) {
            if(isConnected[r][i]) {
                isConnected[r][i] = 0;
                if(r != i)
                    dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.size() == 1) return 1;
        int circle = 0;
        for(int i = 0; i < isConnected.size(); ++i) {
            if(isConnected[i][i]) {
                ++circle;
                isConnected[i][i] = 0;
                dfs(isConnected, i);
            }
        }
        return circle;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<vector<int>> isConnected  = {
    //         {1,1,0},
    //         {1,1,0},
    //         {0,0,1},
    //     };
    //     cout << Solution().findCircleNum(isConnected) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<vector<int>> isConnected  = {
    //         {1,0,0},
    //         {0,1,0},
    //         {0,0,1},
    //     };
    //     cout << Solution().findCircleNum(isConnected) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<vector<int>> isConnected  = {
    //         {1,0,0,1},
    //         {0,1,1,0},
    //         {0,1,1,1},
    //         {1,0,1,1},
    //     };
    //     cout << Solution().findCircleNum(isConnected) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<vector<int>> isConnected  = {
    //         {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    //         {0,1,0,1,0,0,0,0,0,0,0,0,0,1,0},
    //         {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    //         {0,1,0,1,0,0,0,1,0,0,0,1,0,0,0},
    //         {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
    //         {0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    //         {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
    //         {0,0,0,1,0,0,0,1,1,0,0,0,0,0,0},
    //         {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
    //         {1,0,0,0,0,0,0,0,0,1,0,0,0,0,0},
    //         {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0},
    //         {0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    //         {0,0,0,0,1,0,0,0,0,0,0,0,1,0,0},
    //         {0,1,0,0,0,0,0,0,0,0,0,0,0,1,0},
    //         {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    //     };
    //     cout << Solution().findCircleNum(isConnected) << endl;
    // }
    cout << " 5:" << endl;
    {
        vector<vector<int>> isConnected  = {
            {1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
            {1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,0,0,1,0,1,1,0,0,0,0,0,0,0,0},
            {0,0,0,0,1,0,0,0,0,1,1,0,0,0,0},
            {0,0,0,1,0,1,0,0,0,0,1,0,0,0,0},
            {0,0,0,1,0,0,1,0,1,0,0,0,0,1,0},
            {1,0,0,0,0,0,0,1,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,1,1,0,0,0,0,1,0},
            {0,0,0,0,1,0,0,0,0,1,0,1,0,0,1},
            {0,0,0,0,1,1,0,0,0,0,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,1,1,1,0,0,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
            {0,0,0,0,0,0,1,0,1,0,0,0,0,1,0},
            {0,0,0,0,0,0,0,0,0,1,0,0,0,0,1},
        };
        cout << Solution().findCircleNum(isConnected) << endl;
    }
    return 0;
}
#endif