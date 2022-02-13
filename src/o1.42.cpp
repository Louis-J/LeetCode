#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ret = -100;
        for (auto& num : nums) {
            if (sum <= 0)
                sum = num;
            else
                sum += num;
            ret = max(ret, sum);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = { 7,6,4,3,1 };
        cout << Solution().maxSubArray(nums) << endl;
    }
    return 0;
}
#endif