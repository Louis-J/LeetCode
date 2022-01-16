#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//与0076类似
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() <= 1) {
            if(nums.size() == 0)
                return 0;
            else
                return nums[0] >= s;
        }

        int sum = 0;
        int minsize = nums.size()+1;
        for(int i = 0, j = 0; j < nums.size();) {
            //j后移，找包含
            while(j < nums.size()) {
                sum += nums[j];
                j++;
                if(sum >= s) {
                    if(j-i < minsize)
                        minsize = j-i;
                    break;
                }
            }
            if(j == nums.size() && sum < s)
                break;
            //i后移，找不足
            while(1) {
                sum -= nums[i];
                i++;
                if(sum < s) {
                    if(j-i < minsize)
                        minsize = j-i+1;
                    break;
                }
            }
        }
        if(minsize == nums.size()+1)
            return 0;
        return minsize;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {2, 3, 1, 2, 4, 3};
        cout << Solution().minSubArrayLen(7, nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {1, 4, 4};
        cout << Solution().minSubArrayLen(4, nums) << endl;
    }
    // cout << "3:" << endl;
    // {
    // }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif