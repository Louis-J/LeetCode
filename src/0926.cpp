#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        if(s.size() <= 1) return 0;
        pair<int, int> dp;
        dp.first = (s[0] != '0');
        // dp.second = 1 - dp.first;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == '0') {
                dp.second = min(dp.first, dp.second) + 1;
            } else {
                dp.second = min(dp.first, dp.second);
                dp.first++;
            }
        }
        return min(dp.first, dp.second);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string s = "00110";
        cout << Solution().minFlipsMonoIncr(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "010110";
        cout << Solution().minFlipsMonoIncr(s) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "00011000";
        cout << Solution().minFlipsMonoIncr(s) << endl;
    }
    return 0;
}
#endif