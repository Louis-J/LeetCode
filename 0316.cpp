#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.size() <= 1)
            return s;
        
        vector<char> v{27};
        size_t all[26] = {};
        size_t nums = 0;
        for(int i = 0; i < s.size(); i++) {
            auto &ref = all[s[i]-'a'];
            v.emplace_back(s[i]-'a');
            if(ref == 0)
                nums++;
            ref++;
        }
        string ret;
        bool have[26] = {};
        size_t starti = 1;

        for(int i = 1; nums != 0; i++) {
            if(!have[v[i]] && --all[v[i]] == 0) {
                while(1) {
                    size_t minj = 0;
                    for(size_t j = starti; j <= i; j++) {
                        if(!have[v[j]] && v[j] < v[minj])
                            minj = j;
                    }
                    ret += s[minj-1];
                    nums--;
                    have[v[minj]] = true;
                    starti = minj+1;
                    if(v[minj] == v[i])
                        break;
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     cout << Solution().removeDuplicateLetters("bcabc") << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     cout << Solution().removeDuplicateLetters("cbacdcbc") << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     cout << Solution().removeDuplicateLetters("baa") << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     cout << Solution().removeDuplicateLetters("baab") << endl;
    // }
    cout << " 5:" << endl;
    {
        cout << Solution().removeDuplicateLetters("caccabad") << endl;
    }
    return 0;
}
#endif