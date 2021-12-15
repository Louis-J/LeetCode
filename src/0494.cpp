#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findTargetSumWays0(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        // vector<pair<int, int>> dpn;
        unordered_map<int, int> dpn;
        dp[nums[0]] = 1;
        dp[-nums[0]] += 1;
        for(int i = 1; i != nums.size(); i++) {
            dpn.clear();
            for(auto &[j, k]: dp) {
                dpn[j+nums[i]] += k;
                dpn[j-nums[i]] += k;
            }
            swap(dp, dpn);
        }
        return dp[S];
    }
    int findTargetSumWays1(vector<int>& nums, int S) {
        if(S > 1000)
            return 0;
        vector<int> dp(2001);
        vector<pair<int, int>> dpn;
        dp[nums[0] + 1000] = 1;
        dp[-nums[0] + 1000] += 1;
        for(int i = 1; i != nums.size(); i++) {
            dpn.clear();
            for(int j = 0; j <= 2000; j++) {
                if (dp[j] > 0) {
                    dpn.emplace_back(j+nums[i], dp[j]);
                    dpn.emplace_back(j-nums[i], dp[j]);
                }
            }
            dp = vector<int>(2001);
            for(auto &[j, k]: dpn) {
                dp[j] += k;
            }
        }
        return dp[S+1000];
    }
    int findTargetSumWays2(vector<int>& nums, int S) {
        // int *dp = new int[2001];
        // for(int i = 0; i <= 2000; i++)
        //     dp[i] = 0;
        if(S > 1000)
            return 0;
        vector<int> dp1(2001);
        vector<int> dp2(2001);
        dp1[nums[0] + 1000] = 1;
        dp1[-nums[0] + 1000] += 1;
        for(int i = 1; i != nums.size(); i++) {
            for(int j = 0; j < 2001; j++) {
                if (dp1[j] > 0) {
                    dp2[j+nums[i]] += dp1[j];
                    dp2[j-nums[i]] += dp1[j];
                }
            }
            swap(dp1, dp2);
            fill(dp2.begin(), dp2.end(), 0);
        }
        return dp1[S+1000];
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        if(S > 1000)
            return 0;
        int dp1[2001] = {};
        int dp2[2001] = {};
        dp1[nums[0] + 1000] = 1;
        dp1[-nums[0] + 1000] += 1;
        for(int i = 1; i != nums.size(); i++) {
            for(int j = 0; j < 2001; j++) {
                if (dp1[j] > 0) {
                    dp2[j+nums[i]] += dp1[j];
                    dp2[j-nums[i]] += dp1[j];
                }
            }
            swap(dp1, dp2);
            fill(dp2, dp2+2001, 0);
        }
        return dp1[S+1000];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1, 1, 1, 1, 1};
        int S = 3;
        cout << Solution().findTargetSumWays(nums, S) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    //     int S = 3;
    //     cout << Solution().findTargetSumWays(nums, S) << endl;
    // }
    return 0;
}
#endif