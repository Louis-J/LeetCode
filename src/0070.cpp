#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int climbStairs(int n) {
        int i = 1, j = 0;
        while(n--) {
            j += i;
            swap(i, j);
        }
        return i;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        int n = 2;
        cout << Solution().climbStairs(n) << endl;
    }
    cout << "2:" << endl;
    {
        int n = 3;
        cout << Solution().climbStairs(n) << endl;
    }
    cout << "3:" << endl;
    {}
    return 0;
}
#endif