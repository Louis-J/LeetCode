#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int myAtoi(string str) {
        size_t i = 0;
        unsigned int num = 0;
        bool sign = true;
        while(1) {
            if(i == str.size())
                return 0;
            else if(str[i] == ' ')
                i++;
            else if(str[i] == '-') {
                sign = false;
                i++;
                break;
            } else if(str[i] == '+') {
                i++;
                break;
            } else if(str[i] <= '9' && str[i] >= '0') {
                break;
            } else
                return 0;
        }
        // 2,147,483,647
        while(i < str.size()) {
            if(str[i] < '0' || str[i] > '9')
                break;
            if(num >= 214748365) {
                if(sign)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            num = num*10+str[i]-'0';
            i++;
        }
        if(num + sign > (unsigned int)(2147483648ll))
            if(sign)
                return INT_MAX;
            else
                return INT_MIN;
        else if(sign)
            return num;
        else
            return -num;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().myAtoi("42") << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().myAtoi("  -42") << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().myAtoi("  -2147483647") << endl;
        cout << Solution().myAtoi("  -2147483648") << endl;
        cout << Solution().myAtoi("  +2147483647") << endl;
        cout << Solution().myAtoi("  +2147483648") << endl;
        cout << Solution().myAtoi("  -91283472332") << endl;
    }
    return 0;
}
#endif