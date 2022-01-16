#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        if(nums[nums.size() - 1] == nums.size() - 1) return nums.size();
        int begin = 0;
        int end   = nums.size() - 1;

        while(begin != end) {
            int middle = (begin + end) / 2;
            if(nums[middle] != middle)
                end = middle;
            else
                begin = middle + 1;
        }
        return end;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<int> nums = {0, 1, 3};
        cout << Solution().missingNumber(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 9};
        cout << Solution().missingNumber(nums) << endl;
    }
    return 0;
}
#endif