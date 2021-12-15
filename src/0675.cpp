#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//需学习其他方法
class Solution {
    //BFS
    static int CO(vector<vector<int>>& forest, int x1, int y1, int x2, int y2) {
        int m = forest.size(), n = forest[0].size();

        vector<vector<int>> lens(forest.size(), vector<int>(forest[0].size()));
        queue<tuple<int, int, int>> que;
        lens[x1][y1] = 1;
        que.emplace(x1, y1, 1);
        while(que.size() != 0) {
            auto f = que.front();
            que.pop();
            auto &x = get<0>(f), &y = get<1>(f), &l = get<2>(f);

            if(abs(x-x2)+abs(y-y2) == 1)
                return l;
            l++;
            if(x > 0 && forest[x-1][y] != 0 && lens[x-1][y] == 0) {
                lens[x-1][y] = l;
                que.emplace(x-1, y, l);
            }
            if(x < m-1 && forest[x+1][y] != 0 && lens[x+1][y] == 0) {
                lens[x+1][y] = l;
                que.emplace(x+1, y, l);
            }
            if(y > 0 && forest[x][y-1] != 0 && lens[x][y-1] == 0) {
                lens[x][y-1] = l;
                que.emplace(x, y-1, l);
            }
            if(y < n-1 && forest[x][y+1] != 0 && lens[x][y+1] == 0) {
                lens[x][y+1] = l;
                que.emplace(x, y+1, l);
            }
        }
        return -1;
    }
    inline static int CO21(int *newf, int M, int N, int x1, int y1, int x2, int y2) {
        int visit[M*N];
        for(int i = 1; i < M; i++)
            for(int j = 1; j < N; j++)
                visit[i*N+j] = 0;
        vector<tuple<int, int>> que1;
        vector<tuple<int, int>> que2;
        visit[x1*N+y1] = 1;
        que1.emplace_back(x1, y1);
        int l = 1;

        while(que1.size() != 0) {
            for(auto &f : que1) {
                auto &x = get<0>(f), &y = get<1>(f);

                if(abs(x-x2)+abs(y-y2) == 1)
                    return l;
                if(newf[(x-1)*N+y] != 0 && visit[(x-1)*N+y] == 0) {
                    visit[(x-1)*N+y] = l;
                    que2.emplace_back(x-1, y);
                }
                if(newf[(x+1)*N+y] != 0 && visit[(x+1)*N+y] == 0) {
                    visit[(x+1)*N+y] = l;
                    que2.emplace_back(x+1, y);
                }
                if(newf[x*N+(y-1)] != 0 && visit[x*N+(y-1)] == 0) {
                    visit[x*N+(y-1)] = l;
                    que2.emplace_back(x, y-1);
                }
                if(newf[x*N+(y+1)] != 0 && visit[x*N+(y+1)] == 0) {
                    visit[x*N+(y+1)] = l;
                    que2.emplace_back(x, y+1);
                }
            }
            l++;
            swap(que1, que2);
            que2.clear();
        }
        return -1;
    }
    inline static int CO22(int *newf, int M, int N, int x2, int y2, int x1, int y1, int x3, int y3) {
        int visit[M*N];
        for(int i = 1; i < M-1; i++)
            for(int j = 1; j < N-1; j++)
        // for(int i = 0; i < M; i++)
        //     for(int j = 0; j < N; j++)
                visit[i*N+j] = 0;
        vector<tuple<int, int>> que1;
        vector<tuple<int, int>> que2;
        visit[x1*N+y1] = 1;
        que1.emplace_back(x1, y1);
        int l = 1;
        int ret1 = 0, ret2 = 0;

        while(que1.size() != 0) {
            for(auto &f : que1) {
                auto &x = get<0>(f), &y = get<1>(f);

                if(!ret1) {
                    if(abs(x-x2)+abs(y-y2) == 1) {
                        ret1 = l;
                        if(ret2)
                            return ret1+ret2;
                    }
                }
                if(!ret2) {
                    if(abs(x-x3)+abs(y-y3) == 1) {
                        ret2 = l;
                        if(ret1)
                            return ret1+ret2;
                    }
                }
                if(newf[(x-1)*N+y] != 0 && visit[(x-1)*N+y] == 0) {
                    visit[(x-1)*N+y] = l;
                    que2.emplace_back(x-1, y);
                }
                if(newf[(x+1)*N+y] != 0 && visit[(x+1)*N+y] == 0) {
                    visit[(x+1)*N+y] = l;
                    que2.emplace_back(x+1, y);
                }
                if(newf[x*N+(y-1)] != 0 && visit[x*N+(y-1)] == 0) {
                    visit[x*N+(y-1)] = l;
                    que2.emplace_back(x, y-1);
                }
                if(newf[x*N+(y+1)] != 0 && visit[x*N+(y+1)] == 0) {
                    visit[x*N+(y+1)] = l;
                    que2.emplace_back(x, y+1);
                }
            }
            l++;
            swap(que1, que2);
            que2.clear();
        }
        return -1;
    }
public:
    int cutOffTree0(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();
        
        if(forest[0][0] == 0)
            return -1;
        vector<tuple<int, int, int>> trees;
        // trees.emplace_back(0, 0, 0);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(forest[i][j] >= 2)
                    trees.emplace_back(forest[i][j], i, j);
        sort(trees.begin(), trees.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return get<0>(a) < get<0>(b);
        });
        int sum = 0;
        if(get<1>(trees[0]) != 0 || get<2>(trees[0]) != 0) {
            int ret = CO(forest, 0, 0, get<1>(trees[0]), get<2>(trees[0]));
            if(ret == -1)
                return -1;
            sum += ret;
            forest[get<1>(trees[0])][get<2>(trees[0])] = 1;
        } else
            forest[0][0] = 1;
        for(int i = 1; i < trees.size(); i++) {
            int ret = CO(forest, get<1>(trees[i-1]), get<2>(trees[i-1]), get<1>(trees[i]), get<2>(trees[i]));
            if(ret == -1)
                return -1;
            sum += ret;
            forest[get<1>(trees[i])][get<2>(trees[i])] = 1;
        }
        return sum;
    }
    //常数时间部分优化，如数组等
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size(), n = forest[0].size();

        int M = m+2, N = n+2;
        int newf[M*N];
        for(int *p1 = newf, *p2 = newf+(M-1)*N, i = 0; i < N; i++)
            p1[i] = p2[i] = 0;
        for(int *p1 = newf+N, *p2 = newf+N+N-1, i = m; i--; p1 += N, p2 += N)
            *p1 = *p2 = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                newf[(i+1)*N+j+1] = forest[i][j];
        

        vector<tuple<int, int, int>> trees;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                if(newf[i*N+j] >= 2)
                    trees.emplace_back(newf[i*N+j], i, j);

        sort(trees.begin(), trees.end(), [](tuple<int, int, int> &a, tuple<int, int, int> &b) {
            return get<0>(a) < get<0>(b);
        });

        int sum = 0;
        if(get<1>(trees[0]) != 1 || get<2>(trees[0]) != 1) {
            int ret = CO21(newf, M, N, 1, 1, get<1>(trees[0]), get<2>(trees[0]));
            if(ret == -1)
                return -1;
            sum += ret;
        } else
            newf[1*N+1] = 1;
        if(trees.size()%2 == 0) {
            int ret = CO21(newf, M, N, get<1>(trees[trees.size()-1]), get<2>(trees[trees.size()-1]), get<1>(trees[trees.size()-2]), get<2>(trees[trees.size()-2]));
            if(ret == -1)
                return -1;
            sum += ret;
        }
        for(int i = 1; i < trees.size()-1; i+=2) {
            int ret = CO22(newf, M, N, get<1>(trees[i-1]), get<2>(trees[i-1]), get<1>(trees[i]), get<2>(trees[i]), get<1>(trees[i+1]), get<2>(trees[i+1]));
            if(ret == -1)
                return -1;
            sum += ret;
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        //6
        vector<vector<int>> forest {
            {1,2,3},
            {0,0,4},
            {7,6,5}
        };
        cout << Solution().cutOffTree(forest) << endl;
    }
    cout << " 2:" << endl;
    {
        //-1
        vector<vector<int>> forest {
            {1,2,3},
            {0,0,0},
            {7,6,5}
        };
        cout << Solution().cutOffTree(forest) << endl;
    }
    cout << " 3:" << endl;
    {
        //6
        vector<vector<int>> forest {
            {2,3,4},
            {0,0,5},
            {8,7,6}
        };
        cout << Solution().cutOffTree(forest) << endl;
    }
    cout << " 4:" << endl;
    {
        //6
        vector<vector<int>> forest {
            {54581641,64080174,24346381,69107959},
            {86374198,61363882,68783324,79706116},
            {668150,92178815,89819108,94701471},
            {83920491,22724204,46281641,47531096},
            {89078499,18904913,25462145,60813308},
        };
        cout << Solution().cutOffTree(forest) << endl;
    }
    
    return 0;
}
#endif