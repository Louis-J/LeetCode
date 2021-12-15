#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

using u64 = unsigned long long;
class Solution {
    static inline u64 rev(u64 num) {
        u64 ret = 0;
        while (num) {
            ret *= 10;
            ret += num%10;
            num /= 10;
        }
        return ret;
    }
    inline u64 GetU(u64 num, const size_t l) {
        if(num+1 == tens[l])
            return tens[l]+1;

        num += tens[l/2];
        if(num > tens[l])
            return tens[l]-1;
        else
            return num - num%tens[l/2] + rev(num)%tens[l/2];
    }
    inline u64 GetD(u64 num, const size_t l) {
        num -= tens[l/2];
        if(num < tens[l-1])
            return tens[l-1]-1;
        else
            return num - num%tens[l/2] + rev(num)%tens[l/2];
    }
    u64 tens[19] = {1};
public:
    Solution() {
        for(int i = 1; i < 19; i++)
            tens[i] = 10*tens[i-1];
    }
    string nearestPalindromic(string n) {
        u64 num = stoull(n);
        if(num == 0)
            return "1";
        else if(num <= 10)
            return to_string(num-1);

        const size_t l = n.size();

        u64 retnum = num - num%tens[l/2] + rev(num)%tens[l/2];
        if(retnum == num) {
            retnum = GetU(num, l);
            u64 numd = GetD(num, l);
            if(retnum - num >= num - numd)
                retnum = numd;
        } else if(retnum > num) {
            u64 numd = GetD(num, l);
            if(retnum - num >= num - numd)
                retnum = numd;
        } else {
            u64 numu = GetU(num, l);
            if(numu - num < num - retnum)
                retnum = numu;
        }
        return to_string(retnum);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        //121
        cout << Solution().nearestPalindromic("123") << endl;
    }
    cout << " 2:" << endl;
    {
        //9
        cout << Solution().nearestPalindromic("11") << endl;
    }
    cout << " 3:" << endl;
    {
        //101, 99, 131, 1111
        cout << Solution().nearestPalindromic("99") << endl;
        cout << Solution().nearestPalindromic("100") << endl;
        cout << Solution().nearestPalindromic("128") << endl;
        cout << Solution().nearestPalindromic("1100") << endl;
        cout << Solution().nearestPalindromic("358764513820540928") << endl;
    }
    return 0;
}
#endif