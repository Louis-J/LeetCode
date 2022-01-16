#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    using u16 = unsigned short;
    
    //预处理字符串，abc预处理后变成$#a#b#c#^
    static string PreProcess(const string &s)
    {
        const size_t n = s.size();
        string res("$#");
        for(size_t i = 0; i < n; i++) {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('^');//以^作为字符串的结尾
        return res;
    }
    //O(n^2)，先算出每处回文臂长，再用动态规划算出每个长度下的划分次数
    static inline int Manncher(string &s) {
        if (s.size() < 2)
            return 0;

        //Manncher算法 ，o（n）
        string str = PreProcess(s);

        const size_t n = str.size();
        int id = 0, mx = 0;
        auto p = new int[n];
        // vector<int> p(n, 0);
        for(int i = 1; i < n - 1; i++){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //根据正文斜体部分的注释，这里可要可不要
            while(str[i+p[i]] == str[i-p[i]])p[i]++;

            if(i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
        }

        const size_t m = s.size();
        auto q = new int[m];
        // vector<int> q(m);
        q[0] = 0;
        for(size_t i = 1; i < m; i++) {
            if(p[i+2] == i+2)
                q[i] = 0;
            else {
                q[i] = q[i-1]+1;
                for(auto j = 0; j < i-1; j++) {
                    if(q[j] < q[i] && p[i+j+3] >= (i-j-1)+2)
                        q[i] = q[j]+1;
                }
            }
        }
        return q[m-1];
    }
public:
    int minCut(string s) {
        return Manncher(s);
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     cout << Solution().minCut("aab") << endl;
    // }
    cout << "2:" << endl;
    {
        cout << Solution().minCut("abbab") << endl;
    }
    return 0;
}
#endif