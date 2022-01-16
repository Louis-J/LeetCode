#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    // 判断前 n 位(或前n位和后n位)内容相同, 则递归, 代码十分垃圾, 但有97%的打败
    // 好像优化的挺好的了
    bool isScrambleHelper0(string &s1, string &s2, int s1s, int s2s, int length) {
        if(length == 1)
            return true;
        int orig[128] = {0};
        int head[128] = {0};
        int nail[128] = {0};
        int unequalHead = 0;
        int unequalNail = 0;
        int i = 0;
        do {
            char s1c = s1[s1s + i];
            char s2hc = s2[s2s + i];
            char s2nc = s2[s2s + length - 1 - i];
            orig[s1c]++;
            head[s2hc]++;
            nail[s2nc]++;
            if(s1c != s2hc) {
                switch(orig[s1c] - head[s1c]) {
                    case 0: unequalHead--; break;
                    case 1: unequalHead++; break;
                }
                switch(head[s2hc] - orig[s2hc]) {
                    case 0: unequalHead--; break;
                    case 1: unequalHead++; break;
                }
            }
            if(s1c != s2nc) {
                switch(orig[s1c] - nail[s1c]) {
                    case 0: unequalNail--; break;
                    case 1: unequalNail++; break;
                }
                switch(nail[s2nc] - orig[s2nc]) {
                    case 0: unequalNail--; break;
                    case 1: unequalNail++; break;
                }
            }
            i++;
            if(unequalHead == 0
              && isScrambleHelper0(s1, s2, s1s, s2s, i)
              && isScrambleHelper0(s1, s2, s1s + i, s2s + i, length - i)) {
                return true;
            } else if(unequalNail == 0
              && isScrambleHelper0(s1, s2, s1s, s2s + length - i, i)
              && isScrambleHelper0(s1, s2, s1s + i, s2s, length - i)) {
                return true;
            }
        } while(i < length - 1);
        return false;
    }

    // 优化了下, 0ms, 6.3mb
    static bool isScrambleHelper2(char *cs1, char *cs2, int len) {
        if(len <= 3)
            return true;
        int head[26] = {0};
        int nail[26] = {0};
        int unequalHead = 0;
        int unequalNail = 0;
        int i = 0;
        int len1 = len-1;
        do {
            char s1c = cs1[i] - 'a';
            char s2hc = cs2[i] - 'a';
            char s2nc = cs2[len1 - i] - 'a';

            if(s1c != s2hc) {
                switch(++head[s1c]) {
                    case 0: unequalHead--; break;
                    case 1: unequalHead++; break;
                }
                switch(head[s2hc]--) {
                    case 0: unequalHead++; break;
                    case 1: unequalHead--; break;
                }
            }
            if(s1c != s2nc) {
                switch(++nail[s1c]) {
                    case 0: unequalNail--; break;
                    case 1: unequalNail++; break;
                }
                switch(nail[s2nc]--) {
                    case 0: unequalNail++; break;
                    case 1: unequalNail--; break;
                }
            }
            i++;
            if(unequalHead == 0
              && isScrambleHelper2(cs1, cs2, i)
              && isScrambleHelper2(cs1 + i, cs2 + i, len - i)) {
                return true;
            } else if(unequalNail == 0
              && isScrambleHelper2(cs1, cs2 + len - i, i)
              && isScrambleHelper2(cs1 + i, cs2, len - i)) {
                return true;
            }
        } while(i < len1);
        return false;
    }

    //递归方式
    static bool isScrambleHelper3(char *cs1, char *cs2, int len) {
        using Rinfo = tuple<
            int,    // 存储递归返回值, 0/1为有失败或初始, 2/3为成功一个, 4/5为成功; 偶数正, 奇数反
            char *, // cs1
            char *, // cs2
            int,    // len
            int     // 当前i的值
        >;
        vector<Rinfo> stacks;
        stacks.reserve(len*2);
        stacks.emplace_back(0, nullptr, nullptr, 0, 0);
        stacks.emplace_back(0, cs1, cs2, len, 0);
        
        int strcomp[26] = {0};
        int unequal = 0;
        while(stacks.size() > 1) {
            auto &rref = *(--stacks.end());
            auto &status = get<0>(rref);
            auto &cs1 = get<1>(rref);
            auto &cs2 = get<2>(rref);
            auto &len = get<3>(rref);
            auto &i = get<4>(rref);
            switch(status) {
                case 4:
                case 5:
                    get<0>(stacks[stacks.size()-2]) += 2;
                    stacks.resize(stacks.size()-1);
                break;
                case 2:
                    stacks.emplace_back(0, cs1 + i, cs2 + i, len - i, 0);
                break;
                case 3:
                    stacks.emplace_back(0, cs1 + i, cs2, len - i, 0);
                break;
                case 0: {
                    if(len <= 3) { // 直接返回
                        get<0>(stacks[stacks.size()-2]) += 2;
                        stacks.resize(stacks.size()-1);
                        break;
                    }
                    int len1 = len-1;
                    while(true) {
                        char s1c = cs1[i] - 'a';
                        char s2c = cs2[i] - 'a';
                        if(i == len1) {
                            strcomp[s1c] = 0;
                            strcomp[s2c] = 0;
                            unequal = 0;
                            status = 1;
                            i = 0;
                            break;
                        }

                        if(s1c != s2c) {
                            switch(++strcomp[s1c]) {
                                case 0: unequal--; break;
                                case 1: unequal++; break;
                            }
                            switch(strcomp[s2c]--) {
                                case 0: unequal++; break;
                                case 1: unequal--; break;
                            }
                        }
                        i++;
                        if(unequal == 0) {
                            stacks.emplace_back(0, cs1, cs2, i, 0);
                            break;
                        }
                    }
                    break;
                }
                case 1: {
                    int len1 = len-1;
                    while(true) {
                        char s1c = cs1[i] - 'a';
                        char s2c = cs2[len1 - i] - 'a';
                        if(i == len1) {
                            strcomp[s1c] = 0;
                            strcomp[s2c] = 0;
                            unequal = 0;
                            get<0>(stacks[stacks.size()-2]) %= 2;
                            stacks.resize(stacks.size()-1);
                            break;
                        }

                        if(s1c != s2c) {
                            switch(++strcomp[s1c]) {
                                case 0: unequal--; break;
                                case 1: unequal++; break;
                            }
                            switch(strcomp[s2c]--) {
                                case 0: unequal++; break;
                                case 1: unequal--; break;
                            }
                        }
                        i++;
                        if(unequal == 0) {
                            stacks.emplace_back(0, cs1, cs2 + len - i, i, 0);
                            break;
                        }
                    }
                    break;
                }
            }
        }
        return get<0>(stacks[0]) >= 2;
    }
