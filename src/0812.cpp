#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    inline static bool equals(pair<int, int> &pa, pair<int, int> &pb) {
        return pa.first == pb.first && pa.second == pb.second;
    }
    inline static double calcSize2A(int abhight, pair<int, int> &pa, pair<int, int> &pb, pair<int, int> &pc) {
        double width = (pa.first-pb.first) * (pc.second-pb.second) / (double) (pa.second-pb.second);
        return abhight * width;
    }
    inline static double calcSize2B(int abwidth, pair<int, int> &pa, pair<int, int> &pb, pair<int, int> &pc) {
        double hight = (pa.second-pb.second) * (pc.first-pb.first) / (double) (pa.first-pb.first);
        return hight * abwidth;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        vector<pair<int, int>> pointPairsA;
        vector<pair<int, int>> pointPairsB;
        for(auto &point : points) {
            pointPairsA.emplace_back(point[0], point[1]);
            pointPairsB.emplace_back(point[0], point[1]);
        }
        sort(pointPairsA.begin(), pointPairsA.end(), [](pair<int, int> &pa, pair<int, int> &pb) {
            return pa.first < pb.first;
        });
        sort(pointPairsB.begin(), pointPairsB.end(), [](pair<int, int> &pa, pair<int, int> &pb) {
            return pa.second < pb.second;
        });

        int lastIndex = points.size()-1;

        double maxSize = 0;
        if(equals(pointPairsA[0], pointPairsB[0])) {
            if(equals(pointPairsA[lastIndex], pointPairsB[lastIndex])) {
                for(int i = 1; i < lastIndex; i++) {
                    int abhight = 
                }
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> points = {{0,0},{0,1},{1,0},{0,2},{2,0}};
        cout << Solution().largestTriangleArea(points) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     vector<vector<int>> grid = {
    //         {1,0,1},
    //         {1,1,1},
    //         {0,0,1},
    //     };
    //     cout << Solution().largestTriangleArea(points) << endl;
    // }
    return 0;
}
#endif