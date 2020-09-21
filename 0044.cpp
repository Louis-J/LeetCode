#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

#define CHOOSE 2
#if CHOOSE == 0
class Solution {
public:
    bool isMatch(string s, string p) {
        size_t i=0, j=0;
        for(; i < s.size(); i++, j++) {
            switch(p[j]) {
                case '?':
                    break;
                case '*':
                    for(j++;; j++) {
                        if(j == p.size())
                            return i <= s.size();
                        if(p[j] == '?')
                            i++;
                        else if(p[j] != '*')
                            break;
                    }
                    for(int k = s.find(p[j], i); k != -1; k = s.find(p[j], k+1)) {
                        if(this->isMatch(s.substr(k+1), p.substr(j+1)))
                            return true;
                    }
                    return false;
                    break;
                default:
                    if(s[i] != p[j]) {
                        return false;
                    }
                    break;
            }
        }
        if(j == p.size()) {
            return true;
        } else {
            for(; j < p.size(); j++) {
                if(p[j] != '*')
                    return false;
            }
            return true;
        }
        return false;
    }
};
#elif CHOOSE == 1
class Solution {
    string s;
    string p;
    void format(string &unfP) {
        size_t i=0;
        for(; i < unfP.size(); i++) {
            switch(unfP[i]) {
                case '?':
                    p += '?';
                    break;
                case '*':
                    for(i++; i < unfP.size(); i++) {
                        if(unfP[i] == '?')
                            p += '?';
                        else if(unfP[i] != '*')
                            break;
                    }
                    p += '*';
                    i--;
                    break;
                default:
                    p += unfP[i];
                    break;
            }
        }
    }
    size_t nextTo(size_t i) {
        size_t j = i;
        for(; j< p.size(); j++) {
            if(p[j] == '?' || p[j] == '*')
                return j-i;
        }
        return j-i;
    }
    bool isMatchImpl(size_t i, size_t j) {
        for(; i < s.size(); i++, j++) {
            switch(p[j]) {
                case '?':
                    break;
                case '*':{
                    if(j+1 == p.size()) {
                        return true;
                    }
                    size_t nextl = this->nextTo(j+1);
                    for(int k = s.find(&p[j+1], i, nextl); k != -1; k = s.find(&p[j+1], k+1, nextl)) {
                        if(this->isMatchImpl(k+nextl, j+1+nextl))
                            return true;
                    }
                    return false;
                }
                default:
                    // size_t nextl = this->nextTo(j);

                    if(s[i] != p[j]) {
                        return false;
                    }
                    break;
            }
        }
        if(j == p.size()) {//i == s.size() && 
            return true;
        } else if(j+1 == p.size() && p[j] == '*') {
            return true;
        }
        return false;
    }
    bool haveWords() {
        size_t i = 0;
        size_t j = 0;
        for(; i < s.size() && j < p.size(); ) {
            switch(p[j]) {
                case '?':
                    i++;
                    j++;
                    break;
                case '*': {
                    if(j+1 == p.size()) {
                        return true;
                    }
                    size_t nextl = this->nextTo(j+1);
                    size_t k = s.find(&p[j+1], i, nextl);
                    if(k == string::npos) {
                        return false;
                    }
                    i = k+nextl;
                    j += 1+nextl;
                    break;
                }
                default: {
                    size_t nextl = this->nextTo(j);
                    size_t k = s.find(&p[j], i, nextl);
                    if(k == string::npos) {
                        return false;
                    }
                    i = k+nextl;
                    j += nextl;
                    break;
                }
            }
        }
        if(j == p.size()) {
            return true;
        } else if(j+1 == p.size() && p[j] == '*') {
            return true;
        }
        return false;
    }
    bool errorEnds() {
        size_t multMark = p.find_last_of('*');
        size_t j = multMark+1;
        size_t i = s.size() - (p.size() - j);

        for(; i < s.size() && j < p.size(); i++, j++) {
            if(p[j] != '?' && s[i] != p[j]) {
                return true;
            }
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s;
        this->format(p);
        if(!haveWords() || errorEnds()) {
            return false;
        }
        return isMatchImpl(0, 0);
    }
};
#endif

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s = "aa";
        string p = "a";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "2:" << endl;
    {
        string s = "aa";
        string p = "*";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "3:" << endl;
    {
        string s = "cb";
        string p = "?a";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "4:" << endl;
    {
        string s = "adceb";
        string p = "*a*b";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "5:" << endl;
    {
        string s = "acdcb";
        string p = "a*c?b";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "6:" << endl;
    {
        string s = "aaaa";
        string p = "***a";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "7:" << endl;
    {
        string s = "c";
        string p = "*?*";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "8:" << endl;
    {
        string s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
        string p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "9:" << endl;
    {
        string s = "baaabbabbbaabbbbbbabbbaaabbaabbbbbaaaabbbbbabaaaaabbabbaabaaababaabaaabaaaabbabbbaabbbbbaababbbabaaabaabaaabbbaababaaabaaabaaaabbabaabbbabababbbbabbaaababbabbaabbaabbbbabaaabbababbabababbaabaabbaaabbba";
        string p = "*b*ab*bb***abba*a**ab***b*aaa*a*b****a*b*bb**b**ab*ba**bb*bb*baab****bab*bbb**a*a*aab*b****b**ba**abba";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    cout << "10:" << endl;
    {
        string s = "bbbab";
        string p = "*??a?";
        cout << boolalpha << Solution().isMatch(s, p) << endl;
    }
    
    return 0;
}
#endif