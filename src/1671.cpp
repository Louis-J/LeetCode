#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        vector<tuple<int, int, int, int>> dp1(nums.size());
        vector<tuple<int, int, int, int>> dp2(nums.size());
        // auto dp1 = new pair<int, int>[nums.size()];
        // auto dp2 = new pair<int, int>[nums.size()];
        // <到此位置且包括此数所需最少删除次数，上一个比这个元素小的位置的下标，到此位置且大于等于此数所需最少删除次数，上一个比这个元素大的位置的下标>

        dp1[0] = {0, -1, 0, -1};
        for(int i = 1; i < nums.size() - 1; i++) {
            for(int j = i - 1;; j = get<1>(dp1[j])) {
                if(j == -1) {
                    get<0>(dp1[i]) = i;
                    get<1>(dp1[i]) = -1;
                    break;
                } else if(nums[j] < nums[i]) {
                    get<0>(dp1[i]) = i - 1 - j + get<0>(dp1[j]);
                    get<1>(dp1[i]) = j;
                    break;
                }
            }
            if(nums[i - 1] >= nums[i]) {
                get<2>(dp1[i]) = get<2>(dp1[i - 1]) + 1;
                get<3>(dp1[i]) = i - 1;
            } else if(get<2>(dp1[i - 1]) + 1 <) {
                get<2>(dp1[i]) = get<2>(dp1[i - 1]) + 1;
                get<3>(dp1[i]) = i - 1;
            }
        }

        dp2[nums.size() - 1] = {0, -1};
        for(int i = nums.size() - 2; i > 0; i--) {
            for(int j = i + 1;; j = get<2>(dp2[j])) {
                if(j == -1) {
                    get<1>(dp2[i]) = nums.size() - 1 - i;
                    get<2>(dp2[i]) = -1;
                    get<0>(dp2[i]) = min(get<1>(dp2[i]), get<0>(dp2[i + 1]));
                    break;
                } else if(nums[j] < nums[i]) {
                    get<1>(dp2[i]) = j - i - 1 + get<1>(dp2[j]);
                    get<2>(dp2[i]) = j;
                    get<0>(dp2[i]) = min(get<1>(dp2[i]), get<0>(dp2[i + 1]));
                    break;
                }
            }
        }

        int minNum = nums.size() - 1;
        for(int i = 0; i < nums.size(); i++) {
            minNum = min(minNum, dp1[i].first + dp2[i].first);
        }
        cout << endl;
        cout << dp1 << endl;
        cout << dp2 << endl;
        cout << endl;

        return minNum;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {1, 3, 1};
    //     cout << Solution().minimumMountainRemovals(nums) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {2, 1, 1, 5, 6, 2, 3, 1};
    //     cout << Solution().minimumMountainRemovals(nums) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums = {4, 3, 2, 1, 1, 2, 3, 1};
    //     cout << Solution().minimumMountainRemovals(nums) << endl;
    // }
    cout << " 4:" << endl;
    {
        vector<int> nums = {23, 47, 63, 72, 81, 99, 88, 55, 21, 33, 32};
        cout << Solution().minimumMountainRemovals(nums) << endl;
    }
    return 0;
}
#endif