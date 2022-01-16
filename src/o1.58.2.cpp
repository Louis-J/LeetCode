#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        auto strv = string_view(s);
        auto strv1 = strv.substr(n);
        auto strv2 = strv.substr(0, n);
        string ret;
        ret.append(strv1);
        ret.append(strv2);
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        string s = "abcdefg";
        int    k = 2;
        cout << Solution().reverseLeftWords(s, k) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif