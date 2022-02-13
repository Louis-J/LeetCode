#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<vector<int>> intervalIntersection1(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const int m = firstList.size();
        const int n = secondList.size();
        if (m == 0 || n == 0)
            return {};
        pair<int, int> list1[m];
        pair<int, int> list2[n];
        for (int i = 0; i < m; i++) {
            list1[i].first = firstList[i][0];
            list1[i].second = firstList[i][1];
        }
        for (int i = 0; i < n; i++) {
            list2[i].first = secondList[i][0];
            list2[i].second = secondList[i][1];
        }

        vector<vector<int>> ret;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (list1[i].first == list2[j].first) {
                if (list1[i].second == list2[j].second) {
                    ret.emplace_back(vector<int>{ list1[i].first, list1[i].second });
                    i++;
                    j++;
                } else if (list1[i].second < list2[j].second) {
                    ret.emplace_back(vector<int>{ list1[i].first, list1[i].second });
                    i++;
                } else {
                    ret.emplace_back(vector<int>{ list2[j].first, list2[j].second });
                    j++;
                }
            } else if (list1[i].first < list2[j].first) {
                if (list1[i].second > list2[j].second) {
                    ret.emplace_back(vector<int>{ list2[j].first, list2[j].second });
                    j++;
                } else if (list1[i].second == list2[j].second) {
                    ret.emplace_back(vector<int>{ list2[j].first, list1[i].second });
                    i++;
                    j++;
                } else if (list1[i].second < list2[j].first) {
                    i++;
                } else {
                    ret.emplace_back(vector<int>{ list2[j].first, list1[i].second });
                    i++;
                }
            } else {
                if (list1[i].second < list2[j].second) {
                    ret.emplace_back(vector<int>{ list1[i].first, list1[i].second });
                    i++;
                } else if (list1[i].second == list2[j].second) {
                    ret.emplace_back(vector<int>{ list1[i].first, list1[i].second });
                    i++;
                    j++;
                } else if (list2[j].second < list1[i].first) {
                    j++;
                } else {
                    ret.emplace_back(vector<int>{ list1[i].first, list2[j].second });
                    j++;
                }
            }
        }
        return ret;
    }
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        const int m = firstList.size();
        const int n = secondList.size();
        if (m == 0 || n == 0)
            return {};
        pair<int, int> list1[m];
        pair<int, int> list2[n];
        for (int i = 0; i < m; i++) {
            list1[i].first = firstList[i][0];
            list1[i].second = firstList[i][1];
        }
        for (int i = 0; i < n; i++) {
            list2[i].first = secondList[i][0];
            list2[i].second = secondList[i][1];
        }

        vector<vector<int>> ret;
        pair<int, int>* i = list1;
        pair<int, int>* j = list2;
        while (i < list1 + m && j < list2 + n) {
            if (i->first == j->first) {
                if (i->second == j->second) {
                    ret.emplace_back(vector<int>{ i->first, i->second });
                    i++;
                    j++;
                } else if (i->second < j->second) {
                    ret.emplace_back(vector<int>{ i->first, i->second });
                    i++;
                } else {
                    ret.emplace_back(vector<int>{ j->first, j->second });
                    j++;
                }
            } else if (i->first < j->first) {
                if (i->second > j->second) {
                    ret.emplace_back(vector<int>{ j->first, j->second });
                    j++;
                } else if (i->second == j->second) {
                    ret.emplace_back(vector<int>{ j->first, i->second });
                    i++;
                    j++;
                } else if (i->second < j->first) {
                    i++;
                } else {
                    ret.emplace_back(vector<int>{ j->first, i->second });
                    i++;
                }
            } else {
                if (i->second < j->second) {
                    ret.emplace_back(vector<int>{ i->first, i->second });
                    i++;
                } else if (i->second == j->second) {
                    ret.emplace_back(vector<int>{ i->first, i->second });
                    i++;
                    j++;
                } else if (j->second < i->first) {
                    j++;
                } else {
                    ret.emplace_back(vector<int>{ i->first, j->second });
                    j++;
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> firstList = { {0, 2}, {5, 10}, {13, 23}, {24, 25} };
        vector<vector<int>> secondList = { {1, 5}, {8, 12}, {15, 24}, {25, 26} };
        cout << Solution().intervalIntersection(firstList, secondList) << endl;
        //[[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> firstList = { {1,3},{5,9} };
        vector<vector<int>> secondList = {  };
        cout << Solution().intervalIntersection(firstList, secondList) << endl;
        //
    }
    cout << "3:" << endl;
    {
        vector<vector<int>> firstList = { {1,7} };
        vector<vector<int>> secondList = { {3,10} };
        cout << Solution().intervalIntersection(firstList, secondList) << endl;
        //[[3,7]]
    }
    cout << "4:" << endl;
    {
        vector<vector<int>> firstList = { {3,10} };
        vector<vector<int>> secondList = { {5,10} };
        cout << Solution().intervalIntersection(firstList, secondList) << endl;
        //[[5,10]]
    }
    cout << "5:" << endl;
    {
        vector<vector<int>> firstList = { {4,6},{7,8},{10,17} };
        vector<vector<int>> secondList = { {5,10} };
        cout << Solution().intervalIntersection(firstList, secondList) << endl;
        //[[5,6],[7,8],[10,10]]
    }

    return 0;
}
#endif
