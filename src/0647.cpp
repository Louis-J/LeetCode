#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    int countMiddle(string &newStr, int index) {
        int len = 1;
        for(; index - len >= 0 && index + len < newStr.size() && newStr[index - len] == newStr[index + len]; len++) {
        }
        if(index % 2) {
            len /= 2;
        } else {
            len /= 2;
        }
        return len;
    }

public:
    int countSubstrings0(string s) {
        string newStr = "0";
        for(auto &c : s) {
            newStr.append(1, c);
            newStr.append(1, '0');
        }
        int sum = 0;
        for(int i = 0; i < newStr.size(); i++) sum += countMiddle(newStr, i);
        return sum;
    }
    int countSubstrings(string s) {
        string newStr = "0";
        for(auto &c : s) {
            newStr.append(1, c);
            newStr.append(1, '0');
        }
        int sum = 0;
        for(int i = 0; i < newStr.size(); i++) {
            int len = 1;
            for(; i - len >= 0 && i + len < newStr.size() && newStr[i - len] == newStr[i + len]; len++) {
            }
            sum += len / 2;
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(false);
    cout << "1:" << endl;
    {
        string s = "abc";
        cout << Solution().countSubstrings(s) << endl;
    }
    cout << "2:" << endl;
    {
        string s = "aaa";
        cout << Solution().countSubstrings(s) << endl;
    }
    cout << "3:" << endl;
    {}
    return 0;
}
#endif
