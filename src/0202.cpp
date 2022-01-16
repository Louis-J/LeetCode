#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    inline static int NextNum(int n) {
        int ret = 0;
        while(n) {
            char i = n%10;
            n /= 10;
            ret += i*i;
        }
        return ret;
    }
public:
    inline bool isHappy(int n) {
        while(n > 99)
            n = NextNum(n);
        switch(n) {
            case 1:
            case 7:
            case 10:
            case 13:
            case 19:
            case 23:
            case 28:
            case 31:
            case 32:
            case 44:
            case 49:
            case 68:
            case 70:
            case 79:
            case 82:
            case 86:
            case 91:
            case 94:
            case 97:
                return true;
            default:
                return false;
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << (Solution().isHappy(2) ? "true" : "false") << endl;
    cout << (Solution().isHappy(19) ? "true" : "false") << endl;
    cout << (Solution().isHappy(19) ? "true" : "false") << endl;
    cout << (Solution().isHappy(82) ? "true" : "false") << endl;
    cout << (Solution().isHappy(68) ? "true" : "false") << endl;
    cout << (Solution().isHappy(1000) ? "true" : "false") << endl;
    return 0;
}
#endif

// def next(n):
//     r = 0
//     while n != 0:
//         i = n%10
//         n = int(n/10)
//         r += i*i
//     return r

// for i in range(1, 1000):
//     if next(i) > i:
//         print(i)

// for i in range(1, 99):
//     j = next(i)
//     k = next(j)
//     while j != k:
//         j = next(j)
//         k = next(next(k)) 
//     if j == 1:
//         print(i)
