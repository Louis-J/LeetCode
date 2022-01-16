#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    int maxSum(vector<int> &nums) {
        auto dp1 = new int[nums.size() + 1];
        auto dp2 = new int[nums.size() + 1];

        dp1[0] = 0;

        for(int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            dp1[i + 1] = min(dp1[i], sum);
        }

        int back         = nums.size() - 1;
        dp2[nums.size()] = 0;
        for(int i = back, sum = 0; i >= 0; i--) {
            sum += nums[i];
            dp2[i] = min(dp2[i + 1], sum);
        }

        int maxNumMinus = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxNumMinus = min(maxNumMinus, dp1[i] + dp2[i]);
        }
        return maxNumMinus;
    }
    int minSum(vector<int> &nums) {
        auto dp1 = new int[nums.size() + 1];
        auto dp2 = new int[nums.size() + 1];

        dp1[0] = 0;

        for(int i = 0, sum = 0; i < nums.size(); i++) {
            sum += nums[i];
            dp1[i + 1] = max(dp1[i], sum);
        }

        int back         = nums.size() - 1;
        dp2[nums.size()] = 0;
        for(int i = back, sum = 0; i >= 0; i--) {
            sum += nums[i];
            dp2[i] = max(dp2[i + 1], sum);
        }

        int minNumMinus = 0;
        for(int i = 0; i < nums.size(); i++) {
            minNumMinus = max(minNumMinus, dp1[i] + dp2[i]);
        }
        return minNumMinus;
    }

public:
    int maxAbsoluteSum0(vector<int> &nums) {
        int sum = 0;
        for(auto &i : nums) sum += i;
        return max(abs(sum - maxSum(nums)), abs(sum - minSum(nums)));
    }
    int maxAbsoluteSum(vector<int> &nums) {
        int  sum;
        auto dp = new tuple<int, int, int, int>[nums.size() + 1];

        get<0>(dp[0]) = 0;
        get<1>(dp[0]) = 0;
        sum           = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            get<0>(dp[i + 1]) = min(get<0>(dp[i]), sum);
            get<1>(dp[i + 1]) = max(get<1>(dp[i]), sum);
        }

        int back                = nums.size() - 1;
        get<2>(dp[nums.size()]) = 0;
        get<3>(dp[nums.size()]) = 0;
        sum                     = 0;
        for(int i = back; i >= 0; i--) {
            sum += nums[i];
            get<2>(dp[i]) = min(get<2>(dp[i + 1]), sum);
            get<3>(dp[i]) = max(get<3>(dp[i + 1]), sum);
        }

        int maxNumMinus = 0;
        int minNumMinus = 0;
        for(int i = 0; i < nums.size(); i++) {
            maxNumMinus = min(maxNumMinus, get<0>(dp[i]) + get<2>(dp[i]));
            minNumMinus = max(minNumMinus, get<1>(dp[i]) + get<3>(dp[i]));
        }
        return max(abs(sum - maxNumMinus), abs(sum - minNumMinus));
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1, -3, 2, 3, -4};
        cout << Solution().maxAbsoluteSum(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {2, -5, 1, -4, 3, -2};
        cout << Solution().maxAbsoluteSum(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        // vector<int> nums = {1,-3,2,3,-4};
        // cout << Solution().maxAbsoluteSum(nums) << endl;
    }
    return 0;
}
#endif