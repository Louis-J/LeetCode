#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t l = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                if(l != i)
                    nums[l] = nums[i];
                l++;
            }
        }
        return l;
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums1 = {3, 2, 2, 3};
    cout << Solution().removeElement(nums1, 3) << nums1 << endl;
    vector<int> nums2 = {0, 1, 2, 2, 3, 0, 4, 2};
    cout << Solution().removeElement(nums2, 2) << nums2 << endl;
    return 0;
}
#endif