#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

#ifdef LEETCODE
//输出数组内容，可输出多级嵌套的数组
inline ostream& operator<<(ostream& ostr, vector<vector<char>>& v) {
    ostr << "{\n";
    for(auto &i : v) {
        for(auto &j : i)
            ostr << j << ' ';
        ostr << endl;
    }
    return ostr << "}";
}
#endif
#if 1
class Solution {
    struct qipan {
        static bool xMinus[10][10];
        static bool yMinus[10][10];
        static bool zMinus[10][10];
        int x;
        int y;
        int z;
        int now = -1;
        int valid[9] = {false};
        int size = 0;
        qipan(int x, int y):x(x), y(y), z(x/3+y/3*3) {}
        static void init() {
            fill(&xMinus[0][0], &xMinus[0][0] + sizeof(xMinus), false);
            fill(&yMinus[0][0], &yMinus[0][0] + sizeof(yMinus), false);
            fill(&zMinus[0][0], &zMinus[0][0] + sizeof(zMinus), false);
        }
        void emplace_back(auto i) {
            valid[size++] = i;
        }
        bool next() {
            if(now != -1) {
                xMinus[x][valid[now]] = false;
                yMinus[y][valid[now]] = false;
                zMinus[z][valid[now]] = false;
            }
            for(now++; now < size; now++) {
                int &val = valid[now];
                if(xMinus[x][val] == false 
                    && yMinus[y][val] == false 
                    && zMinus[z][val] == false) {
                    xMinus[x][val] = true;
                    yMinus[y][val] = true;
                    zMinus[z][val] = true;
                    return true;
                }
            }
            now = -1;
            return false;
        }
    };
    void solveOne(vector<vector<char>>& board, qipan &r) {
        int &x = r.x;
        int &y = r.y;
        bool have[9] = {false};
        for (int i = 0; i < 9; i++) {
            if(board[x][i] != '.')
                have[board[x][i] - '1'] = true;
            if(board[i][y] != '.')
                have[board[i][y] - '1'] = true;
        }
        for (int i = x/3*3; i < x/3*3+3; i++)
            for (int j = y/3*3; j < y/3*3+3; j++)
                if(board[i][j] != '.')
                    have[board[i][j] - '1'] = true;
        for (int i = 0; i < 9; i++) {
            if (have[i] == false)
                r.emplace_back(i+1);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        qipan::init();
        vector<qipan> res;
        res.reserve(81);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    res.emplace_back(i, j);
            }
        }
        for(auto i = res.begin(); i != res.end(); i++)
            solveOne(board, *i);

        for(auto i = res.begin(); i != res.end();) {
            if (i->next()) {
                int &x = i->x;
                int &y = i->y;
                board[x][y] = i->valid[i->now] + '0';
                // cout << board << endl;
                i++;
            } else {
                for(i--; !(i->next()); i--) {}
                int &x = i->x;
                int &y = i->y;
                board[x][y] = i->valid[i->now] + '0';
                // cout << board << endl;
                i++;
            }
        }
    }
};
bool Solution::qipan::xMinus[10][10];
bool Solution::qipan::yMinus[10][10];
bool Solution::qipan::zMinus[10][10];
#else
class Solution {
    void solveOne(vector<vector<char>>& board, int &x, int &y, vector<int> &r) {
        bool have[9] = {false};
        for (int i = 0; i < 9; i++) {
            if(board[x][i] != '.')
                have[board[x][i] - '1'] = true;
            if(board[i][y] != '.')
                have[board[i][y] - '1'] = true;
        }
        for (int i = x/3*3; i < x/3*3+3; i++)
            for (int j = y/3*3; j < y/3*3+3; j++)
                if(board[i][j] != '.')
                    have[board[i][j] - '1'] = true;
        
        r.clear();
        r.emplace_back(1);
        for (int i = 0; i < 9; i++) {
            if (have[i] == false)
                r.emplace_back(i+1);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        map<int, vector<int>> res;
        vector<int> tmp;
        tmp.reserve(10);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    res.emplace(i*10+j, tmp);
            }
        }
        for(auto i = res.begin(); i != res.end();) {
            int x = i->first/10;
            int y = i->first%10;
            solveOne(board, x, y, i->second);
            if (i->second.size() != 1) {
                board[x][y] = i->second[1] + '0';
                // cout << board << endl;
                i++;
            } else {
                while(i->second.size() == 1 || i->second.size()-1 == i->second[0]) {
                    board[i->first/10][i->first%10] = '.';
                    i--;
                }
                i->second[0]++;
                int x2 = i->first/10;
                int y2 = i->first%10;
                board[x2][y2] = i->second[i->second[0]] + '0';
                // cout << board << endl;
                i++;
            }
        }
    }
};
#endif

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<vector<char>> board = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
        };
        cout << board << endl;
        Solution().solveSudoku(board);
        cout << board << endl;
    }
    cout << "2:" << endl;
    {
        vector<vector<char>> board = {
            {'.','.','9','7','4','8','.','.','.'},
            {'7','.','.','.','.','.','.','.','.'},
            {'.','2','.','1','.','9','.','.','.'},
            {'.','.','7','.','.','.','2','4','.'},
            {'.','6','4','.','1','.','5','9','.'},
            {'.','9','8','.','.','.','3','.','.'},
            {'.','.','.','8','.','3','.','2','.'},
            {'.','.','.','.','.','.','.','.','6'},
            {'.','.','.','2','7','5','9','.','.'},
        };
        cout << board << endl;
        Solution().solveSudoku(board);
        cout << board << endl;
    }
    
    return 0;
}
#endif