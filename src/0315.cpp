#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif
/*
2 5  1 6
0 1  0 1

1 5 2 6
0 1 1 1

1 2 5 6
0 1 2 1
*/
class Solution {
    static inline void guibing(vector<int>& nums, vector<int>& idxs, vector<int>& ret, int b, int e) {
        if(e-b <= 1) {
            if(e-b == 1) {
                if(nums[b] > nums[e]) {
                    ret[idxs[b]]++;
                    swap(nums[b], nums[e]);
                    swap(idxs[b], idxs[e]);
                }
            }
        } else {
            guibing(nums, idxs, ret, b, (b+e)/2);
            guibing(nums, idxs, ret, (b+e)/2+1, e);

            vector<int> tmp1(&nums[(b+e)/2+1], &nums[e+1]);
            vector<int> tmp2(&idxs[(b+e)/2+1], &idxs[e+1]);

            int i = e, j = (b+e)/2, k = tmp1.size()-1;
            while(j >= b && k >= 0) {
                if(nums[j] > tmp1[k]) {
                    ret[idxs[j]] += k+1;
                    nums[i] = nums[j];
                    idxs[i] = idxs[j];
                    i--;
                    j--;
                } else {
                    nums[i] = tmp1[k];
                    idxs[i] = tmp2[k];
                    i--;
                    k--;
                }
            }
            while(k >= 0) {
                nums[i] = tmp1[k];
                idxs[i] = tmp2[k];
                i--;
                k--;
            }
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> idxs(nums.size());
        int idn = 0;
        for(auto &i : idxs)
            i = idn++;
        vector<int> ret(nums.size(), 0);
        guibing(nums, idxs, ret, 0, nums.size()-1);
        return ret;
        // sort(idx.begin(), idx.end(), [&nums](size_t i1, size_t i2) {return nums[i1] > nums[i2];});
        // vector<int> ret(nums.size());
        // for(size_t i = 0; i < idx.size(); i++) {
        //     ret[i]
        // }
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {2, 4, 6, 8, 10};
    //     cout << Solution().countSmaller(nums) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {5, 2, 6, 1};
    //     cout << Solution().countSmaller(nums) << endl;
    // }
    cout << " 3:" << endl;
    {
        //[10,27,10,35,12,22,28,8,19,2,12,2,9,6,12,5,17,9,19,12,14,6,12,5,12,3,0,10,0,7,8,4,0,0,4,3,2,0,1,0]
        vector<int> nums = {26,78,27,100,33,67,90,23,66,5,38,7,35,23,52,22,83,51,98,69,81,32,78,28,94,13,2,97,3,76,99,51,9,21,84,66,65,36,100,41};
        cout << Solution().countSmaller(nums) << endl;
    }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {3, 2, 3, 1};
    //     cout << Solution().countSmaller(nums) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> nums = {3, 1, 2, 3};
    //     cout << Solution().countSmaller(nums) << endl;
    // }
    return 0;
}
#endif