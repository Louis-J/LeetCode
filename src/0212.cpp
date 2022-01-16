#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    class Trie {
        Trie *next[4] = {};
        bool goin = false;
    public:
        size_t x, y;
        Trie(size_t x, size_t y): x(x), y(y) {}
        bool find(vector<vector<char>>& board, vector<vector<char>>& used, size_t m, size_t n, string &str, size_t len) {
            if(!goin) {
                goin = true;
                if(x > 0)
                    next[0] = new Trie(x-1, y);
                if(x < m-1)
                    next[1] = new Trie(x+1, y);
                if(y > 0)
                    next[2] = new Trie(x, y-1);
                if(y < n-1)
                    next[3] = new Trie(x, y+1);
            }
            if(next[0] && board[x-1][y] == str[len] && !used[x-1][y]) {
                if(len+1 == str.size())
                    return true;
                used[x-1][y] = true;
                if(next[0]->find(board, used, m, n, str, len+1)) {
                    used[x-1][y] = false;
                    return true;
                }
                used[x-1][y] = false;
            }
            if(next[1] && board[x+1][y] == str[len] && !used[x+1][y]) {
                if(len+1 == str.size())
                    return true;
                used[x+1][y] = true;
                if(next[1]->find(board, used, m, n, str, len+1)) {
                    used[x+1][y] = false;
                    return true;
                }
                used[x+1][y] = false;
            }
            if(next[2] && board[x][y-1] == str[len] && !used[x][y-1]) {
                if(len+1 == str.size())
                    return true;
                used[x][y-1] = true;
                if(next[2]->find(board, used, m, n, str, len+1)) {
                    used[x][y-1] = false;
                    return true;
                }
                used[x][y-1] = false;
            }
            if(next[3] && board[x][y+1] == str[len] && !used[x][y+1]) {
                if(len+1 == str.size())
                    return true;
                used[x][y+1] = true;
                if(next[3]->find(board, used, m, n, str, len+1)) {
                    used[x][y+1] = false;
                    return true;
                }
                used[x][y+1] = false;
            }
            return false;
        }
    };
public:
    //较慢
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const size_t m = board.size();
        if(m == 0)
            return vector<string>{};
        const size_t n = board[0].size();
        if(n == 0)
            return vector<string>{};

        vector<Trie*> tries[26];
        for(size_t i = 0; i < m; i++)
            for(size_t j = 0; j < n; j++)
                tries[board[i][j]-'a'].emplace_back(new Trie(i, j));

        vector<string> ret;
        vector<vector<char>> used(m, vector<char>(n, 0));
        for(auto &str : words) {
            if(str.size() > 1)
                for(auto &i : tries[str[0]-'a']) {
                    used[i->x][i->y] = true;
                    if(i->find(board, used, m, n, str, 1)) {
                        used[i->x][i->y] = false;
                        ret.emplace_back(str);
                        break;
                    }
                    used[i->x][i->y] = false;
                }
            else if(str.size() == 1 && tries[str[0]-'a'].size() != 0)
                ret.emplace_back(str);
        }
        return ret;
    }
};


#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<char>> board = {
            {'o', 'a', 'a', 'n'},
            {'e', 't', 'a', 'e'},
            {'i', 'h', 'k', 'r'},
            {'i', 'f', 'l', 'v'},
        };
        vector<string> words = {"oath", "pea", "eat", "rain"};
        // vector<string> words = {"oath", "eat"};
        cout << Solution().findWords(board, words) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> board = {
            {'a', 'b'},
        };
        vector<string> words = {"ab"};
        cout << Solution().findWords(board, words) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<char>> board = {
            {'a', 'a'},
        };
        vector<string> words = {"aaa"};
        cout << Solution().findWords(board, words) << endl;
    }
    return 0;
}
#endif