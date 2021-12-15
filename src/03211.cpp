#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int b1 = 0, b2 = 0;
        int e1, e2;
        vector<int> ret;
        for(int i = 0; i < k; i++) {
            int len = nums1.size() - b1 + nums2.size() - b2 - (k-i);
            if(len == 0) {
                if(b1 == nums1.size()) {
                    ret.insert(ret.end(), nums2.begin()+b2, nums2.end());
                    break;
                } else if(b2 == nums2.size()) {
                    ret.insert(ret.end(), nums1.begin()+b1, nums1.end());
                    break;
                } else {
                    if(nums1[b1] == nums2[b2]) {
                        ret.emplace_back(nums1[b1]);
                        int mid = -1;
                        for(int j = 1;; j++) {
                            if(b1+j == nums1.size() && b2+j == nums2.size()) {
                                ret.insert(ret.end(), nums1.begin()+b1, nums1.end());
                                ret.insert(ret.end(), nums1.begin()+b1, nums1.end());
                                i = k;
                                break;
                            } else if(b1+j == nums1.size()) {
                                b2 += j;
                                i += j-1;
                                break;
                            } else if(b2+j == nums2.size()) {
                                b1 += j;
                                i += j-1;
                                break;
                            } else if(nums1[b1+j] == nums2[b2+j]) {
                                if(nums1[b1+j] < nums[b1]) {
                                    ret.insert(ret.end(), nums1.begin()+b1, nums1.begin()+b1+j);
                                    ret.insert(ret.end(), nums1.begin()+b1, nums1.begin()+b1+j);
                                    b1 = b1 + j;
                                    b2 = b2 + j;
                                    i += j+j-1;
                                    j = 1;
                                    mid = -1;
                                    continue;
                                }
                                if(nums1[b1+j] < nums1[b1+j-1]) {
                                }
                                ret.emplace_back(nums1[b1+j]);
                            } else if(nums1[b1+j] > nums2[b2+j]) {
                                b1 += j;
                                i += j-1;
                                break;
                            } else {
                                b2 += j;
                                i += j-1;
                                break;
                            }
                        }
                    } else if(nums1[b1] > nums2[b2])
                        ret.emplace_back(nums1[b1++]);
                    else
                        ret.emplace_back(nums2[b2++]);
                }
            } else {
                if(b1 == nums1.size()) {
                    e2 = b2 + len;
                    size_t maxj = b2;
                    for(int j = b2+1; j <= e2; j++) {
                        if(nums2[j] > nums2[maxj])
                            maxj = j;
                    }
                    if(maxj == e2) {
                        ret.insert(ret.end(), nums2.begin()+maxj, nums2.end());
                        break;
                    } else {
                        ret.emplace_back(nums2[maxj]);
                        b2 = maxj+1;
                    }
                } else if(b2 == nums2.size()) {
                    e1 = b1 + len;
                    size_t maxj = b1;
                    for(int j = b1+1; j <= e1; j++) {
                        if(nums1[j] > nums1[maxj])
                            maxj = j;
                    }
                    if(maxj == e1) {
                        ret.insert(ret.end(), nums1.begin()+maxj, nums1.end());
                        break;
                    } else {
                        ret.emplace_back(nums1[maxj]);
                        b1 = maxj+1;
                    }
                } else {
                    if(nums2.size() - b2 > len)
                        e1 = nums1.size()-1;
                    else if(b1+len < nums1.size())
                        e1 = b1+len;
                    else
                        e1 = nums1.size()-1;
                    if(nums1.size() - b1 > len)
                        e2 = nums2.size()-1;
                    else if(b2+len < nums2.size())
                        e2 = b2+len;
                    else
                        e2 = nums2.size()-1;

                    size_t maxj1 = b1;
                    for(int j = b1+1; j <= e1; j++) {
                        if(nums1[j] > nums1[maxj1])
                            maxj1 = j;
                    }
                    size_t maxj2 = b2;
                    for(int j = b2+1; j <= e2; j++) {
                        if(nums2[j] > nums2[maxj2])
                            maxj2 = j;
                    }
                    if(nums1[maxj1] > nums2[maxj2] || 
                        (nums1[maxj1] == nums2[maxj2] &&
                            (len%2 == 0 || b1 == maxj1 || (b2 != maxj2 && nums1[maxj1-1] < nums2[maxj2-1])))) {
                        ret.emplace_back(nums1[maxj1]);
                        b1 = maxj1+1;
                        if(maxj1 == nums1.size() && maxj2 == nums2.size()+i-k) {
                            ret.insert(ret.end(), nums2.begin()+maxj2, nums2.end());
                            break;
                        }
                    } else {
                        ret.emplace_back(nums2[maxj2]);
                        b2 = maxj2+1;
                        if(maxj2 == nums2.size() && maxj1 == nums1.size()+i-k) {
                            ret.insert(ret.end(), nums1.begin()+maxj1, nums1.end());
                            break;
                        }
                    }
                }
            }
        }
        return ret;
    }
    // vector<int> maxNumber00(vector<int>& nums1, vector<int>& nums2, int k) {
    //     if(nums1.size() > k) {
    //         vector<int> newnums;
    //         for(int i = 0, startj = 0; i < k; i++) {
    //             size_t maxj = startj;
    //             for(int j = startj+1; j <= nums1.size()+i-k; j++) {
    //                 if(nums1[j] > nums1[maxj])
    //                     maxj = j;
    //             }
    //             if(maxj == nums1.size()+i-k) {
    //                 newnums.insert(newnums.end(), nums1.begin()+maxj, nums1.end());
    //                 break;
    //             } else {
    //                 newnums.emplace_back(nums1[maxj]);
    //                 startj = maxj+1;
    //             }
    //         }
    //         swap(nums1, newnums);
    //     }
    //     if(nums2.size() > k) {
    //         vector<int> newnums;
    //         for(int i = 0, startj = 0; i < k; i++) {
    //             size_t maxj = startj;
    //             for(int j = startj+1; j <= nums2.size()+i-k; j++) {
    //                 if(nums2[j] > nums2[maxj])
    //                     maxj = j;
    //             }
    //             if(maxj == nums2.size()+i-k) {
    //                 newnums.insert(newnums.end(), nums2.begin()+maxj, nums2.end());
    //                 break;
    //             } else {
    //                 newnums.emplace_back(nums2[maxj]);
    //                 startj = maxj+1;
    //             }
    //         }
    //         swap(nums2, newnums);
    //     }

    //     // list<pair<int, bool>> l;
    //     // for(auto &i : nums1) {
    //     //     l.emplace_back(i, false);
    //     // }
    //     list<int> l(nums1.begin(), nums1.end());

    //     size_t n2startj = 0;
    //     auto n2startjt = l.begin();
    //     for(size_t i = 0; i < nums2.size(); i++) {
    //         size_t j = n2startj;
    //         auto jt = n2startjt;
    //         for(; jt != l.end() && j < k && *jt >= i; jt++, j++) {}
    //         if(j != k) {
    //             if(jt == l.end()) {
                    
    //             }
    //         }
    //             continue;
    //     }
    // }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums1 = {3, 4, 6, 5};
    //     vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    //     int k = 5;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums1 = {6, 7};
    //     vector<int> nums2 = {6, 0, 4};
    //     int k = 5;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums1 = {8, 9};
    //     vector<int> nums2 = {3, 9};
    //     int k = 3;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums1 = {3, 9};
    //     vector<int> nums2 = {8, 9};
    //     int k = 3;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> nums1 = {8, 6, 9};
    //     vector<int> nums2 = {1, 7, 5};
    //     int k = 3;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 6:" << endl;
    // {
    //     vector<int> nums1 = {6, 7, 5};
    //     vector<int> nums2 = {4, 8, 1};
    //     int k = 3;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 7:" << endl;
    // {
    //     vector<int> nums1 = {6, 6, 8};
    //     vector<int> nums2 = {5, 0, 9};
    //     int k = 3;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 8:" << endl;
    // {
    //     vector<int> nums1 = {3, 8, 5, 3, 4};
    //     vector<int> nums2 = {8, 7, 3, 6, 8};
    //     int k = 5;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    // cout << " 9:" << endl;
    // {
    //     //7,6,7,5,1,0,2,1,0,1,0,5,6,0,5,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3,0
    //     vector<int> nums1 = {5,0,2,1,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3};
    //     vector<int> nums2 = {7,6,7,1,0,1,0,5,6,0,5,0};
    //     int k = 31;
    //     cout << Solution().maxNumber(nums1, nums2, k) << endl;
    // }
    cout << " 10:" << endl;
    {
        //8,8,6,6,5,4,6,3,7,5,6,4,5,6,4,0
        vector<int> nums1 = {6, 5, 4, 6, 3, 7, 5, 6, 4, 5, 6, 4};
        vector<int> nums2 = {8, 8, 6, 0};
        int k = 16;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    return 0;
}
#endif