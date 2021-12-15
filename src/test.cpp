#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    pair<int, int> getnotequal(vector<int>& nums) {
        int x = 0;
        for(auto i: nums)
            x ^= i;
        int b;
        for(b = 31; (x & (1 << b)) == 0; b--) {}

        int sum1 = 0, sum2 = 0;
        for(auto i: nums) {
            if(i & (1 << b))
                sum1 ^= i;
            else 
                sum2 ^= i;
        }
        return {sum1, sum2};
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {1,1,2,2,3,4};
    //     cout << Solution().getnotequal(nums) << endl;
    // }
    cout << " 2:" << endl;
    {
        vector<int> nums = {1,1,2,2,3,5};
        cout << Solution().getnotequal(nums) << endl;
    }
    return 0;
}
#endif