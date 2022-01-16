#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<bool> canEat0(vector<int> &candiesCount, vector<vector<int>> &queries) {
        vector<bool> ret;
        ret.reserve(queries.size());
        vector<long> sumCount;
        sumCount.reserve(candiesCount.size());

        long sum = 0;
        for(auto &count : candiesCount) {
            sumCount.emplace_back(sum);
            sum += count;
        }

        for(auto &query : queries) {
            auto &favoriteType = query[0];
            auto &favoriteDay  = query[1];
            long  dailyCap     = query[2];

            ret.emplace_back(sumCount[favoriteType] + candiesCount[favoriteType] > favoriteDay &&
                             (favoriteDay + 1) * dailyCap > sumCount[favoriteType]);
        }
        return ret;
    }
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        vector<bool> ret;
        ret.reserve(queries.size());
        vector<long> sumCount;
        sumCount.reserve(candiesCount.size() + 1);

        long sum = 0;
        for(auto &count : candiesCount) {
            sumCount.emplace_back(sum);
            sum += count;
        }
        sumCount.emplace_back(sum);

        for(auto &query : queries) {
            auto &favoriteType = query[0];
            long  favoriteDay  = query[1];
            auto &dailyCap     = query[2];

            ret.emplace_back((favoriteDay + 1) * dailyCap > sumCount[favoriteType] &&
                             sumCount[favoriteType + 1] > favoriteDay);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    // cout << " 1:" << endl;
    // {
    //     vector<int>         candiesCount = {7, 4, 5, 3, 8};
    //     vector<vector<int>> queries      = {{0, 2, 2}, {4, 2, 4}, {2, 13, 1000000000}};
    //     cout << Solution().canEat(candiesCount, queries) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int>         candiesCount = {5, 2, 6, 4, 1};
    //     vector<vector<int>> queries      = {{3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}};
    //     cout << Solution().canEat(candiesCount, queries) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> candiesCount    = {46, 5,  47, 48, 43, 34, 15, 26, 11, 25, 41, 47, 15, 25, 16, 50, 32, 42, 32,
    //     21,
    //                                 36, 34, 50, 45, 46, 15, 46, 38, 50, 12, 3,  26, 26, 16, 23, 1,  4,  48, 47, 32,
    //                                 47, 16, 33, 23, 38, 2,  19, 50, 6,  19, 29, 3,  27, 12, 6,  22, 33, 28, 7,  10,
    //                                 12, 8,  13, 24, 21, 38, 43, 26, 35, 18, 34, 3,  14, 48, 50, 34, 38, 4,  50, 26,
    //                                 5,  35, 11, 2,  35, 9,  11, 31, 36, 20, 21, 37, 18, 34, 34, 10, 21, 8,  5};
    //     vector<vector<int>> queries = {
    //         {80, 2329, 69}, {14, 1485, 76}, {33, 2057, 83}, {13, 1972, 27}, {11, 387, 25},  {24, 1460, 47},
    //         {22, 1783, 35}, {1, 513, 33},   {66, 2124, 85}, {19, 642, 26},  {15, 1963, 79}, {93, 722, 96},
    //         {15, 376, 88},  {60, 1864, 89}, {86, 608, 4},   {98, 257, 35},  {35, 651, 47},  {96, 795, 73},
    //         {62, 2077, 18}, {27, 1724, 57}, {34, 1984, 75}, {49, 2413, 95}, {76, 1664, 5},  {28, 38, 13},
    //         {85, 54, 42},   {12, 301, 3},   {62, 2016, 29}, {45, 2316, 37}, {43, 2360, 28}, {87, 192, 98},
    //         {27, 2082, 21}, {74, 762, 37},  {51, 35, 17},   {73, 2193, 4},  {60, 425, 65},  {11, 1522, 58},
    //         {21, 1699, 66}, {42, 1473, 5},  {30, 2010, 48}, {91, 796, 74},  {82, 2162, 31}, {23, 2569, 65},
    //         {24, 684, 23},  {70, 1219, 51}, {5, 1817, 15},  {81, 2446, 34}, {96, 771, 60},  {49, 1171, 60},
    //         {41, 567, 67},  {39, 799, 59},  {90, 957, 81},  {84, 2122, 27}, {82, 1707, 44}, {11, 1889, 20},
    //         {80, 1697, 83}, {24, 1786, 60}, {90, 1847, 99}, {51, 114, 21},  {44, 466, 85},  {56, 469, 20},
    //         {44, 350, 96},  {66, 1946, 10}, {14, 2470, 12}, {69, 1175, 18}, {98, 1804, 25}, {77, 2187, 40},
    //         {89, 2265, 45}, {19, 2246, 45}, {40, 2373, 79}, {60, 2222, 17}, {37, 385, 5},   {97, 1759, 97},
    //         {10, 903, 5},   {87, 842, 45},  {74, 2398, 66}, {62, 49, 94},   {48, 156, 77},  {76, 2310, 80},
    //         {64, 2360, 95}, {70, 1699, 83}, {39, 1241, 66}, {92, 2312, 21}, {63, 2148, 29}, {95, 594, 74},
    //         {89, 90, 51},   {82, 137, 70},  {54, 301, 97},  {15, 819, 43},  {47, 1402, 60}, {17, 2377, 43},
    //         {50, 1937, 95}, {62, 1174, 74}, {67, 1411, 87}, {39, 1151, 48}};
    //     cout << Solution().canEat(candiesCount, queries) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int>         candiesCount = {16, 38, 8,  41, 30, 31, 14, 45, 3,  2,  24, 23, 38, 30, 31, 17, 35, 4, 9,
    //                                 42, 28, 18, 37, 18, 14, 46, 11, 13, 19, 3,  5,  39, 24, 48, 20, 29, 4,  19,
    //                                 36, 11, 28, 49, 38, 16, 23, 24, 4,  22, 29, 35, 45, 38, 37, 40, 2,  37, 8,
    //                                 41, 33, 8,  40, 27, 13, 4,  33, 5,  8,  14, 19, 35, 31, 8,  8};
    //     vector<vector<int>> queries      = {{40, 1083, 86}, {43, 1054, 49}, {48, 690, 92}};
    //     cout << Solution().canEat(candiesCount, queries) << endl;
    // }
    cout << " 5:" << endl;
    {
        vector<int>         candiesCount = {7, 11, 5, 3, 8};
        vector<vector<int>> queries      = {{2, 2, 6}};
        cout << Solution().canEat(candiesCount, queries) << endl;
    }
    return 0;
}
#endif