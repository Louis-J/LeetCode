#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//好几天没想出来，看别人答案的
// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         for(int i=0; i<nums.size(); i++){
//             if(i+1==nums[i]) continue;
//             int x = nums[i];
//             while(x>=1 && x<=nums.size() && x!=nums[x-1]){
//                 swap(x, nums[x-1]);
//             }
//         }
//         for(int i=0; i<nums.size(); i++){
//             if(i+1!=nums[i])    return i+1;
//         }
//         return nums.size()+1;
//     }
// };

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
            return 1;
        int nMax = nums[0], nMin = nums[0];
        for (auto &i : nums) {
            if (i > 0) {
                if (i > nMax)
                    nMax = i;
                if (nMin <= 0 || i < nMin)
                    nMin = i;
            }
        }
        if (nMin > 1 || nMin < 0) {
            return 1;
        } else {
            vector<bool> have(nums.size());
            for (auto &i : nums) {
                if (i > 0 && i <= nums.size())
                    have[i-1] = true;
            }
            for (auto i = 0; i <= nums.size(); i++) {
                if (have[i] == false)
                    return i+1;
            }
            return nums.size();
        }
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {1,2,0};
    //     cout << Solution().firstMissingPositive(nums) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {3,4,-1,1};
    //     cout << Solution().firstMissingPositive(nums) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     vector<int> nums = {7,8,9,11,12};
    //     cout << Solution().firstMissingPositive(nums) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     vector<int> nums = {-1,4,2,1,9,10};
    //     cout << Solution().firstMissingPositive(nums) << endl;
    // }
    cout << "5:" << endl;
    {
        vector<int> nums = {1,0,3,3,0,2};
        cout << Solution().firstMissingPositive(nums) << endl;
    }
    return 0;
}
#endif