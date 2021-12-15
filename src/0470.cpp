#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    int seed;
public:
    Solution() {
        seed = rand7()*rand7()*rand7()*rand7()*rand7()*rand7()*rand7()*rand7()*rand7()*rand7()*rand7();
    }
    int rand10() {
        seed = seed * 1103515245 + 123456;
        return seed%10;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1, 2, 3};
        cout << Solution().rand10(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {1, 4, 4};
        cout << Solution().rand10(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums = {1, 2, 1};
        cout << Solution().rand10(nums) << endl;
    }
    return 0;
}
#endif