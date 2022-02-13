#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int solution(vector<int> &A) {
        // write your code in C++14 (g++ 6.2.0)
        for(int i = 0; i < A.size();) {
            if(A[i] > 0 && A[i] <= A.size()) {
                if(A[i] == i + 1) {
                    i++;
                } else if(A[i] == A[A[i] - 1]) {
                    A[i] = 0;
                    i++;
                } else {
                    swap(A[i], A[A[i] - 1]);
                }
            } else if(A[i] != i + 1) {
                A[i] = 0;
                i++;
            }
        }
        for(int i = 0; i < A.size(); i++)
            if(A[i] == 0) return i + 1;
        return A.size() + 1;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<int> A = {1, 2, 3};
        cout << Solution().solution(A) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> A = {1, 3, 6, 4, 1, 2};
        cout << Solution().solution(A) << endl;
    }
    return 0;
}
#endif