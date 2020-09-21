#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    //超时
    static inline int digui0(vector<vector<int>>& matrix, size_t m, size_t n, size_t i, size_t j) {
        int ret = 1;
        if(i > 0 && matrix[i-1][j] < matrix[i][j])
            ret += digui0(matrix, m, n, i-1, j);
        if(i < m-1 && matrix[i+1][j] < matrix[i][j])
            ret = max(ret, 1+digui0(matrix, m, n, i+1, j));
        if(j > 0 && matrix[i][j-1] < matrix[i][j])
            ret = max(ret, 1+digui0(matrix, m, n, i, j-1));
        if(j < n-1 && matrix[i][j+1] < matrix[i][j])
            ret = max(ret, 1+digui0(matrix, m, n, i, j+1));
        return ret;
    }
    static inline void digui1(vector<vector<int>>& matrix, vector<vector<int>>& length, size_t m, size_t n, size_t i, size_t j) {
        int ret = 1;
        if(i > 0 && matrix[i-1][j] < matrix[i][j]) {
            if(length[i-1][j] == 0)
                digui1(matrix, length, m, n, i-1, j);
            ret += length[i-1][j];
        }
        if(i < m-1 && matrix[i+1][j] < matrix[i][j]) {
            if(length[i+1][j] == 0)
                digui1(matrix, length, m, n, i+1, j);
            ret = max(ret, 1+length[i+1][j]);
        }
        if(j > 0 && matrix[i][j-1] < matrix[i][j]) {
            if(length[i][j-1] == 0)
                digui1(matrix, length, m, n, i, j-1);
            ret = max(ret, 1+length[i][j-1]);
        }
        if(j < n-1 && matrix[i][j+1] < matrix[i][j]) {
            if(length[i][j+1] == 0)
                digui1(matrix, length, m, n, i, j+1);
            ret = max(ret, 1+length[i][j+1]);
        }
        length[i][j] = ret;
    }
public:
    int longestIncreasingPath0(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        if(m == 0)
            return 0;
        const size_t n = matrix[0].size();
        if(n == 0)
            return 0;

        int ret = 0;
        for(size_t i = 0; i < m; i++)
            for(size_t j = 0; j < n; j++) {
                if((i == 0 || matrix[i-1][j] <= matrix[i][j]) &&
                    (i == m-1 || matrix[i+1][j] <= matrix[i][j]) &&
                    (j == 0 || matrix[i][j-1] <= matrix[i][j]) &&
                    (j == n-1 || matrix[i][j+1] <= matrix[i][j]))
                    ret = max(ret, digui0(matrix, m, n, i, j));
            }
        return ret;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        const size_t m = matrix.size();
        if(m == 0)
            return 0;
        const size_t n = matrix[0].size();
        if(n == 0)
            return 0;

        int ret = 0;
        vector<vector<int>> length(m, vector<int>(n, 0));
        for(size_t i = 0; i < m; i++)
            for(size_t j = 0; j < n; j++) {
                if((i == 0 || matrix[i-1][j] <= matrix[i][j]) &&
                    (i == m-1 || matrix[i+1][j] <= matrix[i][j]) &&
                    (j == 0 || matrix[i][j-1] <= matrix[i][j]) &&
                    (j == n-1 || matrix[i][j+1] <= matrix[i][j])) {
                    if(length[i][j] == 0)
                        digui1(matrix, length, m, n, i, j);
                    ret = max(ret, length[i][j]);
                }
            }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix = {
            {9, 9, 4},
            {6, 6, 8},
            {2, 1, 1},
        };
        cout << Solution().longestIncreasingPath(matrix) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix = {
            {3, 4, 5},
            {3, 2, 6},
            {2, 2, 1},
        };
        cout << Solution().longestIncreasingPath(matrix) << endl;
    }
    return 0;
}
#endif