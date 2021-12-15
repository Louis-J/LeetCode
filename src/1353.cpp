#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    template <typename T>
    class DubArr {
        const int N;
        T *       arr;

    public:
        DubArr(int M, int N) : N(N), arr(new T[M * N]) {}
        ~DubArr() { delete arr; }
        T &at(int i, int j) { return arr[i * N + j]; }
    };

public:
    int maxEvents(vector<vector<int>> &events) {
        const int      M = events.size();
        int            N = 0;
        pair<int, int> normalEvents[M];
        for(int i = 0; i < M; i++) {
            normalEvents[i].first  = events[i][0] - 1;
            normalEvents[i].second = events[i][1] - 1;
            N                      = max(N, normalEvents[i].second);
        }
        N++;

        DubArr<int> dubArr(M, N);
        for(int i = 0; i < M; i++) {
            dubArr.at(i, 0) = 0;
        }
        for(int i = 1; i < N; i++) {
            dubArr.at(0, i) = 0;
        }
        for(int i = 1; i < M; i++) {
            for(int j = 1; j < N; j++) {
                if(normalEvents[i].first <= j && normalEvents[i].second >= j)
                    dubArr.at(i, j) = max(dubArr.at(i, j - 1) + 1, dubArr.at(i - 1, j));
                else
                    dubArr.at(i, j) = max(dubArr.at(i, j - 1), dubArr.at(i - 1, j));
            }
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                cout << dubArr.at(i, j) << ' ';
            }
            cout << endl;
        }
        return dubArr.at(M - 1, N - 1);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}};
        cout << Solution().maxEvents(events) << endl;
        // 3
    }
    cout << "2:" << endl;
    {
        vector<vector<int>> events = {{1, 2}, {2, 3}, {3, 4}, {1, 2}};
        cout << Solution().maxEvents(events) << endl;
        // 4
    }
    cout << "3:" << endl;
    {
        vector<vector<int>> events = {{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}};
        cout << Solution().maxEvents(events) << endl;
        // 4
    }
    cout << "4:" << endl;
    {
        vector<vector<int>> events = {{1, 100000}};
        cout << Solution().maxEvents(events) << endl;
        // 1
    }
    return 0;
}
#endif
