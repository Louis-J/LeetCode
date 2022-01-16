#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    struct CQue {
        int *que;
        const int quesize = 0;
        int questart = 0;
        int quenum = 0;
        CQue(int size): que(new int[size]), quesize(size) {}
        int size() {
            return quenum;
        }
        int size() {
            return quenum;
        }
    };
    static inline vector<double> MSWS(vector<int> &nums, int k, int m) {
        CQue que(nk);
        for(auto &i : nums) {
            if(que.size() == nk) {
                nums[que.top()]
            }
        }
    }
    static inline vector<double> MSWD(vector<int> &nums, int nk) {
        
    }
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        if(k%2 == 0)
            return MSWS(nums, k+1/2);
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