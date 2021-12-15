#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<vector<int>> outerTrees(vector<vector<int>>& points) {
        if(points.size() <= 3)
            return points;
        
        //一条横线
        for(int i = 1;; i++) {
            if(i == points.size())
                return points;
            if(points[i][1] != points[i-1][1])
                break;
        }

        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });

        //一条竖线
        if(points[0][0] == points[points.size()-1][0])
            return points;

        //最左
        int rangeL;
        for(rangeL = 1; points[rangeL][0] == points[rangeL-1][0]; rangeL++) {}
        sort(points.begin(), points.begin()+rangeL, [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        //最右
        int rangeR;
        for(rangeR = points.size()-2; points[rangeR][0] == points[rangeR+1][0]; rangeR--) {}
        rangeR++;
        sort(points.begin()+rangeR, points.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] > b[1];
        });

        map<int, int> lineU {
            {points[rangeL-1][0], points[rangeL-1][1]},
            {points[rangeR][0], points[rangeR][1]},
        }, lineD {
            {points[0][0], points[0][1]},
            {points[points.size()-1][0], points[points.size()-1][1]},
        };

        auto it = lineU.begin();
        auto jt = lineD.begin();
        for(int i = rangeL; i < rangeR; i++) {
            auto itt = it;
            if(it->first == points[i][0]) {
                if(it->second < points[i][1]) {
                    it->second = points[i][1];
                    if(it != lineU.begin()) {
                        it--;
                        while(it != lineU.begin()) {
                            itt = it;
                            itt--;
                            //if((b1-a1) * (x-a0) < (y-a1) * (b0-a0))
                            if((points[i][1] - itt->second)*(it->first - itt->first)
                                <= (it->second - itt->second)*(points[i][0] - itt->first))
                                break;
                            else
                                it = lineU.erase(it);
                            it--;
                        }
                        it++;
                    }
                }
            } else {
                itt++;
                if((itt->second - it->second)*(points[i][0] - it->first)
                    <= (points[i][1] - it->second)*(itt->first - it->first)) {
                    it = lineU.emplace_hint(it, points[i][0], points[i][1]);
                    it--;
                    while(it != lineU.begin()) {
                        itt = it;
                        itt--;
                        //if((b1-a1) * (x-a0) < (y-a1) * (b0-a0))
                        if((points[i][1] - itt->second)*(it->first - itt->first)
                            <= (it->second - itt->second)*(points[i][0] - itt->first))
                            break;
                        else
                            it = lineU.erase(it);
                        it--;
                    }
                    it++;
                }
            }

            auto jtt = jt;
            if(jt->first == points[i][0]) {
                if(jt->second > points[i][1]) {
                    jt->second = points[i][1];
                    if(jt != lineD.begin()) {
                        jt--;
                        while(jt != lineD.begin()) {
                            jtt = jt;
                            jtt--;
                            //if((b1-a1) * (x-a0) > (y-a1) * (b0-a0))
                            if((points[i][1] - jtt->second)*(jt->first - jtt->first)
                                >= (jt->second - jtt->second)*(points[i][0] - jtt->first))
                                break;
                            else
                                jt = lineD.erase(jt);
                            jt--;
                        }
                        jt++;
                    }
                }
            } else {
                jtt++;
                if((jtt->second - jt->second)*(points[i][0] - jt->first)
                    >= (points[i][1] - jt->second)*(jtt->first - jt->first)) {
                    jt = lineD.emplace_hint(jt, points[i][0], points[i][1]);
                    jt--;
                    while(jt != lineD.begin()) {
                        jtt = jt;
                        jtt--;
                        //if((b1-a1) * (x-a0) > (y-a1) * (b0-a0))
                        if((points[i][1] - jtt->second)*(jt->first - jtt->first)
                            >= (jt->second - jtt->second)*(points[i][0] - jtt->first))
                            break;
                        else
                            jt = lineD.erase(jt);
                        jt--;
                    }
                    jt++;
                }
            }
        }

        lineU.erase(lineU.begin());
        lineU.erase(--lineU.end());

        lineD.erase(lineD.begin());
        lineD.erase(--lineD.end());

        vector<vector<int>> ret(points.begin(), points.begin()+rangeL);
        for(it = lineU.begin(); it !=lineU.end(); it++)
            ret.emplace_back(vector<int>{it->first, it->second});

        ret.insert(ret.end(), points.begin()+rangeR, points.end());

        for(auto rjt = lineD.rbegin(); rjt !=lineD.rend(); rjt++)
            ret.emplace_back(vector<int>{rjt->first, rjt->second});
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<vector<int>> points = {
    //         {1,1},{2,2},{2,0},{2,4},{3,3},{4,2}
    //     };
    //     cout << Solution().outerTrees(points) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<vector<int>> points = {
    //         {1,2},{2,2},{4,2}
    //     };
    //     cout << Solution().outerTrees(points) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<vector<int>> points = {
    //         {0, 0}, {0, 2}, {1, 1}, {2, 0}, {2, 2}
    //     };
    //     cout << Solution().outerTrees(points) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<vector<int>> points = {
    //         {0,1},{0,2},{0,8},{1,0},{1,3},{1,6},{2,7},{2,8},{2,9},{3,8},{4,4},{4,6},{5,2},{6,1},{6,7},{7,1},{7,2},{7,4},{8,4},{8,5},{8,7},{9,5},{9,8}
    //     };
    //     cout << Solution().outerTrees(points) << endl;
    // }
    cout << " 5:" << endl;
    {
        zhediePV = true;
        // vector<vector<int>> points = {
        //     {7,4},{5,0},{7,3},{2,1},{5,5},{4,5},{3,5},{7,2},{1,2},{1,4},{4,0},{2,5},{6,1},{6,5},{0,3},{3,0}
        // };
        // sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
        //     return a[0] < b[0];
        // });
        // cout << points << endl;
        vector<vector<int>> points = {
            {3,0},{4,0},{5,0},{6,1},{7,2},{7,3},{7,4},{6,5},{5,5},{4,5},{3,5},{2,5},{1,4},{1,3},{1,2},{2,1},{4,2},{0,3}
        };
        points = Solution().outerTrees(points);
        cout << points << endl;
        cout << Solution().outerTrees(points) << endl;
    }
    return 0;
}
#endif