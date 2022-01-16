#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int chars[100] = {};
        for(auto &i : chars) i = -1;
        int lastI  = -1;
        int maxLen = 0;
        for(int i = 0; i < s.size(); i++) {
            auto c   = s[i] - ' ';
            lastI    = max(lastI, chars[c]);
            maxLen   = max(maxLen, i - lastI);
            chars[c] = i;
        }
        return maxLen;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        string s = "abcabcbb";
        cout << Solution().lengthOfLongestSubstring(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "bbbbb";
        cout << Solution().lengthOfLongestSubstring(s) << endl;
    }
    cout << " 3:" << endl;
    {
        string s = "pwwkew";
        cout << Solution().lengthOfLongestSubstring(s) << endl;
    }
    return 0;
}
#endif