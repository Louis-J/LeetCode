#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int minSwap0(vector<int> &nums1, vector<int> &nums2) {
        vector<pair<int, int>> dp(nums1.size());
        dp[0].second = 1;

        for(int i = 1; i < dp.size(); i++) {
            int r1 = 100000, r2 = 100000;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                r1 = min(r1, dp[i - 1].first);
                r2 = min(r2, dp[i - 1].second + 1);
            }
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                r1 = min(r1, dp[i - 1].second);
                r2 = min(r2, dp[i - 1].first + 1);
            }
            dp[i].first  = r1;
            dp[i].second = r2;
        }
        auto &last = dp[dp.size() - 1];
        return min(last.first, last.second);
    }
    int minSwap1(vector<int> &nums1, vector<int> &nums2) {
        pair<int, int> last(0, 1);

        for(int i = 1; i < nums1.size(); i++) {
            int r1 = 100000, r2 = 100000;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                r1 = min(r1, last.first);
                r2 = min(r2, last.second + 1);
            }
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                r1 = min(r1, last.second);
                r2 = min(r2, last.first + 1);
            }
            last.first  = r1;
            last.second = r2;
        }
        return min(last.first, last.second);
    }
    int minSwap(vector<int> &nums1, vector<int> &nums2) {
        pair<int, int> last(0, 1);

        for(int i = 1; i < nums1.size(); i++) {
            int r1, r2;
            if(nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
                r1 = last.first;
                r2 = last.second + 1;
            } else {
                r1 = 100000;
                r2 = 100000;
            }
            if(nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
                r1 = min(r1, last.second);
                r2 = min(r2, last.first + 1);
            }
            last.first  = r1;
            last.second = r2;
        }
        return min(last.first, last.second);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> A = {1, 3, 5, 4};
        vector<int> B = {1, 2, 3, 7};
        cout << Solution().minSwap(A, B) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> A = {0, 3, 5, 8, 9};
        vector<int> B = {2, 1, 4, 6, 9};
        cout << Solution().minSwap(A, B) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> A = {3, 3, 8, 9, 10};
        vector<int> B = {1, 7, 4, 6, 8};
        cout << Solution().minSwap(A, B) << endl;
    }
    return 0;
}
#endif