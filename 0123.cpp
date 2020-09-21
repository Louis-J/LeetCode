#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    //O(n^2)
    int maxProfit2(vector<int>& prices) {
        const auto N = prices.size();
        int profF[N], profB[N];
        profF[0] = 0;
        for(int i = 1; i < N; i++) {
            profF[i] = profF[i-1];
            for(int j = 0; j < i; j++) {
                if(prices[i] - prices[j] > profF[i])
                    profF[i] = prices[i] - prices[j];
            }
        }
        profB[N-1] = 0;
        for(int i = N-2; i >= 0; i--) {
            profB[i] = profB[i+1];
            for(int j = i+1; j < N; j++) {
                if(prices[j] - prices[i] > profB[i])
                    profB[i] = prices[j] - prices[i];
            }
        }
        // cout << endl;
        // for(int i = 0; i < N; i++)
        //     cout << profF[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < N; i++)
        //     cout << profB[i] << ' ';
        // cout << endl;
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum = max(sum, profF[i]+profB[i]);
        return sum;
    }
    //O(n)
    int maxProfit3(vector<int>& prices) {
        const auto N = prices.size();
        int profF[N], profB[N];
        for(int i = 0, minv = 0, maxv = 0, nminv = 0; i < N; i++) {
            if(prices[i]-prices[nminv] >= prices[maxv] - prices[minv]) {
                maxv = i;
                minv = nminv;
            } else if (prices[i] < prices[nminv]) {
                nminv = i;
            }
            profF[i] = prices[maxv] - prices[minv];
        }
        for(int i = N-1, minv = N-1, maxv = N-1, nmaxv = N-1; i >= 0; i--) {
            if(prices[nmaxv]-prices[i] >= prices[maxv] - prices[minv]) {
                maxv = nmaxv;
                minv = i;
            } else if (prices[i] > prices[nmaxv]) {
                nmaxv = i;
            }
            profB[i] = prices[maxv] - prices[minv];
        }
        // cout << endl;
        // for(int i = 0; i < N; i++)
        //     cout << profF[i] << ' ';
        // cout << endl;
        // for(int i = 0; i < N; i++)
        //     cout << profB[i] << ' ';
        // cout << endl;
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum = max(sum, profF[i]+profB[i]);
        return sum;
    }
    //别人题解
    //非常技巧，本以为应fstBuy<fstSell，但实际并不需要，只需要保证fstSell和secSell即可
    int maxProfit(vector<int>& prices) {
        int fstBuy = -prices[0], fstSell = 0;
        int secBuy = -prices[0], secSell = 0;
        for(auto &p : prices) {
            fstBuy = max(fstBuy, -p);
            fstSell = max(fstSell, fstBuy + p);
            secBuy = max(secBuy, fstSell - p);
            secSell = max(secSell, secBuy + p); 
        }
        return secSell;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    //     cout << Solution().maxProfit(prices) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> prices = {1, 2, 3, 4, 5};
    //     cout << Solution().maxProfit(prices) << endl;
    // }
    cout << "3:" << endl;
    {
        vector<int> prices = {3, 5, 0, 1};
        cout << Solution().maxProfit(prices) << endl;
    }
    return 0;
}
#endif