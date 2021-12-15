#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int calc(string &s, int &b) {
        int val = 0;
        // 0 获取op
        // 1 +
        // 2 -
        // 3 *
        // 4 /
        int op = 0;
        int opnum;
        while(b != s.size()) {
            if(op == 0) {
                switch(s[b++]) {
                case ' ': break;
                case '+': op = 1; opnum = 0; break;
                case '-': op = 2; opnum = 0; break;
                case '*': op = 3; opnum = 0; break;
                case '/': op = 4; opnum = 0; break;
                case '(': {
                    val += calc(s, b);
                } break;
                case ')': return val;
                default: op = 1; opnum = s[b-1]-'0'; break;
                }
            } else {
                if(s[b] <= '9' && s[b] >= '0')
                    opnum = opnum*10-'0'+s[b++];
                else if(s[b] == '(') {
                    opnum = calc(s, ++b);
                } else {
                    switch(op) {
                    case 1: val += opnum; break;
                    case 2: val -= opnum; break;
                    case 3: val *= opnum; break;
                    case 4: val /= opnum; break;
                    }
                    switch(s[b++]) {
                    case ' ': op = 0; break;
                    case '+': op = 1; opnum = 0; break;
                    case '-': op = 2; opnum = 0; break;
                    case '*': op = 3; opnum = 0; break;
                    case '/': op = 4; opnum = 0; break;
                    case '(': {
                        val += calc(s, b);
                    } break;
                    case ')': return val;
                    default: op = 1; opnum = s[b-1]-'0'; break;
                    }
                }
            }
        }
        switch(op) {
        case 1: val += opnum; break;
        case 2: val -= opnum; break;
        case 3: val *= opnum; break;
        case 4: val /= opnum; break;
        }
        return val;
    }
public:
    int calculate(string s) {
        int b = 0;
        return calc(s, b);
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     cout << Solution().calculate("1 + 1") << endl;
    //     cout << Solution().calculate(" 2-1 + 2 ") << endl;
    //     cout << Solution().calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    // }
    cout << " 2:" << endl;
    {
        // cout << Solution().calculate("1-(5)") << endl;
        cout << Solution().calculate("(7)-(0)+(4)") << endl;
    }
    // cout << "2:" << endl;
    // {
    //     auto t = TreeNode::CreateLev({3,1,4,nullopt,nullopt,2});
    //     // cout << t << endl;
    //     Solution().recoverTree(t);
    // }
    return 0;
}
#endif