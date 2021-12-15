#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int digui(int amount, vector<int>& coins, int amountNow, vector<int>& coinsNow) {
        if(coins.size()-1 == coinsNow.size())
            return (amount - amountNow)%coins[coins.size()-1] == 0;
        else {
            int coinNow = coins[coinsNow.size()];
            size_t sizemax = (amount - amountNow)/coinNow;
            coinsNow.emplace_back(0);
            auto &v = coinsNow[coinsNow.size()-1];
            size_t ret = 0;
            for(v = 0; v <= sizemax; v++)
                ret += digui(amount, coins, amountNow+coinNow*v, coinsNow);
            coinsNow.resize(coinsNow.size()-1);
            return ret;
        }
    }
    //复杂度为amount的coins.size()次方，复杂度过高超时
    int change0(int amount, vector<int>& coins) {
        if(coins.size() == 0)
            return amount == 0;
        else if(coins.size() == 1)
            return amount % coins[0] == 0;
        sort(coins.begin(), coins.end(), greater<int>());
        vector<int> coinsNow;
        coinsNow.reserve(coins.size());
        return digui(amount, coins, 0, coinsNow);
    }

    //背包，复杂度为amount*coins.size()
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        else if(coins.size() == 0)
            return 0;
        else if(coins.size() == 1)
            return amount % coins[0] == 0;

        //LC报错，需要手动赋值
        //size_t kind[amount+1] = {1};
        size_t kind[amount+1];
        kind[0] = 1;
        for(size_t i = 1; i < amount+1; i++)
            kind[i] = 0;
            
        for(auto &c : coins) {
            for(size_t i = c; i < amount+1; i++)
                kind[i] += kind[i-c];
        }
        return kind[amount];
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> coins = {1, 2, 5};
        cout << Solution().change(5, coins) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> coins = {2};
        cout << Solution().change(3, coins) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> coins = {2};
        cout << Solution().change(2, coins) << endl;
    }
    return 0;
}
#endif