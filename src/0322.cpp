#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        else if(coins.size() == 0)
            return 0;
        else if(coins.size() == 1) {
            if(amount % coins[0] == 0)
                return amount / coins[0];
            else
                return -1;
        }

        size_t nums[amount+1]; //size_t的-1是最大整数
        nums[0] = 0;
        for(size_t i = 1; i < amount+1; i++)
            nums[i] = -1;
            
        for(auto &c : coins) {
            for(size_t i = c; i < amount+1; i++) {
                if(nums[i-c] != -1)
                    nums[i] = min(nums[i], nums[i-c]+1);
            }
        }
        return nums[amount];
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> coins = {1, 2, 5};
        cout << Solution().coinChange(coins, 11) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> coins = {2};
        cout << Solution().coinChange(coins, 3) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> coins = {2};
        cout << Solution().coinChange(coins, 2) << endl;
    }
    return 0;
}
#endif