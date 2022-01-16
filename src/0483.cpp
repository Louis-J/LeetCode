#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//x进制，m位个1
//n = (x^m-1) / (x-1)
//x^(m-1) < n < x^m
//(m-1)*log2x < log2n < m*log2x
//多次逼近
//数学方法做出，O(1)级别，此方法未在LC出现
class Solution {
public:
    string smallestGoodBase(string n) {
        using ld = long double;
        using s64 = long long;
        ld num = stold(n);
        ld log2n = log2(num);
        ld xu, xd;//根据m算出来的x的上限下限
        for(s64 m = log2n+1; m > 2; m--) {
            ld log2xu = log2n/(m-1);
            ld log2xd = log2n/m;
            xu =  exp2(log2xu);
            xd =  exp2(log2xd);
            while(xu - xd > 1) {//类似取极限，多次逼近，基本在3次以内
                xd = pow(num*(xd-1)+1, 1/ld(m));
                xu = pow(num*(xu-1)+1, 1/ld(m));
            }
            if(s64(xu) != s64(xd)) {
                ld x = ld(s64(xu));
                ld nn = (pow(x, ld(m))-1)/(x-1);
                if(abs(nn - num) < 1)
                    return to_string(s64(xu));
            }
        }
        return to_string(s64(num)-1);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        //3
        cout << Solution().smallestGoodBase("13") << endl;
    }
    cout << " 2:" << endl;
    {
        //8
        cout << Solution().smallestGoodBase("4681") << endl;
    }
    cout << " 3:" << endl;
    {
        //999999999999999999
        cout << Solution().smallestGoodBase("1000000000000000000") << endl;
    }
    return 0;
}
#endif