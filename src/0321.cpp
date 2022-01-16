#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    static void GetMaxL0(deque<int> &ret, const vector<int> &nums, int l) {
        if(l == 0)
            return;
        else if(l == 1) {
            int v = nums[0];
            for(int i = 1; i < nums.size(); i++)
                v = max(v, nums[i]);
            ret.emplace_back(v);
            return;
        }
        for(int i = 0;; i++) {
            while(nums.size() - i > l - ret.size() && ret.size() && ret.back() < nums[i])
                ret.pop_back();
            if(i == nums.size())
                break;
            else if(l > ret.size())
                ret.push_back(nums[i]);
        }
    }
    static void Merge0(vector<int> &nums, deque<int> &que1, deque<int> &que2) {
        while(que1.size() && que2.size()) {
            if(que1 > que2) {
                nums.emplace_back(que1.front());
                que1.pop_front();
            } else {
                nums.emplace_back(que2.front());
                que2.pop_front();
            }
        }
        if(que1.size())
            nums.insert(nums.end(), que1.begin(), que1.end());
        else
            nums.insert(nums.end(), que2.begin(), que2.end());
    }
    vector<int> maxNumber0(const vector<int> nums1, const vector<int> nums2, const int k) {
        vector<int> ret;
        vector<int> tmp;
        deque<int> que1, que2;

        int i = max(0, k - (int)nums2.size());
        int j = k-max(0, k - (int)nums1.size());
        GetMaxL0(que1, nums1, i);
        GetMaxL0(que2, nums2, k-i);
        Merge0(ret, que1, que2);

        for(i++; i <= j; i++) {
            tmp.clear();
            que1.clear();
            que2.clear();
            GetMaxL0(que1, nums1, i);
            GetMaxL0(que2, nums2, k-i);
            Merge0(tmp, que1, que2);
            if(ret < tmp)
                swap(ret, tmp);
        }
        return ret;
    }

    
    static vector<int> &GetMaxL1(vector<int> &ret, const vector<int> &nums, int l) {
        if(l == 0)
            return ret;
        else if(l == 1) {
            int v = nums[0];
            for(int i = 1; i < nums.size(); i++)
                v = max(v, nums[i]);
            ret.push_back(v);
            return ret;
        }
        for(int i = 0;; i++) {
            while(nums.size() - i > l - ret.size() && ret.size() && ret[ret.size()-1] < nums[i])
            // while(nums.size() - i > l - ret.size() && ret.size() && *(--ret.end()) < nums[i])
                ret.pop_back();
            if(i == nums.size())
                break;
            else if(l > ret.size())
                ret.push_back(nums[i]);
        }
        return ret;
    }
    static inline bool myGreater1(vector<int> &que1, vector<int> &que2, int i1, int i2) {
        for(; i1 < que1.size() && i2 < que2.size(); i1++, i2++) {
            if(que1[i1] != que2[i2])
                return que1[i1] > que2[i2];
        }
        return i1 < que1.size();
    }
    static void Merge1(vector<int> &nums, vector<int> &que1, vector<int> &que2) {
        if(que1.size() == 0) {
            swap(nums, que2);
            return;
        } else if(que2.size() == 0) {
            swap(nums, que1);
            return;
        }
        for(int i1 = 0, i2 = 0; ;) {
            if(myGreater1(que1, que2, i1, i2)) {
                nums.push_back(que1[i1++]);
                if(i1 == que1.size()) {
                    nums.insert(nums.end(), que2.begin() + i2, que2.end());
                    return;
                }
            } else {
                nums.push_back(que2[i2++]);
                if(i2 == que2.size()) {
                    nums.insert(nums.end(), que1.begin() + i1, que1.end());
                    return;
                }
            }
        }
    }
    static inline bool myGreater2(vector<int>::iterator it1, vector<int>::iterator it2, vector<int>::iterator e1, vector<int>::iterator e2) {
        for(; it1 < e1 && it2 < e2; it1++, it2++) {
            if(*it1 != *it2)
                return *it1 > *it2;
        }
        return it1 < e1;
    }
    static void Merge2(vector<int> &nums, vector<int> &que1, vector<int> &que2) {
        if(que1.size() == 0) {
            swap(nums, que2);
            return;
        } else if(que2.size() == 0) {
            swap(nums, que1);
            return;
        }
        for(vector<int>::iterator it1 = que1.begin(), it2 = que2.begin(); ;) {
            if(myGreater2(it1, it2, que1.end(), que2.end())) {
                nums.push_back(*(it1++));
                if(it1 == que1.end()) {
                    nums.insert(nums.end(), it2, que2.end());
                    return;
                }
            } else {
                nums.push_back(*(it2++));
                if(it2 == que2.end()) {
                    nums.insert(nums.end(), it1, que1.end());
                    return;
                }
            }
        }
    }
    vector<int> maxNumber(const vector<int> nums1, const vector<int> nums2, const int k) {
        vector<int> ret;
        vector<int> tmp;
        vector<int> que1, que2;

        int i = max(0, k - (int)nums2.size());
        int j = k-max(0, k - (int)nums1.size());
        
        Merge1(ret, GetMaxL1(que1, nums1, i), GetMaxL1(que2, nums2, k-i));

        for(i++; i <= j; i++) {
            tmp.clear();
            que1.clear();
            que2.clear();
            Merge1(tmp, GetMaxL1(que1, nums1, i), GetMaxL1(que2, nums2, k-i));
            if(ret < tmp)
                swap(ret, tmp);
        }
        return ret;
    }
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
    //     // 9 7 5
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
    cout << " 8:" << endl;
    {
        vector<int> nums1 = {3, 8, 5, 3, 4};
        vector<int> nums2 = {8, 7, 3, 6, 8};
        int k = 5;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 9:" << endl;
    {
        //7,6,7,5,1,0,2,1,0,1,0,5,6,0,5,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3,0
        vector<int> nums1 = {5,0,2,1,0,1,0,3,9,1,2,8,0,9,8,1,4,7,3};
        vector<int> nums2 = {7,6,7,1,0,1,0,5,6,0,5,0};
        int k = 31;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 10:" << endl;
    {
        //8,8,6,6,5,4,6,3,7,5,6,4,5,6,4,0
        vector<int> nums1 = {6, 5, 4, 6, 3, 7, 5, 6, 4, 5, 6, 4};
        vector<int> nums2 = {8, 8, 6, 0};
        int k = 16;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    cout << " 11:" << endl;
    {
        //9,8,8,8,7,6,2,3
        vector<int> nums1 = {5, 9, 3, 7, 5, 6, 2, 3};
        vector<int> nums2 = {3, 8, 1, 2, 8, 6, 0, 8};
        int k = 8;
        cout << Solution().maxNumber(nums1, nums2, k) << endl;
    }
    return 0;
}
#endif