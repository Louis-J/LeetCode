#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findComplement(int num) {
        unsigned int n = 1 << 31;
        for(; (num & n) == 0; n /= 2);
        int ret = 0;
        for(n /= 2; n != 0; n /= 2) {
            ret += n-(num & n);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        cout << Solution().findComplement(5) << endl;
    }
    cout << "2:" << endl;
    {
        cout << Solution().findComplement(1) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     cout << Solution().findComplement(prices) << endl;
    // }
    
    return 0;
}
#endif
