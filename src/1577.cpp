#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
private:
    static int helper(vector<pair<int, int>> &nums1, vector<pair<int, int>> &nums2) {
        int sum = 0;
        for(auto &[n1, r1] : nums1) {
            int sumThis = 0;
            long n2      = (long)n1 * n1;
            int l = 0, r = nums2.size() - 1;
            while(l < r) {
                long lr = (long)(nums2[l].first) * nums2[r].first;
                if(lr == n2) {
                    sumThis += nums2[l].second * nums2[r].second;
                    l++;
                    r--;
                } else if(lr < n2) {
                    l++;
                } else {
                    r--;
                }
            }
            if(l == r && nums2[l].first == n1) {
                sumThis += nums2[l].second * (nums2[l].second - 1) / 2;
            }
            sum += sumThis * r1;
        }
        return sum;
    }

public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        map<int, int> numMap1;
        map<int, int> numMap2;
        for(int i = 0; i < nums1.size(); i++) {
            auto ret = numMap1.emplace(nums1[i], 1);
            if(!ret.second) ret.first->second++;
        }
        for(int i = 0; i < nums2.size(); i++) {
            auto ret = numMap2.emplace(nums2[i], 1);
            if(!ret.second) ret.first->second++;
        }

        vector<pair<int, int>> numPairs1;
        vector<pair<int, int>> numPairs2;
        for(auto &i : numMap1) numPairs1.emplace_back(i);
        for(auto &i : numMap2) numPairs2.emplace_back(i);

        return helper(numPairs1, numPairs2) + helper(numPairs2, numPairs1);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums1 = {7, 4};
        vector<int> nums2 = {5, 2, 8, 9};
        cout << Solution().numTriplets(nums1, nums2) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums1 = {1, 1};
        vector<int> nums2 = {1, 1, 1};
        cout << Solution().numTriplets(nums1, nums2) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums1 = {7, 7, 8, 3};
        vector<int> nums2 = {1, 2, 9, 7};
        cout << Solution().numTriplets(nums1, nums2) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums1 = {4, 7, 9, 11, 23};
        vector<int> nums2 = {3, 5, 1024, 12, 18};
        cout << Solution().numTriplets(nums1, nums2) << endl;
    }
    return 0;
}
#endif