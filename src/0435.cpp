#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif
static auto __sync__ = []() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();

class Solution {
public:
    int eraseOverlapIntervals0(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            // if(a[1] == b[1])
            //     return a[0] < b[0];
            return a[1] < b[1];
        });

        int ret = 0;
        int e = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] >= e)
                e = intervals[i][1];
            else
                ret++;
        }
        return ret;
    }
    int eraseOverlapIntervals(const vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return 0;
        vector<pair<int, int>> ivs;
        ivs.reserve(intervals.size());
        for(auto &i: intervals)
            ivs.emplace_back(i[0], i[1]);

        sort(ivs.begin(), ivs.end(), [](pair<int, int> &a, pair<int, int> &b){
            return a.second < b.second;
        });

        int ret = 0;
        int e = ivs[0].second;
        for(int i = 1; i < intervals.size(); i++) {
            if(ivs[i].first >= e)
                e = ivs[i].second;
            else
                ret++;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<vector<int>> intervals = {{1,2},{2,3},{3,4},{1,3}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<int>> intervals = {{1,2},{1,2},{1,2}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<vector<int>> intervals = {{1,2},{2,3}};
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<vector<int>> intervals = {
            {-100,-87},
            {-99,-44},
            {-98,-19},
            {-97,-33},
            {-96,-60},
            {-95,-17},
            {-94,-44},
            {-93,-9},
            {-92,-63},
            {-91,-76},
            {-90,-44},
            {-89,-18},
            {-88,10},
            {-87,-39},
            {-86,7},
            {-85,-76},
            {-84,-51},
            {-83,-48},
            {-82,-36},
            {-81,-63},
            {-80,-71},
            {-79,-4},
            {-78,-63},
            {-77,-14},
            {-76,-10},
            {-75,-36},
            {-74,31},
            {-73,11},
            {-72,-50},
            {-71,-30},
            {-70,33},
            {-69,-37},
            {-68,-50},
            {-67,6},
            {-66,-50},
            {-65,-26},
            {-64,21},
            {-63,-8},
            {-62,23},
            {-61,-34},
            {-60,13},
            {-59,19},
            {-58,41},
            {-57,-15},
            {-56,35},
            {-55,-4},
            {-54,-20},
            {-53,44},
            {-52,48},
            {-51,12},
            {-50,-43},
            {-49,10},
            {-48,-34},
            {-47,3},
            {-46,28},
            {-45,51},
            {-44,-14},
            {-43,59},
            {-42,-6},
            {-41,-32},
            {-40,-12},
            {-39,33},
            {-38,17},
            {-37,-7},
            {-36,-29},
            {-35,24},
            {-34,49},
            {-33,-19},
            {-32,2},
            {-31,8},
            {-30,74},
            {-29,58},
            {-28,13},
            {-27,-8},
            {-26,45},
            {-25,-5},
            {-24,45},
            {-23,19},
            {-22,9},
            {-21,54},
            {-20,1},
            {-19,81},
            {-18,17},
            {-17,-10},
            {-16,7},
            {-15,86},
            {-14,-3},
            {-13,-3},
            {-12,45},
            {-11,93},
            {-10,84},
            {-9,20},
            {-8,3},
            {-7,81},
            {-6,52},
            {-5,67},
            {-4,18},
            {-3,40},
            {-2,42},
            {-1,49},
            {0,7},
            {1,104},
            {2,79},
            {3,37},
            {4,47},
            {5,69},
            {6,89},
            {7,110},
            {8,108},
            {9,19},
            {10,25},
            {11,48},
            {12,63},
            {13,94},
            {14,55},
            {15,119},
            {16,64},
            {17,122},
            {18,92},
            {19,37},
            {20,86},
            {21,84},
            {22,122},
            {23,37},
            {24,125},
            {25,99},
            {26,45},
            {27,63},
            {28,40},
            {29,97},
            {30,78},
            {31,102},
            {32,120},
            {33,91},
            {34,107},
            {35,62},
            {36,137},
            {37,55},
            {38,115},
            {39,46},
            {40,136},
            {41,78},
            {42,86},
            {43,106},
            {44,66},
            {45,141},
            {46,92},
            {47,132},
            {48,89},
            {49,61},
            {50,128},
            {51,155},
            {52,153},
            {53,78},
            {54,114},
            {55,84},
            {56,151},
            {57,123},
            {58,69},
            {59,91},
            {60,89},
            {61,73},
            {62,81},
            {63,139},
            {64,108},
            {65,165},
            {66,92},
            {67,117},
            {68,140},
            {69,109},
            {70,102},
            {71,171},
            {72,141},
            {73,117},
            {74,124},
            {75,171},
            {76,132},
            {77,142},
            {78,107},
            {79,132},
            {80,171},
            {81,104},
            {82,160},
            {83,128},
            {84,137},
            {85,176},
            {86,188},
            {87,178},
            {88,117},
            {89,115},
            {90,140},
            {91,165},
            {92,133},
            {93,114},
            {94,125},
            {95,135},
            {96,144},
            {97,114},
            {98,183},
            {99,157}
        };
        cout << Solution().eraseOverlapIntervals(intervals) << endl;
    }
    return 0;
}
#endif