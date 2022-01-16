#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static inline bool isInterleaveImpl(string &s1, string &s2, string &s3, size_t s1e, size_t s2e, size_t s3e) {
        if(s1e == 0 || s2e == 0) {
            if(s1e == 0)
                return s2.compare(0, s2e, s3, 0, s3e) == 0;
            else
                return s1.compare(0, s1e, s3, 0, s3e) == 0;
        } else if(s1[s1e-1] == s2[s2e-1]) {
            if(s1[s1e-1] == s3[s3e-1]) {
                return isInterleaveImpl(s1, s2, s3, s1e-1, s2e, s3e-1)
                    || isInterleaveImpl(s1, s2, s3, s1e, s2e-1, s3e-1);
            } else {
                return false;
            }
        } else if(s1[s1e-1] == s3[s3e-1]) {
            return isInterleaveImpl(s1, s2, s3, s1e-1, s2e, s3e-1);
        } else if(s2[s2e-1] == s3[s3e-1]) {
            return isInterleaveImpl(s1, s2, s3, s1e, s2e-1, s3e-1);
        } else {
            return false;
        }
    }
public:
    //递归，复杂度过高
    bool isInterleave0(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        } else if(s1.size() == 0) {
            return s2 == s3;
        } else if(s2.size() == 0) {
            return s1 == s3;
        } else {
            int s12c[128] = {0};
            int s3c[128] = {0};
            for(auto &i : s1)
                s12c[i]++;
            for(auto &i : s2)
                s12c[i]++;
            for(auto &i : s3)
                s3c[i]++;
            for(int i = 0; i < 128; i++)
                if(s12c[i] != s3c[i])
                    return false;
            return isInterleaveImpl(s1, s2, s3, s1.size(), s2.size(), s3.size());
        }
    }
    //复杂度O(M*N)
    bool isInterleave1(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) {
            return false;
        } else if(s1.size() == 0) {
            return s2 == s3;
        } else if(s2.size() == 0) {
            return s1 == s3;
        } else {
            const auto M = s1.size(), N = s2.size();
            bool il[M+1][N+1];
            il[0][0] = true;
            size_t i, j;
            for(i = 1; i <= M && s1[i-1] == s3[i-1]; i++)
                il[i][0] = true;
            for(; i <= M; i++)
                il[i][0] = false;
            for(i = 1; i <= N && s2[i-1] == s3[i-1]; i++)
                il[0][i] = true;
            for(; i <= N; i++)
                il[0][i] = false;
            
            for(i = 1; i <= M; i++) {
                for(j = 1; j <= N; j++) {
                    if((il[i][j-1] && s2[j-1] == s3[i+j-1]) || (il[i-1][j] && s1[i-1] == s3[i+j-1]))
                        il[i][j] = true;
                    else
                        // break;
                        il[i][j] = false;
                }
                // for(; j <= N; j++)
                //     il[i][j] = false;
            }
            // for(size_t i = 0; i <= M; i++) {
            //     for(size_t j = 0; j <= N; j++)
            //         cout << il[i][j] << ' ';
            //     cout << endl;
            // }
            return il[M][N];
        }
    }
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave1(s1, s2, s3);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac";
        cout << Solution().isInterleave(s1, s2, s3) << endl;
    }
    cout << "2:" << endl;
    {
        string s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc";
        cout << Solution().isInterleave(s1, s2, s3) << endl;
    }
    return 0;
}
#endif