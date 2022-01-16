#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int trgt) {
        vector<int> idx(nums.size());
        int idn = 0;
        for(auto &i : idx)
            i = idn++;
        sort(idx.begin(), idx.end(), [&nums](size_t i1, size_t i2) {return nums[i1] < nums[i2];});

        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size()-1;
        if(nums[i] + nums[j] == trgt)
            return {idx[i], idx[j]};
        else if(nums[i] + nums[j] < trgt)
            while(1) {
                while(nums[i] + nums[j] < trgt) {
                    i++;
                }
                if(nums[i] + nums[j] == trgt)
                    return {idx[i], idx[j]};
                while(nums[i] + nums[j] > trgt) {
                    j--;
                }
                if(nums[i] + nums[j] == trgt)
                    return {idx[i], idx[j]};
            }
        else
            while(1) {
                while(nums[i] + nums[j] > trgt) {
                    j--;
                }
                if(nums[i] + nums[j] == trgt)
                    return {idx[i], idx[j]};
                while(nums[i] + nums[j] < trgt) {
                    i++;
                }
                if(nums[i] + nums[j] == trgt)
                    return {idx[i], idx[j]};
            }
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {2, 7, 11, 15};
    //     cout << Solution().twoSum(nums, 9) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {-1, -2, -3, -4, -5};
    //     cout << Solution().twoSum(nums, -8) << endl;
    // }
    cout << "3:" << endl;
    {
        vector<int> nums = {3, 2, 4};
        cout << Solution().twoSum(nums, 6) << endl;
    }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif