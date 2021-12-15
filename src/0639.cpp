#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

constexpr int ModN = 1e9+7;
class Solution {
public:
    int numDecodings(string s) {
        if(s.size() <= 2) {
            if(s.size() == 1) {
                if(s[0] == '0')
                    return 0;
                else if(s[0] == '*')
                    return 9;
                else
                    return 1;
            } else {
                if(s[0] == '*') {
                    if(s[1] == '0')
                        return 2;
                    else if(s[1] == '*')
                        return 15+81;
                    else if(s[1] <= '6')
                        return 11;
                    else
                        return 10;
                } else if(s[1] == '*') {
                    if(s[0] == '0')
                        return 0;
                    else if(s[0] == '1')
                        return 18;
                    else if(s[0] == '2')
                        return 15;
                    else
                        return 9;
                } else {
                    if(s[0] == '0')
                        return 0;
                    else if(s[1] == '0')
                        return s[0] <= '2';
                    else if(s[0] == '1')
                        return 2;
                    else if(s[0] == '2' && s[1] <= '6')
                        return 2;
                    else
                        return 1;
                }
            }
        }
        int l2, l1;
        if(s[s.size()-1] == '0')
            l2 = 0;
        else if(s[s.size()-1] == '*')
            l2 = 9;
        else
            l2 = 1;
        if(s[s.size()-2] == '*') {
            if(s[s.size()-1] == '0')
                l1 = 2;
            else if(s[s.size()-1] == '*')
                l1 = 15+81;
            else if(s[s.size()-1] <= '6')
                l1 = 11;
            else
                l1 = 10;
        } else if(s[s.size()-1] == '*') {
            if(s[s.size()-2] == '0')
                l1 = 0;
            else if(s[s.size()-2] == '1')
                l1 = 18;
            else if(s[s.size()-2] == '2')
                l1 = 15;
            else
                l1 = 9;
        } else {
            if(s[s.size()-2] == '0')
                l1 = 0;
            else if(s[s.size()-1] == '0')
                l1 = s[s.size()-2] <= '2';
            else if(s[s.size()-2] == '1')
                l1 = 2;
            else if(s[s.size()-2] == '2' && s[s.size()-1] <= '6')
                l1 = 2;
            else
                l1 = 1;
        }
        for(int i = s.size()-3; i >= 0; i--) {
            int tmp;
            if(s[i] == '*') {
                tmp = 9*l1;
                if(s[i+1] == '0')
                    tmp = 2*l2;
                else if(s[i+1] == '*')
                    tmp += 15*l2;
                else if(s[i+1] <= '6')
                    tmp += 2*l2;
                else
                    tmp += l2;
            } else if(s[i+1] == '*') {
                tmp = l1;
                if(s[i] == '0')
                    tmp = 0;
                else if(s[i] == '1')
                    tmp += 9*l2;
                else if(s[i] == '2')
                    tmp += 6*l2;
            } else {
                if(s[i] == '0')
                    tmp = 0;
                else if(s[i+1] == '0')
                    tmp = (s[i] <= '2') * l2;
                else if(s[i] == '1')
                    tmp = l1+l2;
                else if(s[i] == '2' && s[i+1] <= '6')
                    tmp = l1+l2;
                else
                    tmp = l1;
            }
            l2 = l1;
            l1 = tmp%ModN;
        }
        return l1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        // cout << Solution().numDecodings("*") << endl;
        cout << Solution().numDecodings("1*") << endl;
    }
    cout << " 2:" << endl;
    {
        //999
        // cout << Solution().numDecodings("**") << endl;
        cout << Solution().numDecodings("***") << endl;
    }
    cout << " 3:" << endl;
    {
        //404
        // cout << Solution().numDecodings("*0") << endl;
        // cout << Solution().numDecodings("1*0") << endl;
        // cout << Solution().numDecodings("*1*0") << endl;
        // cout << Solution().numDecodings("1*1*0") << endl;
        cout << Solution().numDecodings("*1*1*0") << endl;
    }
    cout << " 4:" << endl;
    {
        //99
        // cout << Solution().numDecodings("1") << endl;
        // cout << Solution().numDecodings("*1") << endl;
        // cout << Solution().numDecodings("0*1") << endl;
        // cout << Solution().numDecodings("10*1") << endl;
        cout << Solution().numDecodings("*10*1") << endl;
    }
    cout << " 5:" << endl;
    {
        // // cout << Solution().numDecodings("1003") << endl;
        // // cout << Solution().numDecodings("90") << endl;
        // // cout << Solution().numDecodings("904") << endl;
        // cout << Solution().numDecodings("*") << endl;
        // cout << Solution().numDecodings("2*") << endl;
        // cout << Solution().numDecodings("72*") << endl;
        // cout << Solution().numDecodings("*72*") << endl;
        cout << Solution().numDecodings("1*72*") << endl;
    }
    cout << " 6:" << endl;
    {
        // cout << Solution().numDecodings("*") << endl;
        // cout << Solution().numDecodings("**") << endl;
        cout << Solution().numDecodings("7**") << endl;
        cout << Solution().numDecodings("*7**") << endl;
        cout << Solution().numDecodings("1*7**") << endl;
    }
    return 0;
}
#endif