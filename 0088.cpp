#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    void merge0(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        vector<int> tmp;
        tmp.reserve(m+n);
        size_t i = 0, j = 0;
        while(i < m && j < n) {
            if(nums1[i] <= nums2[j])
                tmp.emplace_back(nums1[i++]);
            else
                tmp.emplace_back(nums2[j++]);
        }
        if(i != m)
            while(i < m)
                tmp.emplace_back(nums1[i++]);
        else
            while(j < n)
                tmp.emplace_back(nums2[j++]);
        swap(tmp, nums1);
    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n == 0)
            return;
        size_t i = 0, j, k;
        for(j = m+n-1; j >= n; j--)
            nums1[j] = nums1[j-n];
            
        j = n, k = 0;
        while(j < m+n && k < n) {
            if(nums1[j] <= nums2[k])
                nums1[i++] = nums1[j++];
            else
                nums1[i++] = nums2[k++];
        }
        while(k != n)
            nums1[i++] = nums2[k++];
    }
};

#ifdef LEETCODE
int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    Solution().merge(nums1, 3, nums2, 2);
    cout << nums1 << endl;
    return 0;
}
#endif