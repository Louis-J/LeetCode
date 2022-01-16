#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int FME(vector<int>& nums, size_t b, size_t e) {//仅针对最左=最右的情况
        if(e-b <= 3) {
            if(e-b == 3) {
                return min(nums[b+1], nums[b+2]);
            } else {
                return min(nums[b], nums[b+1]);
            }
        }
        size_t m = (b+e)/2;
        if(nums[m] == nums[b])
            return min(FME(nums, b, m), FME(nums, m, e));
        else if(nums[m] < nums[b])
            return FM(nums, b, m+1);
        else
            return FM(nums, m, e);
    }
    static int FM(vector<int>& nums, size_t b, size_t e) {
        if(e-b <= 3) {
            if(e-b == 3) {
                return min(nums[b+1], nums[b+2]);
            } else {
                return min(nums[b], nums[b+1]);
            }
        }
        size_t m = (b+e)/2;
        if(nums[m] >= nums[b])
            return FM(nums, m, e);
        else
            return FM(nums, b, m+1);
    }
public:
    int findMin(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 2)
            return min(nums[0], nums[1]);
        else if(nums[0] == nums[nums.size()-1])
            return FME(nums, 0, nums.size());
        else if(nums[0] < nums[nums.size()-1])
            return nums[0];
        else
            return FM(nums, 0, nums.size());
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {1, 3, 5};
    //     cout << Solution().findMin(nums) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {2, 2, 2, 0, 1};
    //     cout << Solution().findMin(nums) << endl;
    // }
    cout << "3:" << endl;
    {
        vector<int> nums = {3, 3, 1, 3};
        cout << Solution().findMin(nums) << endl;
    }
    // cout << "4:" << endl;
    // {
    //     vector<int> nums = {1, 2, 3, 3, 3, 2, 1};
    //     cout << Solution().candy(nums) << endl;
    // }
    
    return 0;
}
#endif