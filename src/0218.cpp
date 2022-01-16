#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static inline void InsertIt(map<int, int> &line, map<int, int>::iterator &it, int &x1, int &y) {
        if(it->first == x1) {
            auto tmpt = it;
            tmpt--;
            
            if(tmpt->second == y)
                it = line.erase(it);
            else
                it->second = y;
        } else {
            it = line.emplace_hint(it, x1, y);
        }
    }
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        constexpr int INTMAX = 2147483647;
        map<int, int> line{{-1, 0}, {INTMAX, 0}};
        for(auto &i : buildings) {
            int x1 = i[0];
            int x2 = i[1];
            int y = i[2];

            auto it = line.begin();
            for(; it->first <= x1; it++) {}
            auto jt = it;
            it--;
            for(; jt->first < x2; jt++) {}

            //在it和jt间增加高度y，it <= x1 < x2 <= jt
            auto kt = it;
            kt++;
            //it < kt < jt
            if(kt == jt) {//kt jt之间无建筑
                if(it->second < y) {//需增高
                    if(jt->second == y) {
                        line.insert_or_assign(it, x1, y);
                        InsertIt(line, it, x1, y);
                        line.erase(jt);
                    } else if(jt->first == x2) {
                        line.insert_or_assign(it, x1, y);
                        InsertIt(line, it, x1, y);
                    } else {
                        line.emplace(x2, it->second);
                        line.insert_or_assign(it, x1, y);
                        InsertIt(line, it, x1, y);
                    }
                }
            } else {//it jt之间有建筑
                if(it->second < y) {
                    InsertIt(line, it, x1, y);
                }

                if(jt->first != x2) {
                    jt--;
                    line.emplace(x2, jt->second);
                    jt++;
                }

                while(kt != jt) {
                    if(kt->second < y) {
                        if(it->second == y) {
                            kt = line.erase(kt);
                        } else {
                            kt->second = y;
                            it = kt;
                            kt++;
                        }
                    } else {
                        it = kt;
                        kt++;
                    }
                }

                if(it->second == jt->second) {
                        line.erase(jt);
                }
            }
        }
        auto n2 = --line.end(), n1 = n2--;
        if(n1->second == n2->second)
            line.erase(n1);
        line.erase(-1);

        vector<vector<int>> ret;
        for(auto it = line.begin(); it != line.end(); it++) {
            ret.emplace_back(vector<int>{it->first, it->second});
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
    //     cout << Solution().getSkyline(buildings) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<vector<int>> buildings = {{0, 1, 3}};
    //     cout << Solution().getSkyline(buildings) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<vector<int>> buildings = {{0, 2147483647, 2147483647}};
    //     cout << Solution().getSkyline(buildings) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<vector<int>> buildings = {{0, 2, 3}, {2, 5, 3}};
    //     cout << Solution().getSkyline(buildings) << endl;
    // }
    cout << " 5:" << endl;
    {
        vector<vector<int>> buildings = {{2, 13, 10}, {10, 17, 25}, {12, 20, 14}};
        cout << Solution().getSkyline(buildings) << endl;
    }
    return 0;
}
#endif