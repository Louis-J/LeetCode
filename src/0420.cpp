#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static inline int GetKind(char c) {
        if(c <= 'Z' && c >= 'A')
            return 1;
        else if(c <= 'z' && c >= 'a')
            return 2;
        else if(c <= '9' && c >= '0')
            return 4;
        else
            return 0;
    }
public:
    int strongPasswordChecker(string s) {
        if(s.size() > 20) {
            int kinds = GetKind(s[0]);

            int cont = 0;

            int l3 = 0;
            int l4 = 0;
            int l5 = 0;
            int l3m = 0;
            for(size_t i = 1; i < s.size(); i++) {
                if(kinds != 7)
                    kinds |= GetKind(s[i]);
                if(s[i] == s[i-1]) {
                    cont++;
                } else {
                    if(cont >= 2) {
                        int ta = (cont-2)/3;
                        int tb = (cont-2)%3;
                        switch(tb) {
                        case 0: l3++; break;
                        case 1: l4++; break;
                        case 2: l5++; break;
                        }
                        l3m += ta;
                    }
                    cont = 0;
                }
            }
            if(cont >= 2) {
                int ta = (cont-2)/3;
                int tb = (cont-2)%3;
                switch(tb) {
                case 0: l3++; break;
                case 1: l4++; break;
                case 2: l5++; break;
                }
                l3m += ta;
            }

            switch(kinds) {
            case 0: kinds = 3; break;
            case 1: kinds = 2; break;
            case 2: kinds = 2; break;
            case 3: kinds = 1; break;
            case 4: kinds = 2; break;
            case 5: kinds = 1; break;
            case 6: kinds = 1; break;
            case 7: kinds = 0; break;
            }

            int rep;
            int remain = s.size()-20;
            
            if(remain >= l3) {
                remain -= l3;
                if(remain >= l4*2) {
                    remain -= l4*2;
                    if(remain >= l5*3) {
                        remain -= l5*3;
                        if(remain >= l3m*3) {
                            rep = 0;
                        } else {
                            rep = l3m-remain/3;
                        }
                    } else {
                        rep = l5-remain/3+l3m;
                    }
                } else {
                    rep = l4-remain/2+l5+l3m;
                }
            } else {
                rep = l3-remain+l4+l5+l3m;
            }
            return s.size()-20+max(kinds, rep);
        } else if(s.size() < 6) {
            if(s.size() <= 3)
                return 6-s.size();
            
            int kinds = GetKind(s[0]);
            int cont = 0;
            for(size_t i = 1; i < s.size(); i++) {
                if(kinds != 7)
                    kinds |= GetKind(s[i]);
                if(s[i] == s[i-1])
                    cont++;
            }

            switch(kinds) {
            case 0: kinds = 3; break;
            case 1: kinds = 2; break;
            case 2: kinds = 2; break;
            case 3: kinds = 1; break;
            case 4: kinds = 2; break;
            case 5: kinds = 1; break;
            case 6: kinds = 1; break;
            case 7: kinds = 0; break;
            }

            // if(kinds == 3)
            //     return 3;
            // else
                return max(kinds, int(6-s.size()));
        } else {
            int kinds = GetKind(s[0]);
            int cont = 0;
            int ret = 0;
            for(size_t i = 1; i < s.size(); i++) {
                if(kinds != 7)
                    kinds |= GetKind(s[i]);
                if(s[i] == s[i-1]) {
                    cont++;
                    if(cont%3 == 2)
                        ret++;
                } else {
                    cont = 0;
                }
            }

            switch(kinds) {
            case 0: ret = max(3, ret); break;
            case 1: ret = max(2, ret); break;
            case 2: ret = max(2, ret); break;
            case 3: ret = max(1, ret); break;
            case 4: ret = max(2, ret); break;
            case 5: ret = max(1, ret); break;
            case 6: ret = max(1, ret); break;
            }
            return ret;
        }

    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        //2
        cout << Solution().strongPasswordChecker("asehbfsahe") << endl;
    }
    cout << " 2:" << endl;
    {
        //1
        cout << Solution().strongPasswordChecker("aa123") << endl;
    }
    cout << " 3:" << endl;
    {
        //2
        cout << Solution().strongPasswordChecker("aaa111") << endl;
    }
    cout << " 4:" << endl;
    {
        //7
        cout << Solution().strongPasswordChecker("aaaaaaaaaaaaaaaaaaaaa") << endl;
    }
    cout << " 5:" << endl;
    {
        //7
        cout << Solution().strongPasswordChecker("..................!!!") << endl;
    }
    cout << " 6:" << endl;
    {
        //3
        cout << Solution().strongPasswordChecker("...") << endl;
    }
    cout << " 7:" << endl;
    {
        //1
        cout << Solution().strongPasswordChecker("aA123") << endl;
    }
    cout << " 8:" << endl;
    {
        //3
        cout << Solution().strongPasswordChecker("1234567890123456Baaaaa") << endl;
    }
    cout << " 9:" << endl;
    {
        //3
        cout << Solution().strongPasswordChecker("aaaabbaaabbaaa123456A") << endl;
    }
    cout << " 10:" << endl;
    {
        //13
        cout << Solution().strongPasswordChecker("aaaaaaaAAAAAA6666bbbbaaaaaaABBC") << endl;
    }
    cout << " 11:" << endl;
    {
        //3
        cout << Solution().strongPasswordChecker("10203040aaaaa50607080B") << endl;
    }
    
    return 0;
}
#endif