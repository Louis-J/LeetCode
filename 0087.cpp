#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    bool isScrambleHelper(string &s1, string &s2, int s1s, int s2s, int length) {
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
              && isScrambleHelper(s1, s2, s1s, s2s, i)
              && isScrambleHelper(s1, s2, s1s + i, s2s + i, length - i)) {
                return true;
            } else if(unequalNail == 0
              && isScrambleHelper(s1, s2, s1s, s2s + length - i, i)
              && isScrambleHelper(s1, s2, s1s + i, s2s, length - i)) {
                return true;
            }
        } while(i < length - 1);
        return false;
    }
public:
    bool isScramble(string s1, string s2) {
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
            return isScrambleHelper(s1, s2, 0, 0, s1.size());
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s1 = "great", s2 = "rgeat";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << "2:" << endl;
    {
        string s1 = "abcde", s2 = "caebd";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    cout << "3:" << endl;
    {
        string s1 = "hobobyrqd", s2 = "hbyorqdbo";
        cout << Solution().isScramble(s1, s2) << endl;
    }
    return 0;
}
#endif