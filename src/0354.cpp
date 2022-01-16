#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() <= 1)
            return envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            if(a[0] == b[0])
                return a[1] < b[1];
            return a[0] < b[0];
        });
        int lb = 0, le = 1;
        vector<int> ind(envelopes.size(), -1);
        while(envelopes[le][0] == envelopes[lb][0]) {
            if(++le ==  envelopes.size())
                return 1;
        }
        while(le < envelopes.size()) {
            int i = le;
            int link = lb;
            for(; i < envelopes.size() && envelopes[i][0] == envelopes[le][0]; i++) {
                if(envelopes[i][1] <= envelopes[link][1]) {
                    if(link != lb)
                        ind[i] = ind[i-1];
                } else {
                    while(envelopes[i][1] > envelopes[link][1]) {
                        if(++link == le) {
                            for(; i < envelopes.size() && envelopes[i][0] == envelopes[le][0]; i++)
                                ind[i] = link-1;
                            break;
                        }
                    }
                    if(link == le)
                        break;
                    ind[i] = link-1;
                }
            }
            lb = le;
            le = i;
        }
        int ret = 1;
        for(int i = ind[ind.size()-1]; i != -1; i = ind[i])
            ret++;
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    //     cout << Solution().maxEnvelopes(envelopes) << endl;
    // }
    cout << " 2:" << endl;
    {
        vector<vector<int>> envelopes = {{1, 3}, {3, 5}, {6, 7}, {6, 8}, {8, 4}, {9, 5}};
        cout << Solution().maxEnvelopes(envelopes) << endl;
    }
    return 0;
}
#endif