#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findIntegers1(int num) {
        if(num <= 2)
            return num+1;
        else if(num <= 5)
            return num;

        int weishu = log2(float(num));
        int zgw = exp2(weishu);
        int fib[32] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
            144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
            10946, 17711, 28657, 46368, 75025, 121393, 196418,
            317811, 514229, 832040, 1346269, 2178309, 3524578
        };

        int sum = fib[weishu]+1;

        num -= zgw;
        if(num >= zgw/2) {
            num = zgw/2-1;
        } else if(num <= 2) {
            return sum+num;
        }
        return sum + findIntegers1(num)-1;
    }

    int findIntegers(int num) {
        if(num <= 2)
            return num+1;
        else if(num <= 5)
            return num;
        int weishu = log2(float(num));
        int zgw = exp2(weishu);
        int fib[32] = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89,
            144, 233, 377, 610, 987, 1597, 2584, 4181, 6765,
            10946, 17711, 28657, 46368, 75025, 121393, 196418,
            317811, 514229, 832040, 1346269, 2178309, 3524578
        };

        int sum = fib[weishu]+1;

        for(weishu--, zgw/=2; weishu >= 0; weishu--, zgw/=2) {
            if(zgw&num) {
                if((zgw*2)&num)
                    return sum + fib[weishu]-1;
                sum += fib[weishu];
            }
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        // cout << Solution().findIntegers(0) << endl;
        // cout << Solution().findIntegers(1) << endl;
        // cout << Solution().findIntegers(2) << endl;
        // cout << "3 = " << Solution().findIntegers(3) << endl;
        // cout << "4 = " << Solution().findIntegers(4) << endl;
        // cout << "5 = " << Solution().findIntegers(5) << endl;
        // cout << "5 = " << Solution().findIntegers(6) << endl;
        // cout << "5 = " << Solution().findIntegers(7) << endl;
        // cout << "6 = " << Solution().findIntegers(8) << endl;
        cout << "7 = " << Solution().findIntegers(9) << endl;
        cout << "8 = " << Solution().findIntegers(10) << endl;
        cout << "8 = " << Solution().findIntegers(11) << endl;
        cout << "8 = " << Solution().findIntegers(12) << endl;
        cout << "8 = " << Solution().findIntegers(14) << endl;
        cout << "9 = " << Solution().findIntegers(16) << endl;
        cout << "11 = " << Solution().findIntegers(18) << endl;
        cout << "11 = " << Solution().findIntegers(19) << endl;
        cout << "12 = " << Solution().findIntegers(20) << endl;
        cout << "18 = " << Solution().findIntegers(38) << endl;
        cout << "18 = " << Solution().findIntegers(39) << endl;
        cout << "34 = " << Solution().findIntegers(100) << endl;
        cout << "4181 = " << Solution().findIntegers(100000) << endl;
    }
    cout << " 2:" << endl;
    {
        // cout << Solution().findIntegers(25000) << endl;
    }
    return 0;
}
#endif