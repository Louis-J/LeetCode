#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

// todo: 链表判环
class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int sum = 0;
        for(auto &i : nums) sum += i;
        return sum - (nums.size() * (nums.size() - 1) / 2);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1, 3, 4, 2, 2};
        cout << Solution().findDuplicate(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {3, 1, 3, 4, 2};
        cout << Solution().findDuplicate(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {1, 1};
        cout << Solution().findDuplicate(nums) << endl;
    }
    cout << "4:" << endl;
    {
        vector<int> nums = {1, 1, 2};
        cout << Solution().findDuplicate(nums) << endl;
    }
    return 0;
}
#endif
