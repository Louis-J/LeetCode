#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

#include <string_view>
class Solution {
public:
    string orderlyQueue(string S, int K) {
        for(int i = 1;; i++) {
            if(i == S.size())
                return S;
            else if(S[i] != S[i-1])
                break;
        }
        
        if(K != 1) {
            sort(S.begin(), S.end());
            return S;
        } else {
            char minC = 'z';
            for(auto &c: S)
                minC = min(minC, c);

            const int Len = S.size();
            S += S;
            int from = 0;
            while(S[from] != minC)
                from++;

            for(int i = from+1; i < Len; i++) {
                if(S[i] == minC && string_view(&(S[from]), Len) > string_view(&S[i], Len))
                    from = i;
            }
            return S.substr(from, Len);
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        string S = "cba";
        int K = 1;
        cout << Solution().orderlyQueue(S, K) << endl;
    }
    cout << "2:" << endl;
    {
        string S = "baaca";
        int K = 3;
        cout << Solution().orderlyQueue(S, K) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     vector<int> prices = {3, 5, 0, 1};
    //     cout << Solution().maxProfit(prices) << endl;
    // }
    return 0;
}
#endif