#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

//x进制，m位个1
//n = (x^m-1) / (x-1)
//x^(m-1) < n < x^m
//(m-1)*log2x < log2n < m*log2x
class Solution {
public:
    string smallestGoodBase(string n) {
        // double num = stod(n);
        // double log2n = log2(num);
        using ld = long double;
        using s64 = long long;
        ld num = stold(n);
        ld log2n = log2(num);
        ld xud, xdd;
        s64 xus, xds;
        for(s64 m = log2n+1; m > 2; m--) {
            ld log2xu = log2n/(m-1);
            ld log2xd = log2n/m;
            xud =  exp2(log2xu);
            xus = xud;
            xdd =  exp2(log2xd);
            xds = xdd;
            if(xus != )
        }
        return "0";
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     //3
    //     cout << Solution().smallestGoodBase("13") << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     //8
    //     cout << Solution().smallestGoodBase("4681") << endl;
    // }
    cout << " 3:" << endl;
    {
        //999999999999999999
        cout << Solution().smallestGoodBase("1000000000000000000") << endl;
    }
    return 0;
}
#endif