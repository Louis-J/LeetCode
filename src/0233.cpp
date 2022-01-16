#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0)
            return 0;
        //最高位位数
        int dig;
        if(n >= 1000000000)
            dig = 1000000000;
        else {
            for(dig = 1; dig <= n; dig *= 10) {}
            dig /= 10;
        }

        //最高位处1数量
        int sum = 0;
        if(n >= 2*dig) {
            sum += dig;
        } else {
            sum += n-dig+1;
        }

        //每一位处1数量
        while(dig != 1) {
            int tmp0 = n%dig;//零头部分

            dig/=10;
            if(tmp0 >= 2*dig)
                sum += dig;
            else if(tmp0 >= dig)
                sum += tmp0-dig+1;

            sum += (n/dig)/10*dig;//非零头部分
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().countDigitOne(13) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().countDigitOne(0) << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().countDigitOne(1) << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().countDigitOne(9) << endl;
    }
    cout << " 5:" << endl;
    {
        cout << Solution().countDigitOne(10) << endl;
    }
    cout << " 6:" << endl;
    {
        cout << Solution().countDigitOne(100) << endl;
    }
    cout << " 7:" << endl;
    {
        cout << Solution().countDigitOne(1000) << endl;
    }
    cout << " 8:" << endl;
    {
        cout << Solution().countDigitOne(110) << endl;
    }
    cout << " 9:" << endl;
    {
        cout << Solution().countDigitOne(111) << endl;
    }
    return 0;
}
#endif