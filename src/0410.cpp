#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

// class Solution {
//     class DA {
//         int *vec;
//         int n;
//     public:
//         DA(int m, int n): vec(new int[m*n]{}), n(n) {}
//         int &operator()(int i, int j) {
//             return vec[i*n+j];
//         }
//     };
//     // static inline int SA(vector<int>& nums, DA& dp, int m, int p, int sumr) {
//     //     int aim = sumr/m;
        
//     // }
// public:
//     int splitArray(vector<int>& nums, int m) {
//         if(m == 1 || m == n) {
//             int ret = nums[0];
//             for(int i = 1; i < nums.size(); i++)
//                 ret = max(ret, nums[i]);
//             return ret;
//         }
//         int sum = 0;
//         for(auto &i : nums)
//             sum += i;

//         // vector<vector<pair<int, int>>> dp(m);
//         DA dp(m, nums.size());
//         // int sumt = 0;
//         // for(int i = 0; sumt <= sum/m; i++)
//         //     sumt += nums[i];
//         // dp[0].emplace_back(i-1, sumt-nums[i]);
//         // dp[0].emplace_back(i, sumt);

//         // for(int i = 1; i < m; i++) {
//         //     for(int j = )
//         // }
//         // int from = (sum-1)/m;
//         return SA(nums, dp, m, nums.size(), sum);
//     }
// };
class Solution {
public:
    //O(n^2)
    int splitArray0(vector<int>& nums, int m) {
        vector<int> newnums;
        for(auto &i : nums)
            if(i)
                newnums.emplace_back(i);
        swap(newnums, nums);
        if(m == 1) {
            int sum = 0;
            for(auto &i : nums)
                sum += i;
            return sum;
        }
        if(m >= nums.size()) {
            int ret = nums[0];
            for(int i = 1; i < nums.size(); i++)
                ret = max(ret, nums[i]);
            return ret;
        }
        // int sum = 0;
        // for(auto &i : nums)
        //     sum += i;

        vector<int> dp(nums.size());
        // int dp[nums.size()];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            dp[i] = dp[i-1] + nums[i];

        for(int i = 2, j; i <= m; i++) {
            vector<int> newdp(nums.size());
            int idx = i-1;
            int newsum = 0;
            for(j = i-1; j < nums.size(); j++) {
                newsum += nums[j];
                while(idx < nums.size() && max(newsum - nums[idx], dp[idx]) <= max(newsum, dp[idx-1])) {
                    newsum -= nums[idx];
                    idx++;
                }
                newdp[j] = max(newsum, dp[idx-1]);
            }
            swap(dp, newdp);
        }
        return dp[dp.size()-1];
    }
    int splitArray(vector<int>& nums, int m) {
        vector<int> newnums;
        for(auto &i : nums)
            if(i)
                newnums.emplace_back(i);
        swap(newnums, nums);
        if(m == 1) {
            int sum = 0;
            for(auto &i : nums)
                sum += i;
            return sum;
        }
        if(m >= nums.size()) {
            int ret = nums[0];
            for(int i = 1; i < nums.size(); i++)
                ret = max(ret, nums[i]);
            return ret;
        }
        // int sum = 0;
        // for(auto &i : nums)
        //     sum += i;

        int dparr0[nums.size()];
        int dparr1[nums.size()];
        int *dp0 = dparr0;
        int *dp1 = dparr1;

        dp0[0] = nums[0];
        for(int i = 1; i < nums.size(); i++)
            dp0[i] = dp0[i-1] + nums[i];

        for(int i = 2, j; i <= m; i++) {
            int idx = i-1;
            int newsum = 0;
            for(j = i-1; j < nums.size(); j++) {
                newsum += nums[j];
                while(idx < nums.size() && max(newsum - nums[idx], dp0[idx]) <= max(newsum, dp0[idx-1])) {
                    newsum -= nums[idx];
                    idx++;
                }
                dp1[j] = max(newsum, dp0[idx-1]);
            }
            swap(dp0, dp1);
        }
        return dp0[nums.size()-1];
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {7, 2, 5, 10, 8};
    //     cout << Solution().splitArray(nums, 2) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {1, 4, 4};
    //     cout << Solution().splitArray(nums, 3) << endl;
    // }
    cout << " 3:" << endl;
    {
        vector<int> nums = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 350, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 450, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 550, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 650, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 700, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 750, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 800, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 850, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 900, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 950, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        cout << Solution().splitArray(nums, 50) << endl;
    }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {50, 100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 950, 0};
    //     cout << Solution().splitArray(nums, 17) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {7, 2, 5, 10, 8};
    //     cout << Solution().splitArray(nums, 2) << endl;
    // }
    return 0;
}
#endif