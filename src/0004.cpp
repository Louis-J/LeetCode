#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> *L, *S;
        if(nums1.size() > nums2.size()){
            L = &nums1;
            S = &nums2;
        }
        else{
            S = &nums1;
            L = &nums2;
        }

        const unsigned int lenSum = nums1.size() + nums2.size();
        const unsigned int lenHalf = (lenSum + 1)/2;
        unsigned int iMin = 0, iMax = S -> size();

        while (iMin <= iMax) {
            unsigned int i = (iMin + iMax) / 2;
            unsigned int j = lenHalf - i;

            if(i < iMax && (*L)[j - 1] > (*S)[i]){
                iMin = i + 1;
            }
            else if(i > 0 && (*S)[i - 1] > (*L)[j]){
                iMax = i;
            }
            else{
                if(lenSum % 2 == 1){
                    if(i == 0){
                        return (*L)[j-1];
                    }
                    else if(j == 0){
                        return (*S)[i-1];
                    }
                    else{
                        return max((*S)[i-1] , (*L)[j-1]);
                    }
                }
                else{
                    int maxLeft, minRight;
                    if(i == 0){
                        maxLeft = (*L)[j-1];
                    }
                    else if(j == 0){
                        maxLeft = (*S)[i-1];
                    }
                    else{
                        maxLeft = max((*S)[i-1] , (*L)[j-1]);
                    }
                    if(i == S -> size()){
                        minRight = (*L)[j];
                    }
                    else if(j == L -> size()){
                        minRight = (*S)[i];
                    }
                    else{
                        minRight = min((*S)[i] , (*L)[j]);
                    }
                    return (maxLeft + minRight)/2.0;
                }
            }
        }
        return 0;
    }
    // static double fmsa(int *n1, int n1l, int *n2, int n2l) {
    //     if((n1l + n2l)%2 == 1) {
            
    //     }
    //     int i1 = 
    // }
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    //     return fmsa(&nums1[0], nums1.size(), &nums2[0], nums2.size());
    // }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums1 = {1, 3};
        vector<int> nums2 = {2};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums1 = {1, 2};
        vector<int> nums2 = {3, 4};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums1 = {0, 0};
        vector<int> nums2 = {0, 0};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums1 = {};
        vector<int> nums2 = {1};
        cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    }
    return 0;
}
#endif