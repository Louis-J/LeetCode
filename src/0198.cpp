#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int rob(vector<int> &nums) {
        pair<int, int> dpNT = {0, 0};
        for(auto &n : nums) {
            dpNT = {max(dpNT.first, dpNT.second), dpNT.first + n};
        }
        return max(dpNT.first, dpNT.second);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1, 2, 3, 1};
        cout << Solution().rob(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {2, 7, 9, 3, 1};
        cout << Solution().rob(nums) << endl;
    }

    return 0;
}
#endif