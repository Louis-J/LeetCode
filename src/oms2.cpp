#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int solution(vector<int> &V, vector<int> &A, vector<int> &B) {
        int         maxNoBefore1   = 0;
        int         maxNoBefore2   = 0;
        int         maxBeforeAfter = 0;
        vector<int> before(V.size(), -1); // -2: bad; -1: no before; other: index of before;
        for(int i = 0; i < B.size(); i++) {
            if(before[B[i]] != -1) {
                before[B[i]] = -2;
            } else {
                before[B[i]] = A[i];
            }
        }
        for(int i = 0; i < V.size(); i++) {
            if(before[i] == -1) {
                if(V[i] >= maxNoBefore1) {
                    maxNoBefore2 = maxNoBefore1;
                    maxNoBefore1 = V[i];
                } else if(V[i] > maxNoBefore2) {
                    maxNoBefore2 = V[i];
                }
            } else if(before[i] != -2 && before[before[i]] == -1) {
                maxBeforeAfter = max(maxBeforeAfter, V[before[i]] + V[i]);
            }
        }
        return max(maxNoBefore1 + maxNoBefore2, maxBeforeAfter);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> V = {1, 1, 5};
        vector<int> A = {0, 1};
        vector<int> B = {2, 2};
        cout << Solution().solution(V, A, B) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> V = {1, 1, 100, 100};
        vector<int> A = {0, 1, 2};
        vector<int> B = {2, 2, 3};
        cout << Solution().solution(V, A, B) << endl;
    }
    return 0;
}
#endif