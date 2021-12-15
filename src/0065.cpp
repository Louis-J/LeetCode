#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isNumber(string s) {
        size_t i = 0;
        for (;; i++) {//空格
            if (i == s.size())
                return false;
            else if (s[i] == ' ')
                continue;
            else
                break;
        }
        bool numPoint = false;//.前是否有小数点
        if (s[i] == '+' || s[i] == '-')//正负号
            i++;
        if (i == s.size())//整数
            return false;
        else if (s[i] >= '0' && s[i] <= '9')
            numPoint = true;
        else if (s[i] != '.')
            return false;
        for (;; i++) {
            if (i == s.size())
                return true;
            if (s[i] < '0' || s[i] > '9')
                break;
        }
        if (s[i] == '.') {//小数
            i++;
            if (!numPoint && (i == s.size() || s[i] < '0' || s[i] > '9'))
                return false;
            for (;; i++) {
                if (i == s.size())
                    return true;
                if (s[i] < '0' || s[i] > '9')
                    break;
            }
        }
        if (s[i] == 'e') {//指数
            i++;
            if (i != s.size() && (s[i] == '+' || s[i] == '-'))//正负号
                i++;
            if (i == s.size() || s[i] < '0' || s[i] > '9')
                return false;
            for (;; i++) {
                if (i == s.size())
                    return true;
                if (s[i] < '0' || s[i] > '9')
                    break;
            }
        }
        for (;; i++) {//空格
            if (i == s.size())
                return true;
            else if (s[i] == ' ')
                continue;
            else
                return false;
        }
    }
};

#ifdef LEETCODE
int main() {
    vector<string> paras = {
        "0"        ,
        " 0.1 "    ,
        "abc"      ,
        "1 a"      ,
        "2e10"     ,
        " -90e3   ",
        " 1e"      ,
        "e3"       ,
        " 6e-1"    ,
        " 99e2.5 " ,
        "53.5e93"  ,
        " --6 "    ,
        "-+3"      ,
        "95a54e53" ,
        ".1"       ,
        "."        ,
    };
    for (auto &para : paras) {
        cout << "{" << endl;
        cout << "   param : " << para << endl;
        cout << "   result : " << Solution().isNumber(para) << endl;
        cout << "}" << endl;
    }
    return 0;
}
#endif