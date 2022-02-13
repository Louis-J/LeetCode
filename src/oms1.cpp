#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int solution(int N, vector<int> &A, string &S) {
        int rs[N] = {0};
        int cs[N] = {0};

        int maxR = 0;
        int maxC = 0;

        for(int i = 0; i < A.size(); i++) {
            if(S[i] == 'R') {
                maxR = max(maxR, ++rs[A[i]]);
            } else
                maxC = max(maxC, ++cs[A[i]]);
        }
        return maxR + maxC;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> prices = {7, 1, 5, 3, 6, 4};
        cout << Solution().maxProfit(prices) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> prices = {7, 6, 4, 3, 1};
        cout << Solution().maxProfit(prices) << endl;
    }
    return 0;
}
#endif