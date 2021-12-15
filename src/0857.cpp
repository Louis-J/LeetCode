#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    double mincostToHireWorkers(vector<int> &quality, vector<int> &wage, int k) {
        int                   len = quality.size();
        vector<tuple<int, double>> bili;
        for(size_t i = 0; i < len; i++) {
            bili.emplace(wage[i]/quality[i]);
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> quality = {7, 4};
        vector<int> wage    = {5, 2, 8, 9};
        int         k;
        cout << Solution().mincostToHireWorkers(quality, wage, k) << endl;
    }
    // cout << " 2:" << endl;
    // {
    // }
    // cout << " 3:" << endl;
    // {
    // }
    // cout << " 4:" << endl;
    // {
    // }
    return 0;
}
#endif