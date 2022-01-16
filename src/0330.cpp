#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //注：可继续优化，如算logN复杂度前置0的个数,logN复杂度算需要除以的2的指数次方
    int minPatches(vector<int>& nums, int n) {
        int ret = 0;
        if(nums.size() == 0) {
            for(; n > 0; n/=2)
                ret++;
            return ret;
        }
        int sum = 0;
        for(auto it = nums.begin(); it != nums.end() && sum < n;) {
            if(*it <= sum+1) {
                sum += *it;
                it++;
            } else {
                sum += sum+1;
                ret++;
            }
        }
        for(; n > sum; n/=2)
            ret++;
        return ret;
    }
};

#ifdef LEETCODE
int getj(int sum) {
    int j;
    for(j = 1; j <= sum+1; j *= 2) {}
    return j/2;
}
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {1, 3};
    //     int n = 6;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {1, 5, 10};
    //     int n = 20;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums = {1, 2, 2};
    //     int n = 4;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {};
    //     int n = 7;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> nums = {};
    //     int n = 8;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 6:" << endl;
    // {
    //     vector<int> nums = {1, 2, 31 ,33};
    //     int n = 217483647;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 7:" << endl;
    // {
    //     vector<int> nums = {1, 7, 21, 31, 34, 37, 40, 43, 49, 87, 90, 92, 93, 98, 99};
    //     int n = 12;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    // cout << " 8:" << endl;
    // {
    //     vector<int> nums = {1,1,7,8,9,9,10,12,13,13,15,17,17,17,18,18,18,20,21,24,25,26,26,28,28,29,31,34,35,35,39,41,43,44,44,45,46,46,47,49,50,50,51,52,54,55,58,60,63,64,65,67,67,69,69,69,70,70,70,75,76,77,77,78,79,82,83,90,91,95,97};
    //     int n = 65;
    //     cout << Solution().minPatches(nums, n) << endl;
    // }
    cout << " 9:" << endl;
    {
        vector<int> nums = {1,2,2,6,34,38,41,44,47,47,56,59,62,73,77,83,87,89,94};
        int n = 20;
        cout << Solution().minPatches(nums, n) << endl;
    }
    return 0;
}
#endif