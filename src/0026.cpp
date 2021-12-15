#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        size_t l = 0;
        for(size_t i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[l]) {
                l++;
                nums[l] = nums[i];
            }
        }
        return l+1;
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums1 = {1, 1, 2};
    cout << Solution().removeDuplicates(nums1) << nums1 << endl;
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << Solution().removeDuplicates(nums2) << nums2 << endl;
    return 0;
}
#endif