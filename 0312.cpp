#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int maxCoins0(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }
        int tmp;
        vector<int> index(nums.size()-2);
        tmp = 1;
        for(auto &i : index)
            i = tmp++;
        sort(index.begin(), index.end(), [&nums](int a, int b) {
            return nums[a] < nums[b];
        });

        vector<int> lidx(nums.size());
        tmp = -1;
        for(auto &i : lidx)
            i = tmp++;
        vector<int> ridx(nums.size());
        tmp = 1;
        for(auto &i : ridx)
            i = tmp++;

        int sum = nums[0]*nums[nums.size()-1] + max(nums[0], nums[nums.size()-1]);
        for(auto &i : index) {
            sum += nums[i]*nums[lidx[i]]*nums[ridx[i]];
            lidx[i+1] = lidx[i];
            ridx[i-1] = ridx[i];
        }
        return sum;
    }
    int maxCoins1(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        } else {
            vector<int> newnums(nums.begin()+1, nums.end());
            int summax = maxCoins1(newnums) + nums[0]*nums[1];
            size_t i;
            for(i = 0; i < newnums.size()-1; i++) {
                newnums[i] = nums[i];
                int ret = maxCoins1(newnums);
                int tmp = ret + nums[i]*nums[i+1]*nums[i+2];
                if(summax < tmp)
                    summax = tmp;
                if(tmp == 552400)
                    cout << ret << newnums << endl;
            }
            newnums[i] = nums[i];
            int ret = maxCoins1(newnums);
            int tmp = ret + nums[i]*nums[i+1];
            if(summax < tmp)
                summax = tmp;
            if(tmp == 552400)
                cout << ret << newnums << endl;
            return summax;
        }
    }
    int maxCoins2(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }
        int tmp;
        vector<int> index;
        for(size_t i = 1; i < nums.size()-1; i++) {
            if(nums[i] <= nums[i-1] && nums[i] <= nums[i+1])
                index.emplace_back(i);
        }

        vector<int> lidx(nums.size());
        tmp = -1;
        for(auto &i : lidx)
            i = tmp++;
        vector<int> ridx(nums.size());
        tmp = 1;
        for(auto &i : ridx)
            i = tmp++;

        int sum = 0;
        for(size_t i = 0; i < index.size(); i++) {
            auto j = index[i];
            sum += nums[j]*nums[lidx[j]]*nums[ridx[j]];
            lidx[j+1] = lidx[j];
            ridx[j-1] = ridx[j];

            int tmpl = lidx[j];
            if(tmpl != 0 && nums[tmpl] <= nums[lidx[tmpl]] && nums[tmpl] <= nums[ridx[tmpl]])
                index.emplace_back(tmpl);
                
            int tmpr = ridx[j];
            if(tmpr != nums.size()-1 && nums[tmpr] <= nums[lidx[tmpr]] && nums[tmpr] <= nums[ridx[tmpr]])
                index.emplace_back(tmpr);
        }
        vector<int> remain;
        for(int i = 0; i != nums.size(); i = ridx[i]) {
            remain.emplace_back(nums[i]);
        }
        return sum+maxCoins1(remain);
    }
    int maxCoins(vector<int>& nums) {
        if(nums.size() <= 2) {
            if(nums.size() == 2) {
                return nums[0]*nums[1] + max(nums[0], nums[1]);
            } else if(nums.size() == 1) {
                return nums[0];
            } else {
                return 0;
            }
        }
        map<size_t, int> coins;
        
        for(size_t i = 0; i < nums.size()-2; i++) {
            coins.emplace_back(i, nums[i]*nums[i+1] + max(nums[i], nums[i+1]))
        }
        for(size_t i = 2; i < nums.size(); i++) {
            map<size_t, int> tmp;
            for(size_t j = 0; j < nums.size()-i-1; j++) {
                int minnum = coins
                tmp.emplace_back()
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    // cout << " 1:" << endl;
    // {
    //     vector<int> nums = {3, 1, 5, 8};
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    // cout << " 2:" << endl;
    // {
    //     vector<int> nums = {9, 76, 64, 21, 97, 60};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     /*
    //     9 76 64 97 60
    //     130368

    //     9 76 97 60
    //     602176

    //     9 76 60
    //     1044496

    //     >>
    //     1086136
    //     */
    // }
    // cout << " 3:" << endl;
    // {
    //     vector<int> nums = {104, 105, 106, 108, 106};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins2(nums) << endl;
    // }
    // cout << " 4:" << endl;
    // {
    //     vector<int> nums = {9, 76, 64, 21, 97, 60};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins2(nums) << endl;
    // }
    // cout << " 5:" << endl;
    // {
    //     vector<int> nums = {35, 16, 83, 87, 84, 59, 48, 41, 20, 54};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    // cout << " 6:" << endl;
    // {
    //     vector<int> nums = {35, 16, 83, 87, 84, 59, 48, 41, 54};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    // cout << " 7:" << endl;
    // {
    //     vector<int> nums = {35, 16, 83, 84, 59, 48, 41, 54};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    // cout << " 8:" << endl;
    // {
    //     vector<int> nums = {35, 16, 83, 59, 48, 41, 54};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    // cout << " 9:" << endl;
    // {
    //     vector<int> nums = {35, 16, 83, 48, 41, 54};
    //     cout << Solution().maxCoins1(nums) << endl;
    //     cout << Solution().maxCoins(nums) << endl;
    // }
    cout << " 10:" << endl;
    {
        vector<int> nums = {35, 16, 83, 41, 54};
        cout << Solution().maxCoins1(nums) << endl;
        cout << Solution().maxCoins(nums) << endl;
    }
    return 0;
}
#endif