/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        if(k != 2 && stones.size() % (k-1) != 1)
            return -1;
    }
};
// @lc code=end

