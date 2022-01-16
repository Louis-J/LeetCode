#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> lmax(height.size(), 0), rmax(height.size(), 0);
        int sum = 0;
        for (int i = 0, maxH = 0; i < height.size(); i++) {
            if (height[i] > maxH) {
                maxH = height[i];
            }
            lmax[i] = maxH;
        }
        for (int i = height.size()-1, maxH = 0; i >= 0; i--) {
            if (height[i] > maxH) {
                maxH = height[i];
            }
            rmax[i] = maxH;
        }
        for (int i = 0; i < height.size(); i++) {
            sum += min(lmax[i], rmax[i]) - height[i];
        }
        return sum;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << Solution().trap(height) << endl;
    }
    cout << "2:" << endl;
    {
        vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
        cout << Solution().trap(height) << endl;
    }
    return 0;
}
#endif