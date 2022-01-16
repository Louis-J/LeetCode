#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> minLeft(nums.size()), minRight(nums.size());
        const int   size1 = nums.size() - 1;
        int         sum;

        sum        = nums[0];
        minLeft[0] = 0;
        for(int i = 1; i <= size1; i++) {
            minLeft[i] = min(minLeft[i - 1], sum);
            sum += nums[i];
        }

        sum             = nums[size1];
        minRight[size1] = 0;
        for(int i = size1 - 1; i >= 0; i--) {
            minRight[i] = min(minRight[i + 1], sum);
            sum += nums[i];
        }

        int minus = 0;
        sum       = 0;
        for(int i = 0; i <= size1; i++) {
            minus = min(minus, minLeft[i] + minRight[i]);
            sum += nums[i];
        }
        return sum - minus;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> nums = {1};
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> nums = {5, 4, -1, 7, 8};
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << "4:" << endl;
    {
        vector<int> nums = {2, -1};
        cout << Solution().maxSubArray(nums) << endl;
    }
    cout << "5:" << endl;
    {
        vector<int> nums = {-2, 1};
        cout << Solution().maxSubArray(nums) << endl;
    }
    return 0;
}
#endif