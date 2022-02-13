#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        vector<int> stk;
        vector<int> ret(temperatures.size());
        stk.emplace_back(temperatures.size()-1);
        ret.back() = 0;
        for(int i = temperatures.size() - 2; i >= 0; i--) {
            if(temperatures[i] < temperatures[stk.back()]) {
                ret[i] = stk.back() - i;
                stk.emplace_back(i);
            } else {
                while(true) {
                    stk.pop_back();
                    if(stk.size() == 0) {
                        ret[i] = 0;
                        break;
                    } else if(temperatures[i] < temperatures[stk.back()]) {
                        ret[i] = stk.back() - i;
                        break;
                    }
                }
                stk.emplace_back(i);
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(false);
    cout << "1:" << endl;
    {
        vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
        cout << Solution().dailyTemperatures(temperatures) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> temperatures = {30, 40, 50, 60};
        cout << Solution().dailyTemperatures(temperatures) << endl;
    }
    cout << "3:" << endl;
    {
        vector<int> temperatures = {30, 60, 90};
        cout << Solution().dailyTemperatures(temperatures) << endl;
    }
    return 0;
}
#endif
