#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    //暂未看最优解法
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, pair<int, int>> table;
        int ret = 0;
        for(auto &i : nums) {
            if(table.find(i) == table.end()) {
                int minn = i, maxn = i;

                auto it = table.find(i-1);
                if(it != table.end())
                    minn = it->second.first;

                auto jt = table.find(i+1);
                if(jt != table.end())
                    maxn = jt->second.second;

                ret = max(ret, maxn-minn+1);

                if(it != table.end()) {
                    if(i-1 == minn)
                        it->second.second = maxn;
                    else
                        table[minn].second = maxn;
                }
                if(jt != table.end()) {
                    if(i+1 == maxn)
                        jt->second.first = minn;
                    else
                        table[maxn].first = minn;
                }

                table.emplace(i, make_pair(minn, maxn));
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {100, 4, 200, 1, 3, 2};
    //     cout << Solution().longestConsecutive(nums) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    //     cout << Solution().longestConsecutive(nums) << endl;
    // }
    cout << "3:" << endl;
    {
        vector<int> nums = {-2, -3, -3, 7, -3, 0, 5, 0, -8, -4, -1, 2};
        cout << Solution().longestConsecutive(nums) << endl;
    }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif