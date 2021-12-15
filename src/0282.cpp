#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> dungeon = {
            {-2, -3, 3},
            {-5, -10, 1},
            {10, 30, -5},
        };
        cout << Solution().calculateMinimumHP(dungeon) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> dungeon = {
            {100},
        };
        cout << Solution().calculateMinimumHP(dungeon) << endl;
    }
    return 0;
}
#endif