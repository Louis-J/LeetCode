#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int getsize(vector<int> &nums, int num, int b, int e) {
        int size = 0;
        for(int i = b; i <= e; i++)
            if(nums[i] == num)
                size++;
        return size;
    }
    static pair<int, int> getme(vector<int> &nums, int b, int e) {
        if(e == b)
            return {nums[b], 1};
        int ml = (b+e)/2, mr = ml+1;
        pair<int, int> l = getme(nums, b, ml);
        pair<int, int> r = getme(nums, mr, e);

        l.second += getsize(nums, l.first, mr, e);
        r.second += getsize(nums, r.first, b, ml);

        if(l.second >= r.second)
            return l;
        else
            return r;
    }
public:
    int majorityElement0(vector<int>& nums) {
        return getme(nums, 0, nums.size()-1).first;
    }
    int majorityElement1(vector<int>& nums) {
        unordered_map<int, int> a;
        pair<int, int> b{0, 0};
        for(auto i: nums) {
            auto &r = ++a[i];
            if(b.second < r)
                b = {i, r};
        }
        return b.first;
    }
    int majorityElement(vector<int>& nums) {
        int num = 0, count = 0;
        int l = 0;
        for(auto &i: nums) {
            l++;
            if(i == num)
                count++;
            else if(count <= l/2)
                num = i, count = 1, l = 1;
        }
        return num;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {3, 2, 3};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {1, 4, 4};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums = {2,2,1,1,1,2,2};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums = {10,9,9,9,10};
        cout << Solution().majorityElement(nums) << endl;
    }
    cout << " 5:" << endl;
    {
        vector<int> nums = {2,2,3,3,3,3,2};
        cout << Solution().majorityElement(nums) << endl;
    }
    return 0;
}
#endif