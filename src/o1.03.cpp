#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findRepeatNumber0(vector<int> &nums) {
        unordered_set<int> numSet;
        for(auto &i:nums)
            if(!numSet.emplace(i).second)
                return i;
        return 0;
    }
    int findRepeatNumber(vector<int> &nums) {
        int i = 0;
        while(true) {
            if(nums[i] != i) {
                if(nums[i] < i)
                    return nums[i];
                else if(nums[i] == nums[nums[i]])
                    return nums[i];
                swap(nums[i], nums[nums[i]]);
            } else {
                i++;
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
        cout << Solution().findRepeatNumber(nums) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif