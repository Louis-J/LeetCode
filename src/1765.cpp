#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
        vector<vector<int>> ret;
        int                 m = isWater.size();
        int                 n = isWater[0].size();

        shared_ptr<int[]> arr(new int[m * n]);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(isWater[i][j])
                    arr[i * n + j] = 0;
                else
                    arr[i * n + j] = 1;
            }
        }

        

        for()
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<vector<int>> isWater = {
            {0, 1},
            {0, 0},
        };
        cout << Solution().highestPeak(isWater) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> isWater = {
            {0, 0, 1},
            {1, 0, 0},
            {0, 0, 0},
        };
        cout << Solution().highestPeak(isWater) << endl;
    }
    cout << " 3:" << endl;
    {}
    return 0;
}
#endif