#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<int> ret(rowIndex);
        ret[0] = 1;
        for(long long i = 1; i < rowIndex; i++) {
            ret[i] = ret[i-1]*(rowIndex-i)/i;
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    zhediePV = true;
    cout << " 1:" << endl;
    {
        cout << Solution().getRow(3) << endl;
        cout << Solution().getRow(5) << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().getRow(13) << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().getRow(20) << endl;
    }
    return 0;
}
#endif