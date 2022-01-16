#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    string replaceSpace(string s) {
        string ret;
        for(auto &c : s) {
            if(c != ' ')
                ret += c;
            else
                ret += "%20";
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        string s = "We are happy.";
        cout << Solution().replaceSpace(s) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif