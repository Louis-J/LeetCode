#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    // 最垃圾的方法, 多次二分
    bool findNumberIn2DArray0(vector<vector<int>> &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0 || matrix[0][0] > target) return false;
        int xSize = matrix.size();
        int ySize = matrix[0].size();

        int xLen, yLen;

        int i, j, middle;

        i = 0, j = xSize - 1;
        while(i != j) {
            middle = (i + j) / 2;
            if(matrix[middle][0] < target)
                i = middle + 1;
            else
                j = middle;
        }
        if(matrix[i][0] == target) return true;
        if(matrix[i][0] < target)
            xLen = i;
        else
            xLen = i - 1;

        i = 0, j = ySize - 1;
        while(i != j) {
            middle = (i + j) / 2;
            if(matrix[0][middle] < target)
                i = middle + 1;
            else
                j = middle;
        }
        if(matrix[0][i] == target) return true;
        if(matrix[0][i] < target)
            yLen = i;
        else
            yLen = i - 1;

        for(int x = 0; x <= xLen; x++) {
            i = 0, j = yLen;
            while(i != j) {
                middle = (i + j) / 2;
                if(matrix[x][middle] < target)
                    i = middle + 1;
                else
                    j = middle;
            }
            if(matrix[x][i] == target) return true;
        }
        return false;
    }
    // 立体的二分,
    // 对一个矩形区域，得到一个中间点，目标值在中间点的右上矩形或左下矩形里，递归判断右上矩形或左下矩形里是否存在
    // 复杂度为log(m+n)*log(m+n), 还没看到比这个快的
    bool findHelper(vector<vector<int>> &matrix, int target, pair<int, int> pUL, pair<int, int> pDR) {
        if((pUL.first == pDR.first && pUL.second == pDR.second) || matrix[pUL.first][pUL.second] >= target)
            return matrix[pUL.first][pUL.second] == target;

        pair<int, int> point;

        pair<int, int> i = pUL, j = pDR;
        while(i.first != j.first || i.second != j.second) {
            point = {(i.first + j.first) / 2, (i.second + j.second) / 2};
            if(matrix[point.first][point.second] < target) {
                if(point.first != j.first)
                    i.first = ++point.first;
                else
                    i.first = point.first;
                if(point.second != j.second)
                    i.second = ++point.second;
                else
                    i.second = point.second;
            } else
                j = point;
        }
        if(matrix[point.first][point.second] == target) return true;

        if(pUL.first != point.first &&
           findHelper(matrix, target, make_pair(pUL.first, point.second), make_pair(point.first - 1, pDR.second)))
            return true;
        if(pUL.second != point.second &&
           findHelper(matrix, target, make_pair(point.first, pUL.second), make_pair(pDR.first, point.second - 1)))
            return true;
        return false;
    }
    bool findNumberIn2DArray(vector<vector<int>> &matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0) return false;
        return findHelper(matrix, target, {0, 0}, {matrix.size() - 1, matrix[0].size() - 1});
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        cout << Solution().findNumberIn2DArray(matrix, 5) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> matrix = {
            {1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
        cout << Solution().findNumberIn2DArray(matrix, 20) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> matrix = {{-5}};
        cout << Solution().findNumberIn2DArray(matrix, -5) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<int>> matrix = {{1, 4}, {2, 5}};
        cout << Solution().findNumberIn2DArray(matrix, 5) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<vector<int>> matrix = {{+1, +2, +3, +4, +5},
                                      {+6, +7, +8, +9, 10},
                                      {11, 12, 13, 14, 15},
                                      {16, 17, 18, 19, 20},
                                      {21, 22, 23, 24, 25}};
        cout << Solution().findNumberIn2DArray(matrix, 15) << endl;
    }

    return 0;
}
#endif