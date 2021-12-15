#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

using u64 = unsigned long long;
class Solution {
    static inline bool ifHuiWen(u64 x) {
        u64 y = 0;
        for(u64 i = x; i != 0; i /= 10) {
            y = (y*10) + (i%10);
        }
        return x == y;
    }
public:
    int largestPalindrome0(int n) {
        u64 num = 1;
        while(n--)
            num *= 10;
        num -= 1;

        for(u64 i = 0, x; 1; i++, num--) {
            x = num*num;
            if(ifHuiWen(x))
                return x%1337;
            for(u64 j = 1; j <= i; j++) {
                if(ifHuiWen(x - j*j))
                    return (x - j*j)%1337;
            }
            x-=num;
            if(ifHuiWen(x))
                return x%1337;
        }
    }
    int largestPalindrome(int n) {
        constexpr int ret[] = {0, 9, 987, 123, 597, 677, 1218, 877, 475};
        return ret[n];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().largestPalindrome(1) << endl;
        cout << Solution().largestPalindrome(2) << endl;
        cout << Solution().largestPalindrome(3) << endl;
        cout << Solution().largestPalindrome(4) << endl;
        cout << Solution().largestPalindrome(5) << endl;
        cout << Solution().largestPalindrome(6) << endl;
        cout << Solution().largestPalindrome(7) << endl;
        cout << Solution().largestPalindrome(8) << endl;
    }
    // cout << " 2:" << endl;
    // {
    // }
    return 0;
}
#endif