public:
    bool isScramble0(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        } else if(s1.size() == 0) {
            return true;
        } else {
            int s1c[128] = {0};
            int s2c[128] = {0};
            for(auto &i : s1)
                s1c[i]++;
            for(auto &i : s2)
                s2c[i]++;
            for(int i = 0; i < 128; i++)
                if(s1c[i] != s2c[i])
                    return false;
            return isScrambleHelper0(s1, s2, 0, 0, s1.size());
        }
    }
    bool isScramble2(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        } else if(s1.size() == 0) {
            return true;
        } else {
            int chars[26] = {0};
            int unequal = 0;
            for(auto &i : s1)
                switch(chars[i-'a']++) {
                    case 0: unequal++; break;
                    case -1: unequal--; break;
                }
            for(auto &i : s2)
                switch(chars[i-'a']--) {
                    case 0: unequal++; break;
                    case 1: unequal--; break;
                }
            if(unequal != 0)
                return false;
            return isScrambleHelper2(&s1[0], &s2[0], s1.size());
        }
    }
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size()) {
            return false;
        } else if(s1.size() == 0) {
            return true;
        } else {
            int chars[26] = {0};
            int unequal = 0;
            for(auto &i : s1)
                switch(chars[i-'a']++) {
                    case 0: unequal++; break;
                    case -1: unequal--; break;
                }
            for(auto &i : s2)
                switch(chars[i-'a']--) {
                    case 0: unequal++; break;
                    case 1: unequal--; break;
                }
            if(unequal != 0)
                return false;
            return isScrambleHelper3(&s1[0], &s2[0], s1.size());
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s1 = "great", s2 = "rgeat";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    cout << "000:" << endl;
    {
        cout << Solution().isScramble("abc", "acb");
        cout << Solution().isScramble2("abc", "acb");
        cout << Solution().isScramble3("abc", "acb") << endl;

        cout << Solution().isScramble("abc", "bac");
        cout << Solution().isScramble2("abc", "bac");
        cout << Solution().isScramble3("abc", "bac") << endl;

        cout << Solution().isScramble("abc", "bca");
        cout << Solution().isScramble2("abc", "bca");
        cout << Solution().isScramble3("abc", "bca") << endl;

        cout << Solution().isScramble("abc", "cab");
        cout << Solution().isScramble2("abc", "cab");
        cout << Solution().isScramble3("abc", "cab") << endl;

        cout << Solution().isScramble("abc", "cba");
        cout << Solution().isScramble2("abc", "cba");
        cout << Solution().isScramble3("abc", "cba") << endl;
    }
    cout << "2:" << endl;
    {
        string s1 = "abcde", s2 = "caebd";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    cout << "3:" << endl;
    {
        string s1 = "hobobyrqd", s2 = "hbyorqdbo";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    cout << "4:" << endl;
    {
        string s1 = "abcdd", s2 = "dbdac";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    cout << "5:" << endl;
    {
        string s1 = "dbdac", s2 = "abcdd";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    cout << "6:" << endl;
    {
        string s1 = "great", s2 = "raget";
        cout << Solution().isScramble(s1, s2);
        cout << Solution().isScramble2(s1, s2);
        cout << Solution().isScramble3(s1, s2) << endl;
    }
    return 0;
}
#endif