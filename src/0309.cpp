#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) {
            return 0;
        }
        // vector<pair<int, int>> dp; //当前盈利; 操作日期(自然买负卖)
        vector<pair<int, int>> dp1; //当前盈利; 操作日期(最后为买)
        vector<int> dp2; //当前盈利(当天为卖)
        dp1.reserve(prices.size());
        dp2.reserve(prices.size());
        dp1.emplace_back(0, 0);
        if(prices[1] < prices[0])
            dp1.emplace_back(0, 1);
        else
            dp1.emplace_back(0, 0);
        dp2.emplace_back(0);
        dp2.emplace_back(prices[1] - prices[0]);

        for(int i = 2; i < prices.size(); i++) {
            dp1.emplace_back(dp1[i-1]);
            if(prices[i] < prices[dp1[i].second]) {
                dp1[i].second = i;
            }
            if(dp2[i-2] > dp1[i].first) {
                dp1[i].first = dp2[i-2];
                dp1[i].second = i;
            }

            dp2.emplace_back(max(dp1[i-1].first - prices[dp1[i-1].second] + prices[i], 
                                dp2[i-1] - prices[i-1] + prices[i]));
        }
        // cout << dp1 << endl << dp2 << endl;
        return max({dp1[prices.size()-1].first, dp2[prices.size()-1], dp2[prices.size()-2]});
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> prices = {1,2,3,0,2};
        cout << Solution().maxProfit(prices) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> prices = {1,2,4,2,5,7,2,4,9,0,9};
        cout << Solution().maxProfit(prices) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> prices = {7,4,2,1};
        cout << Solution().maxProfit(prices) << endl;
    }
    
    return 0;
}
#endif