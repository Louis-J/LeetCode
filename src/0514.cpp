#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int steps[26][26] = {};
        for(int i = 0; i < ring.size(); i++)
            for(int j = i+1; j < ring.size(); j++)
                if(ring[i] != ring[j] && steps[ring[i]-'a'][ring[j]-'a'] == 0 || steps[ring[i]-'a'][ring[j]-'a'] > j-i) {
                    steps[ring[i]-'a'][ring[j]-'a'] = j-i;
                    steps[ring[j]-'a'][ring[i]-'a'] = j-i;
                }
        int ret = 0;
        int start = ring[0]-'a';
        for(auto &c : key) {
            ret += steps[start][c-'a'];
            start = c-'a';
        }
        return ret+key.size();
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     cout << Solution().findRotateSteps("godding", "gd") << endl;
    // }
    cout << " 2:" << endl;
    {
        cout << Solution().findRotateSteps("godding", "di") << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {2, 4, 3, 5, 1};
    //     cout << Solution().reversePairs(nums) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums = {-5, -5};
    //     cout << Solution().reversePairs(nums) << endl;
    // }
    return 0;
}
#endif