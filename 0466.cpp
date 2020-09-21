#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int refn = 1;
        for(int i = 0; i < s2.size(); i++)
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