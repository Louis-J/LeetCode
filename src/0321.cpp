#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() > k) {
            vector<int> newnums;
            for(int i = 0, startj = 0; i < k; i++) {
                size_t maxj = startj;
                for(int j = startj+1; j <= nums1.size()+i-k; j++) {
                    if(nums1[j] > nums1[maxj])
                        maxj = j;
                }
                if(maxj == nums1.size()+i-k) {
                    newnums.insert(newnums.end(), nums1.begin()+maxj, nums1.end());
                    break;
                } else {
                    newnums.emplace_back(nums1[maxj]);
                    startj = maxj+1;
                }
            }
            swap(nums1, newnums);
        }
        if(nums2.size() > k) {
            vector<int> newnums;
            for(int i = 0, startj = 0; i < k; i++) {
                size_t maxj = startj;
                for(int j = startj+1; j <= nums2.size()+i-k; j++) {
                    if(nums2[j] > nums2[maxj])
                        maxj = j;
                }
                if(maxj == nums2.size()+i-k) {
                    newnums.insert(newnums.end(), nums2.begin()+maxj, nums2.end());
                    break;
                } else {
                    newnums.emplace_back(nums2[maxj]);
                    startj = maxj+1;
                }
            }
            swap(nums2, newnums);
        }

        // list<pair<int, bool>> l;
        // for(auto &i : nums1) {
        //     l.emplace_back(i, false);
        // }
        list<int> l(nums1.begin(), nums1.end());

        size_t n2startj = 0;
        auto n2startjt = l.begin();
        for(size_t i = 0; i < nums2.size(); i++) {
            size_t j = n2startj;
            auto jt = n2startjt;
            for(; jt != l.end() && j < k && *jt >= i; jt++, j++) {}
            if(j != k) {
                if(jt == l.end()) {
                    
                }
            }
                continue;
        }

    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums1 = {3, 4, 6, 5};
        vector<int> nums2 = {9, 1, 2, 5, 8, 3};
        int k = 5;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums1 = {6, 7};
        vector<int> nums2 = {6, 0, 4};
        int k = 5;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums1 = {3, 8};
        vector<int> nums2 = {3, 9};
        int k = 3;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    return 0;
}
#endif