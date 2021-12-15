#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif
//不难
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        if(nums.size() == k*3)
            return vector<int>{0, k-1, 2*k-1};
        if(k == 1) {
            int m1 = 0, m2, m3 = 0;
            for(int i = 1; i < 3; i++) {
                if(nums[i] > nums[m3])
                    m3 = i;
                else if(nums[i] <= nums[m1])
                    m1 = i;
            }
            m2 = 3-m1-m3;

            for(int i = 3; i < nums.size(); i++) {
                if(nums[i] > nums[m1]) {
                    m1 = i;
                    if(nums[m1] > nums[m2]) {
                        swap(m1, m2);
                        if(nums[m2] > nums[m3])
                            swap(m2, m3);
                    }
                }
            }
            int r1 = min({m1, m2, m3});
            int r3 = max({m1, m2, m3});
            int r2 = m1+m2+m3-r1-r3;
            return vector<int>{r1, r2, r3};
        }

        vector<int> sums(nums.size()-k+1);
        int sum = 0;
        for(int i = 0; i < k; i++)
            sum += nums[i];
        sums[0] = sum;
        for(int i = k; i < nums.size(); i++) {
            sum += nums[i];
            sum -= nums[i-k];
            sums[i-k+1] = sum;
        }
        // return sums;

        int m3 = 0;
        for(int i = 1; i < sums.size(); i++) {
            if(sums[i] > sums[m3])
                m3 = i;
        }
        int m2;
        if(m3 < k)
            m2 = m3+k;
        else
            m2 = 0;

        for(int i = 0; i <= m3-k; i++) {
            if(sums[i] > sums[m2])
                m2 = i;
        }
        for(int i = m3+k; i < sums.size(); i++) {
            if(sums[i] > sums[m2])
                m2 = i;
        }
        sum = sums[m2] + sums[m3];
        for
        // int max3 = 0;
        // int maxsum3 = 0;
        // int sum = 0;
        // for(int i = 0; i < 3*k; i++)
        //     sum += nums[i];

        // maxsum3 = sum;
        // for(int i = 3*k; i < nums.size(); i++) {
        //     sum += nums[i];
        //     sum -= nums[i-3*k];
        //     if(sum > maxsum3) {
        //         max3 = i-3*k;
        //         maxsum3 = sum;
        //     }
        // }
        
        // int max2 = 0;
        // int maxsum2 = 0;
        // sum = 0;
        // for(int i = 0; i < 2*k; i++)
        //     sum += nums[i];

        // maxsum2 = sum;
        // for(int i = 2*k; i < nums.size(); i++) {
        //     sum += nums[i];
        //     sum -= nums[i-2*k];
        //     if(sum > maxsum2) {
        //         max2 = i-2*k;
        //         maxsum2 = sum;
        //     }
        // }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1,2,1,2,6,7,5,1};
        int k = 2;
        cout << Solution().maxSumOfThreeSubarrays(nums, k) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     cout << Solution().isSymmetric(TreeNode::CreateLev({1, 2, 2, nullopt, 3, nullopt, 3})) << endl;
    // }
    return 0;
}
#endif