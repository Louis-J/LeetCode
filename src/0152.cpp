#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int ret   = nums[0];
        int plus0 = nums[0];
        int plus1 = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            int n = nums[i];
            if(n == 0) {
                plus0 = 0;
                plus1 = 0;
                ret   = max(ret, 0);
            } else if(n > 0) {
                int newPlus0 = min(plus0 * n, n);
                int newPlus1 = max(plus1 * n, n);
                plus0 = newPlus0;
                plus1 = newPlus1;
                ret   = max(ret, plus1);
            } else {
                int newPlus0 = min(plus1 * n, n);
                int newPlus1 = max(plus0 * n, n);
                plus0 = newPlus0;
                plus1 = newPlus1;
                ret   = max(ret, plus1);
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {2, 3, -2, 4};
        cout << Solution().maxProduct(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {-2, 0, -1};
        cout << Solution().maxProduct(nums) << endl;
    }

    return 0;
}
#endif