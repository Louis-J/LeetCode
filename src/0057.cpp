#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
private:
    bool isSmall(vector<int>& a, vector<int>& b) {
        return (a[1] < b[0]);
    }
    bool isIn(vector<int>& a, vector<int>& b) {
        return (max(a[1], b[1]) - min(a[0], b[0]) <= a[1] - a[0] - b[0] + b[1]);
    }
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> rlt;
        int i = 0;
        for (; i < intervals.size() && isSmall(intervals[i], newInterval); i++) {
                rlt.emplace_back(intervals[i]);
        }
        for (; i < intervals.size() && isIn(intervals[i], newInterval); i++) {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
        }
        rlt.emplace_back(newInterval);
        for (; i < intervals.size() && !isIn(intervals[i], newInterval); i++) {
                rlt.emplace_back(intervals[i]);
        }
        return rlt;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> intervals = {{1,3},{6,9}};
        vector<int> newInterval = {2,5};
        cout << Solution().insert(intervals, newInterval) << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
        vector<int> newInterval = {4,8};
        cout << Solution().insert(intervals, newInterval) << endl;
    }
    cout << "3:" << endl;
    {
        vector<vector<int>> intervals = {{1,5}};
        vector<int> newInterval = {0,0};
        cout << Solution().insert(intervals, newInterval) << endl;
    }
    cout << "3:" << endl;
    {
        vector<vector<int>> intervals = {{1,5},{10,11},{15,2147483647}};
        vector<int> newInterval = {5,7};
        cout << Solution().insert(intervals, newInterval) << endl;
    }
    return 0;
}
#endif