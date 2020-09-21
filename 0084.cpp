#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

#define S 3
#if S == 1
//遍历，以第i个为最大高度算面积，o(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        int rlt = 0;
        for(int i = 0; i < heights.size(); i++) {
            //i为最大高度
            if(i > 1 && heights[i] == heights[i-1])
                continue;
            int l = i-1, r = i+1;
            while(l >= 0 && heights[l] >= heights[i])
                l--;
            while(r < heights.size() && heights[r] >= heights[i])
                r++;
            if(heights[i]*(r-l-1) > rlt)
                rlt = heights[i]*(r-l-1);
        }
        return rlt;
    }
};
#elif S == 2
//遍历，仅当高度增高时算面积，o(n^2)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        int rlt = 0;
        for(int i = 0; i < heights.size(); i++) {
            if(i == 0 || heights[i] > heights[i-1]) {
                int h = heights[i], r = i+1;
                int hmin = i == 0 ? 0 : heights[i-1];
                for(; h > hmin; h = heights[r], r++) {
                    while(r < heights.size() && heights[r] >= h)
                        r++;
                    if(h*(r-i) > rlt)
                        rlt = h*(r-i);
                    if(r == heights.size())
                        break;
                }
            }
        }
        return rlt;
    }
};
#elif S == 3
//遍历，改进1,优化找最左最右，o(n)
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0)
            return 0;
        int rlt = 0;
        vector<int> toLeft(heights.size()), toRight(heights.size());
        toLeft[0] = 0;
        toRight[heights.size()-1] = heights.size()-1;
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] > heights[i-1])
                toLeft[i] = i;
            else if(heights[i] == heights[i-1])
                toLeft[i] = toLeft[i-1];
            else {
                int j;
                for(j = toLeft[i-1]; j >= 0 && heights[j] >= heights[i]; j--) {}
                toLeft[i] = j+1;
            }
        }
        for(int i = heights.size()-2; i >= 0; i--) {
            if(heights[i] > heights[i+1])
                toRight[i] = i;
            else if(heights[i] == heights[i+1])
                toRight[i] = toRight[i+1];
            else {
                int j;
                for(j = toRight[i+1]; j < heights.size() && heights[j] >= heights[i]; j++) {}
                toRight[i] = j-1;
            }
        }
        for(int i = 0; i < heights.size(); i++) {
            int tmp = (1+toRight[i]-toLeft[i])*heights[i];
            if(tmp > rlt)
                rlt = tmp;
        }
        return rlt;
    }
};
#endif

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<int> heights = {2,1,5,6,2,3};
        cout << Solution().largestRectangleArea(heights) << endl;
    }
    // cout << "2:" << endl;
    // {
    //     auto S = "aa", T = "aa";
    //     cout << Solution().minWindow(S, T) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     auto S = "ADOBECODEBANC", T = "ABC";
    //     cout << Solution().minWindow(S, T) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     auto S = "ADOBECODEBANC", T = "ABC";
    //     cout << Solution().minWindow(S, T) << endl;
    // }
    
    return 0;
}
#endif