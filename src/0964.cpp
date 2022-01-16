#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {}
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(false);
    cout << " 1:" << endl;
    {
        int x      = 3;
        int target = 19;
        cout << Solution().leastOpsExpressTarget(x, target) << endl;
    }
    cout << " 2:" << endl;
    {
        int x      = 5;
        int target = 501;
        cout << Solution().leastOpsExpressTarget(x, target) << endl;
    }
    cout << " 3:" << endl;
    {
        int x      = 100;
        int target = 100000000;
        cout << Solution().leastOpsExpressTarget(x, target) << endl;
    }
    return 0;
}
#endif