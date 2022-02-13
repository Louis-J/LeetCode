#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int solution(int N, vector<int> &A, vector<int> &B, vector<int> &H) {
        vector<char>        incAll(N);  // 1: true; 0: false;
        vector<int>         incThis;
        vector<int>         incNext;
        vector<vector<int>> edgesAll(N);

        for(int i = 0; i < A.size(); i++) {
            edgesAll[A[i]].emplace_back(B[i]);
            edgesAll[B[i]].emplace_back(A[i]);
        }

        int times = 0;
        for(auto &i : H) incThis.emplace_back(i);

        while(incThis.size() != 0) {
            for(auto &i : incThis) incAll[i] = 1;

            for(auto &i : incThis) {
                for(auto &j : edgesAll[i]) {
                    if(incAll[j] == 0) {
                        incNext.emplace_back(j);
                    }
                }
            }

            swap(incThis, incNext);
            incNext.clear();
            times++;
        }

        for(auto &c : incAll)
            if(c == 0) return -1;
        return times - 1;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int N = 6;
        vector<int> A = {0, 1, 1, 3, 0};
        vector<int> B = {1, 2, 3, 4, 5};
        vector<int> H = {2, 4};
        cout << Solution().solution(N, A, B, H) << endl;
    }
    cout << " 2:" << endl;
    {
    }
    return 0;
}
#endif