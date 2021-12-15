#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int DG(int n, int k, int x) {
        if(k == 0)
            return 1;
        int ret = 0;
        if(x > 2) {
            ret = DG(n, k, x-1);
            int y = x*(x-1)/2;
            n-=x, k-=y;
            for(; n >= 0 && k >= 0; n-=x, k-=y) {
                ret += (n+1)*DG(n, k, x-1);
            }
        } else {
            if(n >= 2*k) {
                ret = 1;
            }
        }
        return ret;
    }
public:
    int kInversePairs(int n, int k) {
        // int x[] = {1, 3, 6}
        //y = x*(x-1)/2
        //x = sqrt(2*y)+1
        /*
        2 1
        3 3
        */
        if(k == 0)
            return 1;
        if(k >= n*(n-1)/2)
            return 1;

        return DG(n, k, sqrt(2.0*k)+1);
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     cout << Solution().kInversePairs(3, 0) << endl;
    //     cout << Solution().kInversePairs(3, 1) << endl;
    // }
    cout << " 2:" << endl;
    {
        //4
        // 2 1 3 4 5
        // 1 3 2 4 5
        // 1 2 4 3 5
        // 1 2 3 5 4
        // cout << Solution().kInversePairs(5, 1) << endl;
        //3
        // 2 1 4 3 5
        // 2 1 3 5 4
        // 1 3 2 5 4
        cout << Solution().kInversePairs(5, 2) << endl;
    }
    // cout << " 3:" << endl;
    // {
    //     cout << Solution().kInversePairs(nums) << endl;
    // }
    return 0;
}
#endif