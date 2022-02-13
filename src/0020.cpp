#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &c: s) {
            switch(c) {
                case '(': {
                    stk.emplace(c);
                    break;
                }
                case '[': {
                    stk.emplace(c);
                    break;
                }
                case '{': {
                    stk.emplace(c);
                    break;
                }
                case ')': {
                    if(stk.size() == 0)
                        return false;
                    auto first = stk.top();
                    stk.pop();
                    if(first != '(')
                        return false;
                    break;
                }
                case ']': {
                    if(stk.size() == 0)
                        return false;
                    auto first = stk.top();
                    stk.pop();
                    if(first != '[')
                        return false;
                    break;
                }
                case '}': {
                    if(stk.size() == 0)
                        return false;
                    auto first = stk.top();
                    stk.pop();
                    if(first != '{')
                        return false;
                    break;
                }
            }
        }
        return stk.size() == 0;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        auto s = "()";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 2:" << endl;
    {
        auto s = "()[]{}";
        cout << Solution().isValid(s) << endl;
    }
    cout << " 3:" << endl;
    {
        auto s = "(]";
        cout << Solution().isValid(s) << endl;
    }
    return 0;
}
#endif