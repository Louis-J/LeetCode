#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static void digui(vector<vector<int>> &ret, vector<int> &nums, const int p = 0) {
        if(p == nums.size()-1) {
            ret.emplace_back(nums);
            return;
        }
        digui(ret, nums, p+1);
        for(int i = p+1; i < nums.size(); i++) {
            if(nums[p] != nums[i]) {
                swap(nums[p], nums[i]);
                digui(ret, nums, p+1);
                swap(nums[p], nums[i]);
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        digui(ret, nums);
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1,1,2};
        cout << Solution().permuteUnique(nums) << endl;
    }
    // cout << "2:" << endl;
    // {
    // }
    // cout << "3:" << endl;
    // {
    //     string s = "cb";
    //     string p = "?a";
    //     cout << boolalpha << Solution().isMatch(s, p) << endl;
    // }
    
    return 0;
}
#endif
