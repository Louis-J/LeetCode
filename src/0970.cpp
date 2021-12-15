#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(x == 1 && y == 1) {
            if(bound >= 2)
                return {2};
            else
                return {};
        } else if(x == 1) {
            vector<int> retList;
            for(int temp = 1; temp < bound; temp *= y) retList.emplace_back(temp + 1);
            return retList;
        } else if(y == 1) {
            vector<int> retList;
            for(int temp = 1; temp < bound; temp *= x) retList.emplace_back(temp + 1);
            return retList;
        } else {
            vector<int> xs;
            vector<int> ys;
            for(int temp = 1; temp < bound; temp *= x) xs.emplace_back(temp);
            for(int temp = 1; temp < bound; temp *= y) ys.emplace_back(temp);

            unordered_set<int> retSet;
            for(auto &theX : xs) {
                for(auto &theY : ys) {
                    if(theX + theY <= bound)
                        retSet.emplace(theX + theY);
                    else
                        break;
                }
            }
            vector<int> retList;
            for(auto &&i : retSet) retList.emplace_back(i);
            return retList;
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        int x     = 2;
        int y     = 3;
        int bound = 10;
        cout << Solution().powerfulIntegers(x, y, bound) << endl;
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