#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //模仿0123并稍加优化，效果一般，O(kn)
    int maxProfit0(int k, vector<int>& prices) {
        if(k == 0 || prices.size() < 2)
            return 0;
        k = min(k, int(prices.size()/2+1));
        vector<int> buys(k, -prices[0]);
        vector<int> sels(k, 0);

        int l = 1;
        for(auto &p : prices) {
            if(-p > buys[0])
                buys[0] = -p;
            else if(buys[0] + p > sels[0]) {
                sels[0] = buys[0] + p;
                if(l < k)
                    l++;
            }
            for(int i = 1; i < l; i++) {
                if(sels[i-1]-p > buys[i])
                    buys[i] = sels[i-1]-p;
                else if(buys[i] + p > sels[i]) {
                    sels[i] = buys[i] + p;
                    if(l < k)
                        l++;
                }
            }
        }
        int ret = sels[l-1];
        if(l >= 2 && sels[l-2] > ret)
            ret = sels[l-2];
        return ret;
    }
    //O(max(n, logk))
    int maxProfit(int k, vector<int>& prices) {
        if(k == 0 || prices.size() < 2)
            return 0;

        multiset<int, std::greater<int>> mps;
        multimap<int, pair<int, int>> comb;
        vector<tuple<size_t, size_t>> profs;

        size_t buyi = 0;
        size_t seli = 0;
        size_t lasti = 0;
        int lastbp = 0;
        for(size_t i = 1; i < prices.size(); i++) {
            if(prices[i] < prices[seli]) {
                mps.emplace(sel - buy);
                if(lasti == buyi-1 && prices[seli] - lastbp) {
                    comb.emplace({});
                }
                buy = prices[i];
                sel = prices[i];
            } else if(buy + p > sel) {
                sel = buy + p;
            }
        }
        mps.emplace(sel);

        k = min(k, int(mps.size()));
        int ret = 0;
        auto it = mps.begin();
        for(size_t i = 0; i < k; i++, it++) {
            ret += *it;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> prices = {1, 2, 3, 4, 5};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> prices = {3, 5, 0, 1};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int> prices = {2, 4, 1};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> prices = {3, 2, 6, 5, 0, 3};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    // cout << " 6:" << endl;
    // {
    //     vector<int> prices = {2, 1, 4};
    //     cout << Solution().maxProfit(2, prices) << endl;
    // }
    cout << " 7:" << endl;
    {
        vector<int> prices = {6, 1, 3, 2, 4, 7};
        cout << Solution().maxProfit(2, prices) << endl;
    }
    return 0;
}
#endif