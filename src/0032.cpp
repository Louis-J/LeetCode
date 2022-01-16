#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int longestValidParentheses0(string s) {
        vector<int> lastPosi(s.size(), -1);
        int maxLen = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if(s[i-1] == '(') {
                    lastPosi[i] = i-1;
                    if (i-2 >= 0 && lastPosi[i-2] != -1) {
                        lastPosi[i] = lastPosi[i-2];
                    }
                } else if (i-1 >= 0 && lastPosi[i-1] != -1
                    && lastPosi[i-1]-1 >= 0 && s[lastPosi[i-1]-1] == '(') {
                    lastPosi[i] = lastPosi[i-1]-1;
                    if (lastPosi[i-1]-2 >= 0 && lastPosi[lastPosi[i-1]-2] != -1) {
                        lastPosi[i] = lastPosi[lastPosi[i-1]-2];
                    }
                }
                if (lastPosi[i] != -1 && i-lastPosi[i] > maxLen) {
                    maxLen = i-lastPosi[i]+1;
                }
            }
        }
        //cout << lastPosi << endl;
        return maxLen;
    }
    //时间O(n)空间O(1)
    int longestValidParentheses(string s) {
        int b = 0, e = s.size()-1;
        for(; b <= e && s[b] == ')'; b++) {}
        for(; b <= e && s[e] == '('; e--) {}


        int lrhave = 0;
        int len = 0;
        int lend = 0;
        int maxlen = 0;
        for(int i = b; i <= e; i++) {
            if(s[i] == '(') {
                lrhave++;
            } else {
                if(lrhave > 0) {
                    lrhave--;
                    len += 2;
                    if(lrhave == 0) {
                        maxlen = max(maxlen, len);
                        lend = i;
                    }
                } else {
                    len = 0;
                }
            }
        }
        if(lrhave != 0) {
            lrhave = 0;
            len = 0;
            for(int i = e; i > lend; i--) {
                if(s[i] == ')') {
                    lrhave++;
                } else {
                    if(lrhave > 0) {
                        lrhave--;
                        len += 2;
                        if(lrhave == 0)
                            maxlen = max(maxlen, len);
                    } else {
                        len = 0;
                    }
                }
            }
        }
        return maxlen;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     string s = "(()";
    //     cout << Solution().longestValidParentheses(s) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     string s = ")()())";
    //     cout << Solution().longestValidParentheses(s) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     string s = "(())";
    //     cout << Solution().longestValidParentheses(s) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     string s = "()(()";
    //     cout << Solution().longestValidParentheses(s) << endl;
    // }
    cout << " 5:" << endl;
    {
        string s = ")()())()()(";
        cout << Solution().longestValidParentheses(s) << endl;
    }
    return 0;
}
#endif