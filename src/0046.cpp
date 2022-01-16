#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution0 {
    vector<vector<int>> ret;
    vector<int> have;
    vector<int> rest;
    void dfs() {
        if(rest.size() == 0)
            ret.emplace_back(have);
        else {
            int i = rest.size()-1;
            int hs = have.size();
            have.emplace_back(rest[i]);
            rest.resize(i);

            dfs();
            for(i--; i >= 0; i--) {
                swap(have[hs], rest[i]);
                dfs();
            }
            rest.insert(rest.begin(), have[hs]);
            have.resize(hs);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        rest = vector<int>(nums.rbegin(), nums.rend());
        dfs();
        return ret;
    }
};

class Solution {
    static void digui(vector<vector<int>> &ret, vector<int> &nums, const int p = 0) {
        if(p == nums.size()-1) {
            ret.emplace_back(nums);
            return;
        }
        digui(ret, nums, p+1);
        for(int i = p+1; i < nums.size(); i++) {
            swap(nums[p], nums[i]);
            digui(ret, nums, p+1);
            swap(nums[p], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        digui(ret, nums);
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> nums = {1,2,3};
        cout << Solution().permute(nums) << endl;
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