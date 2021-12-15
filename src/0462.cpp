#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int minMoves20(vector<int>& nums) {
        map<int, int> a;
        for(auto &i: nums)
            a[i]++;
        if(a.size() == 0)
            return 0;

        auto it = a.begin();
        int have = 0;
        int rest = nums.size() - it->second;

        for(; have + it->second < rest; have += it->second, it++, rest -= it->second) {}
        
        int move = 0;
        int pin = it->first;
        for(auto &i: nums) {
            move += abs(i-pin);
        }
        return move;
    }
    int minMoves21(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> a{{nums[0], 1}};
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == a[a.size()-1].first)
                a[a.size()-1].second++;
            else
                a.emplace_back(nums[i], 1);
        }
        if(a.size() == 0)
            return 0;

        auto it = a.begin();
        int have = 0;
        int rest = nums.size() - it->second;

        for(; have + it->second < rest; have += it->second, it++, rest -= it->second) {}
        
        int move = 0;
        int pin = it->first;
        for(auto &i: a) {
            move += abs(i.first-pin)*i.second;
        }
        return move;
    }
    int minMoves23(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0] == nums[nums.size()-1])
            return 0;

        int move = 0;
        int pin = nums[nums.size()/2];
        for(auto &i: nums) {
            move += abs(i-pin);
        }
        return move;
    }
    int minMoves24(vector<int>& nums) {
        const size_t Len = nums.size();
        int *arr = new int[Len];
        copy(nums.begin(), nums.end(), arr);


        sort(arr, arr+Len);
        if(arr[0] == arr[Len-1])
            return 0;

        int move = 0;
        int pin = arr[Len/2];
        auto pinit = arr+Len/2;
        for(auto it = arr; it < pinit; it++) {
            move += pin-*it;
        }
        for(auto it = pinit; it < arr+Len; it++) {
            move += *it-pin;
        }
        return move;
    }
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int increment, decrement, target=0;
        for(int i = 1; i < n; ++i) {
            increment = (nums[i] - nums[i-1]) * i;
            decrement = (nums[i] - nums[i-1]) * (n-i);
            if(increment <= decrement) {
                target = i;
            }
            else
                break;
        }
        int ans = 0;
        for(auto& num : nums)
            ans += abs(num - nums[target]);
        return int(ans);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<int> nums = {1, 2, 3};
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> nums = {1, 4, 4};
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> nums = {1, 2, 1};
        cout << Solution().minMoves2(nums) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<int> nums = {1, 2, 2};
        cout << Solution().minMoves2(nums) << endl;
    }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums = {2, 2, 4, 4};
    //     cout << Solution().minMoves2(nums) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     //2
    //     cout << Solution().strongPasswordChecker("aaa111") << endl;
    // }
    return 0;
}
#endif