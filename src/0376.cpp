#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = 2;
        int i = 1;
        while(true) {
            if(i >= nums.size())
                return 1;
            if(nums[i] == nums[0])
                i++;
            else
                break;
        }
        bool inc = nums[i] > nums[0];

        while(++i < nums.size()) {
            if((inc && nums[i] < nums[i-1]) || (!inc && nums[i] > nums[i-1])) {
                len++;
                inc = !inc;
            }
        }
        return len;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1,7,4,9,2,5};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
        cout << Solution().wiggleMaxLength(nums) << endl;
    }
    return 0;
}
#endif