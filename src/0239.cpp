#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    template<typename T>
    class CirQue2 {
        const size_t capacity;
        size_t num = 0;
        size_t start = 0;
        T *const que;
    public:
        CirQue2(size_t n): capacity(n), que(new T[n]) {}
        ~CirQue2() {delete[] que;}
        bool empty() {return num == 0;}
        T &front() {return que[start];}
        T &back() {return que[(start+num-1)%capacity];}
        void pop_front() {
            start = (start+1)%capacity;
            num--;
        }
        void pop_back() {
            num--;
        }
        template<typename... _Args>
        void emplace_back(_Args&&... __args) {
            que[(start+num)%capacity] = T(std::forward<_Args>(__args)...);
            num++;
        }
        void emplace_back(T &n) {
            que[(start+num)%capacity] = n;
            num++;
        }
    };
    template<typename T>
    class CirQue3 {
        T *const que, *const nail;
        T *b, *e;
        bool isempty = true;
    public:
        CirQue3(size_t n): que(new T[n]), nail(que+n-1), b(que), e(que) {}
        ~CirQue3() {delete[] que;}
        bool empty() {return isempty;}
        T &front() {return *b;}
        T &back() {return *e;}
        void pop_front() {
            if(b == e)
                isempty = true;
            else {
                if(b != nail)
                    b++;
                else
                    b = que;
            }
        }
        void pop_back() {
            if(b == e)
                isempty = true;
            else {
                if(e != que)
                    e--;
                else
                    e = nail;
            }
        }
        template<typename... _Args>
        void emplace_back(_Args&&... __args) {
            if(isempty) {
                *e = T(std::forward<_Args>(__args)...);
                isempty = false;
            } else {
                if(e != nail)
                    e++;
                else
                    e = que;
                *e = T(std::forward<_Args>(__args)...);
            }
        }
        void emplace_back(T &n) {
            if(isempty) {
                *e = n;
                isempty = false;
            } else {
                if(e != nail)
                    e++;
                else
                    e = que;
                *e = n;
            }
        }
    };
public:
    vector<int> maxSlidingWindow0(vector<int>& nums, int k) {
        if(nums.size() <= 0) {
            return vector<int>{0};
        }
        deque<int> windows;
        vector<int> result(nums.size()-k+1);
        for (int i = 0; i < nums.size(); i++) {
            if (i >= k && windows.front() <= i - k) {
                windows.pop_front();
            }
            while (!windows.empty() && nums[windows.back()] <= nums[i]) {
                windows.pop_back();
            }
            windows.push_back(i);
            if (i >= k-1) {
                result[i - k+1] = nums[windows.front()];
            }
        }
        return result;
    }
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) {
        using CirQue = CirQue2<int>;
        if(nums.size() <= 1 || k == 1)
            return nums;
        else if(nums.size() <= k) {
            int maxn = nums[0];
            for(auto it = nums.begin()+1; it != nums.end(); it++)
                maxn = max(maxn, *it);
            return vector<int>{maxn};
        }
        CirQue window(k);
        k--;
        vector<int> ret(nums.size()-k);

        for(size_t i = 0; i < k; i++) {
            while(!window.empty() && nums[window.back()] <= nums[i])
                window.pop_back();
            window.emplace_back(i);
        }
        
        for(size_t i = 0; i < ret.size(); i++) {
            if(window.front() < i)
                window.pop_front();
            while(!window.empty() && nums[window.back()] <= nums[i+k])
                window.pop_back();
            window.emplace_back(i+k);
            ret[i] = nums[window.front()];
        }
        return ret;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() <= k) {
            int maxn = nums[0];
            // for(auto it = nums.begin()+1; it != nums.end(); it++)
            //     maxn = max(maxn, *it);
            for(size_t i = 1; i < nums.size(); i++)
                maxn = max(maxn, nums[i]);
            return vector<int>{maxn};
        }
        // deque<pair<size_t, int>> window;
        CirQue2<pair<int, int>> window(k);
        k--;
        vector<int> ret;
        ret.reserve(nums.size()-k);

        size_t i = 0;
        for(; i < k; i++) {
            while(!window.empty() && window.back().second <= nums[i])
                window.pop_back();
            window.emplace_back(i, nums[i]);
        }
        for(; i < nums.size(); i++) {
            if(window.front().first < i-k)
                window.pop_front();
            while(!window.empty() && window.back().second <= nums[i])
                window.pop_back();
            window.emplace_back(i, nums[i]);
            ret.emplace_back(window.front().second);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    //     // Solution().maxSlidingWindow(nums, 3);
    //     cout << Solution().maxSlidingWindow(nums, 3) << endl;
    // }
    cout << "2:" << endl;
    {
        vector<int> nums = {1, 3, 1, 2, 0, 5};
        // Solution().maxSlidingWindow(nums, 3);
        cout << Solution().maxSlidingWindow(nums, 3) << endl;
    }
    // cout << "3:" << endl;
    // {
    //     vector<int> nums = {-95,92,-85,59,-59,-14,88,-39,2,92,94,79,78,-58,37,48,63,-91,91,74,-28,39,90,-9,-72,-88,-72,93,38,14,-83,-2,21,4,-75,-65,3,63,100,59,-48,43,35,-49,48,-36,-64,-13,-7,-29,87,34,56,-39,-5,-27,-28,10,-57,100,-43,-98,19,-59,78,-28,-91,67,41,-64,76,5,-58,-89,83,26,-7,-82,-32,-76,86,52,-6,84,20,51,-86,26,46,35,-23,30,-51,54,19,30,27,80,45,22};
    //     cout << Solution().maxSlidingWindow(nums, 10) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     vector<int> nums = {1, 2, 3, 3, 3, 2, 1};
    //     cout << Solution().candy(nums) << endl;
    // }
    
    return 0;
}
#endif