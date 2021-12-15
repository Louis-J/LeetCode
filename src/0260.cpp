#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto i: nums)
            diff ^= i;
        unsigned int n = 1 << 31;
        for(; (diff & n) == 0; n /= 2);
        int r1 = 0, r2 = 0;
        for(auto i: nums)
            if(i & n)
                r1 ^= i;
            else
                r2 ^= i;
        return vector<int>{r1, r2};
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1,2,1,3,2,5};
        cout << Solution().singleNumber(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {-1,0};
        cout << Solution().singleNumber(nums) << endl;
    }
    return 0;
}
#endif
