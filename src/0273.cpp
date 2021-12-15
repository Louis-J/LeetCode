#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static inline void addin1000(string &ret, int n) {
        constexpr char *strn1[] = {
            "Zero", "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Eleven",
            "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen",
        };
        constexpr char *strn10[] = {
            "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
        };
        if(n/100 >= 1) {
            ret += strn1[n/100];
            n %= 100;
            if(n == 0) {
                ret += " Hundred";
                return;
            } else
                ret += " Hundred ";
        }
        if(n/10 >= 2) {
            ret += strn10[n/10-2];
            n %= 10;
            if(n == 0) {
                return;
            } else {
                ret += ' ';
                ret += strn1[n];
            }
        } else if(n != 0) {
            ret += strn1[n];
        }
    }
public:
    string numberToWords(int num) {
        if(num == 0)
            return "Zero";
        string ret;
        if(num >= 1000*1000*1000) {
            addin1000(ret, num / (1000*1000*1000));
            num %= (1000*1000*1000);
            if(num == 0) {
                ret += " Billion";
                return ret;
            } else
                ret += " Billion ";
        }
        if(num >= 1000*1000) {
            addin1000(ret, num / (1000*1000));
            num %= (1000*1000);
            if(num == 0) {
                ret += " Million";
                return ret;
            } else
                ret += " Million ";
        }
        if(num >= 1000) {
            addin1000(ret, num / (1000));
            num %= (1000);
            if(num == 0) {
                ret += " Thousand";
                return ret;
            } else
                ret += " Thousand ";
        }
        addin1000(ret, num);
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().numberToWords(123) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().numberToWords(12345) << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().numberToWords(1234567) << endl;
    }
    cout << " 4:" << endl;
    {
        cout << Solution().numberToWords(1234567891) << endl;
    }
    cout << " 5:" << endl;
    {
        cout << Solution().numberToWords(20) << endl;
    }
    return 0;
}
#endif