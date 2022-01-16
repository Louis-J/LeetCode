#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //之前写的
    string removeDuplicateLetters0(string s) {
        if(s.size() <= 1)
            return s;
        
        //统计每个字母数量, 并转换放入数组v中
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

        //队列操作: 从上一个选用字母到下一个必须要选用的范围内, 选出最小字母, 并选用此字母
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
    string removeDuplicateLetters(string s) {
        if(s.size() <= 1)
            return s;
        
        //统计每个字母数量, 并转换放入数组v中
        vector<char> v;
        size_t all[26] = {};
        for(int i = 0; i < s.size(); i++) {
            char val = s[i]-'a';
            all[val]++;
            v.emplace_back(val);
        }

        string ret;
        bool have[26] = {};
        deque<int> que;
        bool quehave[26] = {};// 必须加, 否则可能会删除有用的字母
        for(size_t i = 0; i < s.size(); i++) {
            if(!have[v[i]]) {
                if(!quehave[v[i]]) {
                    while(que.size() != 0 && (v[que.back()] > v[i])) {
                        quehave[v[que.back()]] = false;
                        que.pop_back();
                    }
                    que.push_back(i);
                    quehave[v[i]] = true;
                }
                if(--all[v[i]] == 0) {
                    while(!have[v[i]] && que.size() != 0) {
                        if(!have[v[que.front()]]) {
                            have[v[que.front()]] = true;
                            ret += s[que.front()];
                        }
                        quehave[v[que.front()]] = false;
                        que.pop_front();
                    }
                }
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().removeDuplicateLetters("bcabc") << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().removeDuplicateLetters("cbacdcbc") << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().removeDuplicateLetters("baa") << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().removeDuplicateLetters("baab") << endl;
    }
    cout << " 5:" << endl;
    {
        cout << Solution().removeDuplicateLetters("caccabad") << endl;
    }
    cout << " 6:" << endl;
    {
        cout << Solution().removeDuplicateLetters("abacb") << endl;
    }
    cout << " 7:" << endl;
    {
        cout << Solution().removeDuplicateLetters("bddbccd") << endl;
    }
    return 0;
}
#endif