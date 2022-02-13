#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<vector<int>> merge0(vector<vector<int>> &intervals) {
        if(intervals.size() <= 1) return intervals;

        vector<vector<int>>    ret;
        vector<pair<int, int>> pairs;
        for(auto &i : intervals) pairs.emplace_back(i[0], i[1]);
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &i, pair<int, int> &j) { return i.first < j.first; });

        ret.emplace_back(vector<int>{pairs[0].first, pairs[0].second});
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i].first <= ret.back()[1]) {
                ret.back()[1] = max(ret.back()[1], pairs[i].second);
            } else {
                ret.emplace_back(vector<int>{pairs[i].first, pairs[i].second});
            }
        }
        return ret;
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if(intervals.size() <= 1) return intervals;

        vector<vector<int>>    ret;
        vector<pair<int, int>> pairs;
        for(auto &i : intervals) pairs.emplace_back(i[0], i[1]);
        sort(pairs.begin(), pairs.end(), [](pair<int, int> &i, pair<int, int> &j) { return i.first < j.first; });

        pair<int, int> tmp = pairs[0];
        for(int i = 1; i < pairs.size(); i++) {
            if(pairs[i].first <= tmp.second) {
                tmp.second = max(tmp.second, pairs[i].second);
            } else {
                ret.emplace_back(vector<int>{tmp.first, tmp.second});
                tmp = pairs[i];
            }
        }
        ret.emplace_back(vector<int>{tmp.first, tmp.second});
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        cout << Solution().merge(intervals) << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> intervals = {{1, 4}, {4, 5}};
        cout << Solution().merge(intervals) << endl;
    }
    cout << "3:" << endl;
    {}
    return 0;
}
#endif