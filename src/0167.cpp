#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int trgt) {
        int i = 0, j = nums.size()-1;
        if(nums[i] + nums[j] == trgt)
            return {i+1, j+1};
        else if(nums[i] + nums[j] < trgt)
            while(1) {
                while(nums[i] + nums[j] < trgt) {
                    i++;
                }
                if(nums[i] + nums[j] == trgt)
                    return {i+1, j+1};
                while(nums[i] + nums[j] > trgt) {
                    j--;
                }
                if(nums[i] + nums[j] == trgt)
                    return {i+1, j+1};
            }
        else
            while(1) {
                while(nums[i] + nums[j] > trgt) {
                    j--;
                }
                if(nums[i] + nums[j] == trgt)
                    return {i+1, j+1};
                while(nums[i] + nums[j] < trgt) {
                    i++;
                }
                if(nums[i] + nums[j] == trgt)
                    return {i+1, j+1};
            }
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums = {2, 7, 11, 15};
    cout << Solution().twoSum(nums, 9) << endl;
    return 0;
}
#endif