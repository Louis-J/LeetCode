#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    char firstUniqChar(string s) {
        char cs[26] = {};
        for(auto &c : s) {
            if(cs[c - 'a'] < 2) cs[c - 'a']++;
        }
        for(char i = 0; i < 26; i++) {
            if(cs[i] == 1) return i + 'a';
        }
        return ' ';
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        string s = "abaccdeff";
        cout << Solution().firstUniqChar(s) << endl;
    }
    cout << " 2:" << endl;
    {
        string s = "";
        cout << Solution().firstUniqChar(s) << endl;
    }
    return 0;
}
#endif