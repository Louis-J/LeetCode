#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0)
            return 0;
        int buy = -prices[0], sell = 0;
        for(auto &p : prices) {
            buy = max(buy, -p);
            sell = max(sell, buy + p);
        }
        return sell;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> prices = {7,1,5,3,6,4};
        cout << Solution().maxProfit(prices) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> prices = {7,6,4,3,1};
        cout << Solution().maxProfit(prices) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     vector<int> prices = {3, 5, 0, 1};
    //     cout << Solution().maxProfit(prices) << endl;
    // }
    return 0;
}
#endif