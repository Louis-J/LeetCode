#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    inline static size_t NextNum(size_t n) {
        size_t digit;
        if(n*10/10 != n)
            digit = 1000000000000000000;
        else {
            digit = 1;
            while(digit <= n)
                digit *= 10;
            digit /= 10;
        }
        size_t sum = 0;
        for(;digit != 0; digit /= 10) {
            sum += (n/digit) * (n/digit);
            n %= digit;
        }
        return sum;
    }
public:
    inline bool isHappy(size_t n) {
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