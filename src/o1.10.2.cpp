#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    constexpr static int mod = 1e9 + 7;
public:
    int numWays(int n) {
        int i = 0, j = 1;
        while (n >= 0) {
            j = (i + j) % mod;
            swap(i, j);
            n--;
        }
        return i;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int n = 2;
        cout << Solution().numWays(n) << endl;
    }
    cout << " 2:" << endl;
    {
        int n = 7;
        cout << Solution().numWays(n) << endl;
    }
    cout << " 3:" << endl;
    {
        int n = 21;
        cout << Solution().numWays(n) << endl;
    }
    return 0;
}
#endif