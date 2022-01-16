#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    bool isPalindrome0(string s) {
        if(s.size() < 2)
            return true;
        size_t i = -1, j = s.size();
        while(1) {
            while(1) {
                if(++i == j)
                    return true;
                if(s[i] <= 'Z' && s[i] >= 'A') {
                    s[i] = s[i]-'A'+'a';
                    break;
                } else if(s[i] <= 'z' && s[i] >= 'a') {
                    break;
                } else if(s[i] <= '9' && s[i] >= '0') {
                    break;
                }
            }
            while(1) {
                if(--j == i)
                    return true;
                if(s[j] <= 'Z' && s[j] >= 'A') {
                    s[j] = s[j]-'A'+'a';
                    break;
                } else if(s[j] <= 'z' && s[j] >= 'a') {
                    break;
                } else if(s[j] <= '9' && s[j] >= '0') {
                    break;
                }
            }
            if(s[i] != s[j])
                return false;
        }
    }
    bool isPalindrome(string s) {
        if(s.size() < 2)
            return true;
        size_t i = -1, j = s.size();
        while(1) {
            while(1) {
                if(++i == j)
                    return true;
                if(isalnum(s[i]))
                    break;
            }
            while(1) {
                if(--j == i)
                    return true;
                if(isalnum(s[j]))
                    break;
            }
            if(tolower(s[i]) != tolower(s[j]))
                return false;
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << Solution().isPalindrome("ab2a") << endl;
    cout << Solution().isPalindrome("0P") << endl;
    cout << Solution().isPalindrome("A a") << endl;
    cout << Solution().isPalindrome("A man, a p: Panama") << endl;
    cout << Solution().isPalindrome("A man, a plaal: Panama") << endl;
    cout << Solution().isPalindrome("an, ana") << endl;
    cout << Solution().isPalindrome("lan, anal: ") << endl;
    cout << Solution().isPalindrome(" plan, anal: P") << endl;
    cout << Solution().isPalindrome("an, a plan, anal: Pana") << endl;
    cout << Solution().isPalindrome("A man, a plan, anal: Panama") << endl;
    cout << Solution().isPalindrome("A man, a plan, a canal: Panama") << endl;
    cout << Solution().isPalindrome("race a car") << endl;
    return 0;
}
#endif