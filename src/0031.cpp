#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1)
            return;
        else if(nums.size() == 2) {
            swap(nums[0], nums[1]);
            return;
        }
        for(int i = nums.size()-1; i >= 1; i--) {
            if(nums[i-1] < nums[i]) {
                int a = i-1;

                //此处可使用二分查找优化
                int b = nums.size()-1;
                for(; b > i && nums[b] <= nums[a]; b--) {}
                // int b = i;
                // for(; b < nums.size() && nums[b] > nums[a]; b++) {}
                // b--;

                swap(nums[a], nums[b]);
                sort(&nums[a+1], &nums[nums.size()]);
                return;
            }
        }
        int size = nums.size()-1;
        for(int i = 0; i < nums.size()/2; i++)
            swap(nums[i], nums[size-i]);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1, 2, 3};
        Solution().nextPermutation(nums);
        cout << nums << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {3, 2, 1};
        Solution().nextPermutation(nums);
        cout << nums << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums = {1, 1, 5};
        Solution().nextPermutation(nums);
        cout << nums << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums = {1, 3, 2, 4};
        Solution().nextPermutation(nums);
        cout << nums << endl;
        Solution().nextPermutation(nums);
        cout << nums << endl;
        Solution().nextPermutation(nums);
        cout << nums << endl;
        Solution().nextPermutation(nums);
        cout << nums << endl;
        Solution().nextPermutation(nums);
        cout << nums << endl;
    }
    return 0;
}
#endif