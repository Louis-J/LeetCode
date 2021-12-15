#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        if(nums.size() == 1)
            return vector<int>{nums[0][0], nums[0][0]};

        vector<pair<int, int>> newnums;
        for(int i = 0; i < nums.size(); i++)
            for(int j = 0; j < nums[i].size(); j++)
                newnums.emplace_back(nums[i][j], i);
        sort(newnums.begin(), newnums.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });
        // multimap<int, int> idxmap;
        // int idxs[nums.size()];
        // for(auto &i : idxs)
        //     i = 0;
        // for(int i = 0; i < nums.size(); i++)
        //     idxmap.emplace(nums[i][0], i);
        // while(idxmap.size() != 0) {
        //     auto it = idxmap.begin();
        //     auto idx = it->second;
        //     newnums.emplace_back(it->first, idx);
        //     idxmap.erase(it);
        //     if(++idxs[idx] != nums[idx].size())
        //         idxmap.emplace(nums[idx][idxs[idx]], idx);
        // }

        int have[nums.size()];
        for(auto &i : have)
            i = 0;
        int kind = 0;
        int i = 0, j = 0;

        int minb = newnums[0].first, mine = newnums[newnums.size()-1].first;
        while(j < newnums.size()) {
            have[newnums[j].second]++;
            if(have[newnums[j].second] == 1) {
                kind++;
                if(kind == nums.size()) {
                    if(newnums[j].first - newnums[i].first < mine - minb)
                        minb = newnums[i].first, mine = newnums[j].first;
                    while(--have[newnums[i++].second] != 0) {
                        if(newnums[j].first - newnums[i].first < mine - minb)
                            minb = newnums[i].first, mine = newnums[j].first;
                    }
                    kind--;
                }
            }
            j++;
        }
        return vector<int>{minb, mine};
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> nums = {
            {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}
        };
        cout << Solution().smallestRange(nums) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     vector<vector<int>> nums = {
    //         {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}
    //     };
    //     cout << Solution().smallestRange(nums) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<vector<int>> nums = {
    //         {4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}
    //     };
    //     cout << Solution().smallestRange(nums) << endl;
    // }
    return 0;
}
#endif