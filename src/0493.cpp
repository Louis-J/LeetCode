#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //超时，几乎是O(n^2)
    int reversePairs0(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        map<long long, int> amap{{nums[nums.size()-1], 1}};
        int sum = 0;
        for(auto it = nums.rbegin()+1; it != nums.rend(); it++) {
            auto jt = amap.begin();
            for(; jt != amap.end() && jt->first*2 < *it; jt++) {
                sum += jt->second;
            }
            jt = amap.find(*it);
            if(jt == amap.end())
                amap.emplace(*it, 1);
            else
                jt->second++;
        }
        return sum;
    }
private:
    //归并排序的方法、O(nlogn)
    static inline int guibing0(vector<int>& nums, int b, int e) {
        if(e-b <= 1) {
            if(e-b == 1) {
                if(nums[b] >= nums[e]) {
                    swap(nums[b], nums[e]);
                    if(nums[e] > (long long)(nums[b])*2)
                        return 1;
                }
                if(nums[b] > (long long)(nums[e])*2)
                    return 1;
            }
            return 0;
        } else {
            int ret = 0;
            ret += guibing0(nums, b, (b+e)/2);
            ret += guibing0(nums, (b+e)/2+1, e);

            for(int i = (b+e)/2, j = e; i >= b; i--) {
                for(; j >= (b+e)/2+1 && nums[i] <= (long long)(nums[j])*2; j--) {}
                if(j == (b+e)/2)
                    break;
                ret += j - ((b+e)/2+1)+1;
            }
            //合并
            vector<int> tmp1(&nums[(b+e)/2+1], &nums[e+1]);
            int i = e, j = (b+e)/2, k = tmp1.size()-1;
            while(j >= b && k >= 0) {
                if(nums[j] > tmp1[k]) {
                    nums[i] = nums[j];
                    i--;
                    j--;
                } else {
                    nums[i] = tmp1[k];
                    i--;
                    k--;
                }
            }
            while(k >= 0) {
                nums[i] = tmp1[k];
                i--;
                k--;
            }
            return ret;
        }
    }
    //tmp1改用栈数组而非vector，避免堆分配和堆回收，提高100多ms
    static inline int guibing1(vector<int>& nums, int b, int e) {
        if(e-b <= 1) {
            if(e-b == 1) {
                if(nums[b] >= nums[e]) {
                    swap(nums[b], nums[e]);
                    if(nums[e] > (long long)(nums[b])*2)
                        return 1;
                }
                if(nums[b] > (long long)(nums[e])*2)
                    return 1;
            }
            return 0;
        } else {
            int ret = 0;
            int midS = (b+e)/2+1;
            ret += guibing1(nums, b, (b+e)/2);
            ret += guibing1(nums, midS, e);

            for(int i = (b+e)/2, j = e; i >= b; i--) {
                for(; j >= midS && nums[i] <= (long long)(nums[j])*2; j--) {}
                if(j == (b+e)/2)
                    break;
                ret += j - (midS)+1;
            }
            //合并
            // vector<int> tmp1(&nums[midS], &nums[e+1]);
            int tmp1[e+1-midS];
            for(int i = 0; i < e+1-midS; i++)
                tmp1[i] = nums[i+midS];
            int i = e, j = (b+e)/2, k = e-midS;
            while(j >= b && k >= 0) {
                if(nums[j] > tmp1[k]) {
                    nums[i] = nums[j];
                    i--;
                    j--;
                } else {
                    nums[i] = tmp1[k];
                    i--;
                    k--;
                }
            }
            while(k >= 0) {
                nums[i] = tmp1[k];
                i--;
                k--;
            }
            return ret;
        }
    }
public:
    int reversePairs1(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        return guibing0(nums, 0, nums.size()-1);
    }
    int reversePairs(vector<int>& nums) {
        if(nums.size() <= 1)
            return 0;
        return guibing1(nums, 0, nums.size()-1);
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {1, 3, 2, 3, 1};
    //     cout << Solution().reversePairs(nums) << endl;
    // }
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