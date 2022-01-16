#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rlt;

        vector<bool> a(n, false);
        vector<bool> b(n, false);
        vector<bool> c(2*n-1, false);
        vector<bool> d(2*n-1, false);

        vector<int> pos(n, -1);
        vector<string> pic = [&n] {
            string tmp(n, '.');
            return vector<string>(n, tmp);
        }();
        for(int i = 0;; i++) {
            auto next = [&] {
                //清除上次运算的副作用
                if(pos[i] != -1) {
                    a[i] = b[pos[i]] = c[i+pos[i]] = d[n-1-i+pos[i]] = false;
                    pic[i][pos[i]] = '.';
                }
                //贪婪 遍历
                for(int j = pos[i]+1; j < n; j++) {
                    if(!a[i] && !b[j] && !c[i+j] && !d[n-1-i+j]) {
                        pos[i] = j;
                        pic[i][j] = 'Q';
                        a[i] = b[j] = c[i+j] = d[n-1-i+j] = true;
                        return true;
                    }
                }
                //清除本次运算的副作用
                pos[i] = -1;
                return false;
            };
            bool t = next();
            if(!t || i == n-1) {
                if(t && i == n-1) {
                    rlt.emplace_back(pic);
                    next();
                }
                for(i--; i >= 0 && !next(); i--) {}
                if(i < 0)
                    return rlt;
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     int n = 1;
    //     cout << Solution().solveNQueens(n) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     int n = 2;
    //     cout << Solution().solveNQueens(n) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     int n = 3;
    //     cout << Solution().solveNQueens(n) << endl;
    // }
    cout << "4:" << endl;
    {
        int n = 4;
        cout << Solution().solveNQueens(n) << endl;
    }
    
    return 0;
}
#endif