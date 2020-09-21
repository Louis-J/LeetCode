#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        size_t i = 0;
        for(size_t j = 0; j < nums.size(); j++) {
            if(nums[j] != 0)
                nums[i++] = nums[j];
        }
        for(; i < nums.size(); i++)
            nums[i] = 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {0, 1, 0, 3, 12};
        Solution().moveZeroes(nums);
        cout << nums << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {1, 3, 12, 0, 0};
        Solution().moveZeroes(nums);
        cout << nums << endl;
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