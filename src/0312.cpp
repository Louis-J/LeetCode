#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

static auto __sync__ = []() {
    ios::sync_with_stdio(false);
    // cin.tie(0);
    return 0;
}();
class Solution {
public:
    // int maxCoins(vector<int>& nums) {
    //     nums.insert(nums.begin(), 1);
    //     nums.emplace_back(1);
    //     const size_t Len = nums.size();
        
    //     int *dp = new int[Len*Len];
    //     for(int i = 1; i < Len-1; i++)
    //         dp[i*Len+i] = nums[i-1] * nums[i] * nums[i+1];

    //     for(int i = 1; i < Len-1; i++) {
    //         for(int j = 1; j < Len-i-1; j++) {
    //             dp[j*Len+j+i] = max(  dp[(j+1)*Len+j+i] + nums[j-1]*nums[j]*nums[j+i+1], 
    //                                 dp[j*Len+j+i-1] + nums[j-1]*nums[j+i]*nums[j+i+1]);
    //             for(int k = j+1; k <= j+i-1; k++) {
    //                 dp[j*Len+j+i] = max(dp[j*Len+j+i], dp[j*Len+k-1]+dp[(k+1)*Len+j+i]+nums[j-1]*nums[k]*nums[j+i+1]);
    //             }
    //         }
    //     }
    //     return dp[1*Len+Len-2];
    // }
    int maxCoins(vector<int>& nums) {
        const size_t Len = nums.size()+2;
        
        int *nnums = new int[Len];
        nnums[0] = nnums[Len-1] = 1;
        copy(nums.begin(), nums.end(), nnums+1);

        int *dp = new int[Len*Len];
        for(int i = 1; i < Len-1; i++)
            dp[i*Len+i] = nnums[i-1] * nnums[i] * nnums[i+1];

        for(int i = 1; i < Len-1; i++) {
            for(int j = 1; j < Len-i-1; j++) {
                dp[j*Len+j+i] = max(dp[(j+1)*Len+j+i] + nnums[j-1]*nnums[j]*nnums[j+i+1], 
                                    dp[j*Len+j+i-1] + nnums[j-1]*nnums[j+i]*nnums[j+i+1]);
                for(int k = j+1; k <= j+i-1; k++) {
                    dp[j*Len+j+i] = max(dp[j*Len+j+i], dp[j*Len+k-1]+dp[(k+1)*Len+j+i]+nnums[j-1]*nnums[k]*nnums[j+i+1]);
                }
            }
        }

        int ret = dp[1*Len+Len-2];

        delete[] nnums;
        delete[] dp;

        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {3,1,5,8};
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {9,76,64,21};
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {35,16,83,87,84,59,48,41};
        cout << Solution().maxCoins(nums) << endl;
    }
    cout << "4:" << endl;
    {
        vector<int> nums = {35,16,83,87,84,59,48,41,20,54};
        cout << Solution().maxCoins(nums) << endl;
    }
    return 0;
}
#endif

// 3
// 18
// 70 15+120+