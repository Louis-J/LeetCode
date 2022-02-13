#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int minp = prices[0];
        int maxp = 0;
        for (auto& p : prices)
            if (p < minp)
                minp = p;
            else if (p - minp > maxp)
                maxp = p - minp;
        return maxp;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> prices = { 7,1,5,3,6,4 };
        cout << Solution().maxProfit(prices) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> prices = { 7,6,4,3,1 };
        cout << Solution().maxProfit(prices) << endl;
    }
    return 0;
}
#endif