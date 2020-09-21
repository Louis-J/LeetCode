#ifdef LEETCODE
#include <LeetCodeL.hpp>
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
    //O(n)，算出每处回文臂长，找到最远的能扩展的一位，然后返回扩展后长度
    static inline int Manncher(string &s) {
        if (s.size() < 2)
            return 0;

        //Manncher算法 ，o(n)
        string str = PreProcess(s);

        const size_t n = str.size();
        int id = 0, mx = 0;
        // auto p = new int[n];
        vector<int> p(n, 0);
        
        int minlen = s.size()-1;
        for(int i = 1; i < (n + 1)/2; i++){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //根据正文斜体部分的注释，这里可要可不要
            while(str[i+p[i]] == str[i-p[i]])p[i]++;

            if(i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }
            // $#a#a#c#e
            if(p[i] == i) {
                minlen = s.size()+1-i;
            }
        }
        return minlen;
    }
public:
    string shortestPalindrome(string s) {
        string ret(s.rbegin(), s.rbegin()+Manncher(s));
        ret += s;
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     cout << Solution().shortestPalindrome("aacecaaa") << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     cout << Solution().shortestPalindrome("abcd") << endl;
    // }
    cout << "3:" << endl;
    {
        cout << Solution().shortestPalindrome("aba") << endl;
    }
    return 0;
}
#endif