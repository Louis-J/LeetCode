#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    bool canPartition0(vector<int>& nums) {
        int sum2 = 0;
        for(auto &i: nums)
            sum2 += i;
        if(sum2%2 == 1)
            return false;
        sum2 /= 2;
        int n = nums.size();
        set<int> reach;
        vector<int> next;
        for(auto &i: nums) {
            if(i == sum2)
                return true;
            else if(i < sum2)
                next.emplace_back(i);
            for(auto it = reach.begin(); it != reach.end(); it++) {
                int num = *it;
                if(num+i == sum2)
                    return true;
                else if(num+i < sum2)
                    next.emplace_back(num+i);
            }
            reach.insert(next.begin(), next.end());
            next.clear();
        }
        return false;
    }
    bool canPartition1(vector<int>& nums) {
        int sum2 = 0;
        for(auto &i: nums)
            sum2 += i;
        if(sum2%2 == 1)
            return false;
        sum2 /= 2;
        int n = nums.size();
        vector<unsigned char> reach(sum2, 255);
        for(int i = 0; i < n; i++) {
            int num = nums[i];
            if(num == sum2)
                return true;
            if(num < sum2) {
                if(reach[num] == 255)
                    reach[num] = i;
                for(int j = 0; j < sum2; j++) {
                    if(reach[j] < i) {
                        if(j+num == sum2)
                            return true;
                        else if(j+num < sum2 && reach[j+num] == 255)
                            reach[j+num] = i;
                    }
                }
            }
        }
        return false;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0)
            return false;

        int target = sum/2;

        vector<char> dp(target+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; ++i) {
            int value = nums[i-1];
            if(value <= target) {
                if(dp[target-value])
                    return true;
                for(int j = target-1; j >= value; --j)
                    dp[j] |= dp[j-value];
            }
        }
        return dp[target];
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {1, 5, 11, 5};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {1, 2, 3, 5};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    cout << " 3:" << endl;
    {
        vector<int> nums = {1, 1};
        cout << Solution().canPartition(nums) << endl;
    }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {1, 2, 5};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> nums = {2, 2, 3, 5};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    // cout << " 6:" << endl;
    // {
    //     vector<int> nums = {1, 1, 1, 1};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    // cout << " 7:" << endl;
    // {
    //     vector<int> nums = {14, 9, 8, 4, 3, 2};
    //     cout << Solution().canPartition(nums) << endl;
    // }
    return 0;
}
#endif