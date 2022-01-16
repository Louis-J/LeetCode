#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        if(n == 1) return 1;
        vector<vector<int>> graph(n);
        for(auto &edge : edges) {
            graph[edge[0]].emplace_back(edge[1]);
            graph[edge[1]].emplace_back(edge[0]);
        }
        for(auto &edge : graph) sort(edge.begin(), edge.end());
        target--;
        double              ret = 0;
        vector<vector<int>> paths;
        vector<vector<int>> pathsNext;
        vector<int>         pathInit(n + 1);
        pathInit[0] = 1;
        pathInit[n] = 0;
        paths.emplace_back(pathInit);

        while(--n) {
            for(auto &path : paths) {
                for(auto &nextp : graph[path[n]]) {
                    if(nextp == target) {
                        if(n == 1)
                        
                    } else if(path[nextp] == 0) {
                        path[nextp] = 1;
                        path[n]     = nextp;
                        pathsNext.emplace_back(path);
                        path[nextp] = 0;
                    }
                }
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int                 n      = 7;
        vector<vector<int>> edges  = {{1, 2}, {1, 3}, {1, 7}, {2, 4}, {2, 6}, {3, 5}};
        int                 t      = 2;
        int                 target = 4;
        cout << Solution().frogPosition(n, edges, t, target) << endl;
    }
    cout << " 2:" << endl;
    {}
    cout << " 3:" << endl;
    {}
    return 0;
}
#endif