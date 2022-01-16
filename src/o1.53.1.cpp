#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

// 此题花了过多时间
// 需要总结和练习二分法
class Solution {
    int getIndexBegin(vector<int> &nums, int target, int begin, int end) {
        if(begin == end) return begin - (nums[begin] == target);
        int middle = (begin + end + 1) / 2;
        if(nums[middle] < target)
            return getIndexBegin(nums, target, middle, end);
        else
            return getIndexBegin(nums, target, begin, middle - 1);
    }
    int getIndexEnd(vector<int> &nums, int target, int begin, int end) {
        if(begin == end) return begin + (nums[begin] == target);
        int middle = (begin + end) / 2;
        if(nums[middle] <= target)
            return getIndexEnd(nums, target, middle + 1, end);
        else
            return getIndexEnd(nums, target, begin, middle);
    }

public:
    int search(vector<int> &nums, int target) {
        if(nums.size() > 1) {
            if(nums[0] > target || nums[nums.size() - 1] < target) return 0;
            auto iBegin = getIndexBegin(nums, target, 0, nums.size() - 1);
            //cout << "iBegin：" << iBegin << endl;
            auto iEnd = getIndexEnd(nums, target, 0, nums.size() - 1);
            //cout << "iEnd：" << iEnd << endl;
            return iEnd - iBegin - 1;
        } else if(nums.size() == 1) {
            return nums[0] == target;
        } else
            return 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<int> nums   = {5, 7, 7, 8, 8, 10};
        int         target = 8;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums   = {5, 7, 7, 8, 8, 10};
        int         target = 6;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums   = {1};
        int         target = 1;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums   = {2, 2};
        int         target = 1;
        cout << Solution().search(nums, target) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums   = {2, 2};
        int         target = 2;
        cout << Solution().search(nums, target) << endl;
    }
    return 0;
}
#endif