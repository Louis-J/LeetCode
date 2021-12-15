#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif
static auto __sync__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    //数据结构不转换
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if(people.size() <= 1)
            return people;
        
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<vector<int>> rlt;
        rlt.reserve(people.size());
        for(auto &i: people)
            rlt.insert(rlt.begin()+i[1], vector<int>{i[0], i[1]});
        return rlt;
    }
    //数据结构转换一个
    vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
        if(people.size() <= 1)
            return people;
        
        sort(people.begin(), people.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] > b[0];
        });
        vector<pair<int, int>> que;
        que.reserve(people.size());
        for(auto &i: people)
            que.insert(que.begin()+i[1], pair<int, int>(i[0], i[1]));
        vector<vector<int>> rlt;
        rlt.reserve(people.size());
        for(auto &i: que)
            rlt.emplace_back(vector<int>{i.first, i.second});
        return rlt;
    }
    //数据结构转换两个
    vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
        if(people.size() <= 1)
            return people;
        vector<pair<int, int>> pp;
        pp.reserve(people.size());
        for(auto &i : people)
            pp.emplace_back(i[0], i[1]);
        
        sort(pp.begin(), pp.end(), [](pair<int, int> &a, pair<int, int> &b) {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        });
        vector<pair<int, int>> que;
        que.reserve(people.size());
        for(auto &i: pp)
            que.insert(que.begin()+i.second, i);
        vector<vector<int>> rlt;
        rlt.reserve(people.size());
        for(auto &i: que)
            rlt.emplace_back(vector<int>{i.first, i.second});
        return rlt;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> people = {{7,0},{4,4},{7,1},{5,0},{6,1},{5,2}};
        cout << Solution().reconstructQueue(people) << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> people = {{6,0},{5,0},{4,0},{3,2},{2,2},{1,4}};
        cout << Solution().reconstructQueue(people) << endl;
    }
    // cout << "3:" << endl;
    // {
    // }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif