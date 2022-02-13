#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int solution(string &S) {
        // write your code in C++14 (g++ 6.2.0)
        pair<int, int> dpChars[26];  // (cut num, index)
        for(int i = 0; i < 26; i++) dpChars[i] = {0, -1};

        int maxCut = 0;
        for(int i = 0; i < S.size(); i++) {
            char ci         = S[i] - 'a';
            int  maxCutTemp = maxCut;
            // update maxCut
            if(dpChars[ci].second != -1 && maxCut < dpChars[ci].first + i - dpChars[ci].second + 1) {
                maxCut = dpChars[ci].first + i - dpChars[ci].second + 1;
            }
            // update dpChars
            if(dpChars[ci].second == -1 || maxCutTemp > dpChars[ci].first + i - dpChars[ci].second) {
                dpChars[ci] = {maxCutTemp, i};
            }
        }

        return S.size() - maxCut;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    // cout << " 1:" << endl;
    // {
    //     string S = "abccac";
    //     cout << Solution().solution(S) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     string S = "abcdabcdabcd";
    //     cout << Solution().solution(S) << endl;
    // }
    cout << " 3:" << endl;
    {
        string S = "axaabyab";
        cout << Solution().solution(S) << endl;
    }
    return 0;
}
#endif