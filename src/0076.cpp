#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    //思路：建立一个表记录包含的需要各字符的个数
    //使用b e作为段的起始和结束，
    //1.后移e尝试包含所需要的所有字符，然后统计e-b
    //2.后移b去掉一个已包含的字符
    //3.重复12
    string minWindow(string s, string t) {
        if(t.size() == 0)
            return "";
        else if(t.size() == 1)
            return s.find(t[0]) != -1 ? t : "";
        int needNum = 0;
        vector<bool> valid(256);
        vector<int> need(256);
        for(auto &i : t) {
            if(!valid[i]) {
                valid[i] = true;
                needNum++;
            }
            need[i]++;
        }
        int b = -1, e = s.size();
        for(int i = 0, j = 0; j < s.size(); j++) {
            //j后移，找包含
            for(; j < s.size(); j++) {
                if(valid[s[j]]) {
                    need[s[j]]--;
                    if(need[s[j]] == 0) {
                        needNum--;
                        if(needNum == 0) {
                            if(j-i < e-b) {
                                b = i;
                                e = j;
                            }
                            break;
                        }
                    }
                }
            }
            if(j == s.size())
                break;
            //i后移，找不足
            for(; i < j; i++) {
                if(valid[s[i]]) {
                    need[s[i]]++;
                    if(need[s[i]] == 1) {
                        needNum++;
                        if(j-i < e-b) {
                            b = i;
                            e = j;
                        }
                        i++;
                        break;
                    }
                }
            }
        }
        if(b == -1)
            return "";
        else
            return s.substr(b, e-b+1);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        auto S = "ADOBECODEBANC", T = "ABC";
        cout << Solution().minWindow(S, T) << endl;
    }
    cout << "2:" << endl;
    {
        auto S = "aa", T = "aa";
        cout << Solution().minWindow(S, T) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     auto S = "ADOBECODEBANC", T = "ABC";
    //     cout << Solution().minWindow(S, T) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     auto S = "ADOBECODEBANC", T = "ABC";
    //     cout << Solution().minWindow(S, T) << endl;
    // }
    
    return 0;
}
#endif