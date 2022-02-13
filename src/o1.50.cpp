#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    char firstUniqChar(string s) {
        int order = 0;
        int chars[26] = {};
        for (auto& c : s) {
            if (chars[c - 'a'] == 0)
                chars[c - 'a'] = ++order;
            else if (chars[c - 'a'] > 0)
                chars[c - 'a'] = -1;
        }

        int aimOrder = 27;
        int aimIndex;
        for (int i = 0; i < 26; i++)
            if (chars[i] > 0 && chars[i] < aimOrder) {
                aimIndex = i;
                aimOrder = chars[i];
            }
        if (aimOrder == 27)
            return ' ';
        else
            return 'a' + aimIndex;
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
