#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

// 完全错误，无法使用分治，只能使用贪心加二分
/*
class Solution0 {
    static void mergeGet(vector<tuple<int, int>> &p1, vector<tuple<int, int>> &p2, bool order, int begin, int end) {
        if(begin == end) {
            if(order) p2[begin] = p1[begin];
            return;
        }
        int middle = (begin + end + 1) / 2;
        mergeGet(p1, p2, !order, begin, middle - 1);
        mergeGet(p1, p2, !order, middle, end);

        vector<tuple<int, int>> &pf   = order ? p1 : p2;
        vector<tuple<int, int>> &pt   = order ? p2 : p1;
        int                      i    = 0;
        int                      j    = 0;
        int                      maxi = -1;
        while(i <= middle - begin - 1 || j <= end - middle) {
            if(j > end - middle || (i <= middle - begin - 1 && get<0>(pf[begin + i]) < get<0>(pf[middle + j]))) {
                pt[begin + i + j] = pf[begin + i];
                auto &ptHere      = pt[begin + i + j];
                if(maxi == -1 || get<1>(pf[begin + i]) >= get<1>(pt[maxi])) {
                    maxi = begin + i + j;
                }
                if(get<2>(ptHere) != 0) {
                    get<2>(ptHere) = begin + i + j - get<2>(pf[begin + i - get<2>(ptHere)]);
                }
                get<2>(pf[begin + i]) = begin + i + j;
                i++;
            } else {
                pt[begin + i + j] = pf[middle + j];
                auto &ptHere      = pt[begin + i + j];
                if(maxi != -1 &&
                   (get<2>(ptHere) == 0 || get<1>(pt[maxi]) > get<1>(pt[get<2>(pf[middle + j - get<2>(ptHere)])]) ||
                    (get<1>(pt[maxi]) == get<1>(pt[get<2>(pf[middle + j - get<2>(ptHere)])]) &&
                     maxi > get<2>(pf[middle + j - get<2>(ptHere)])))) {
                    get<1>(ptHere) = get<1>(pt[maxi]) + 1;
                    get<2>(ptHere) = begin + i + j - maxi;
                } else if(get<2>(ptHere) != 0) {
                    get<1>(ptHere) = get<1>(pt[get<2>(pf[middle + j - get<2>(ptHere)])]) + 1;
                    get<2>(ptHere) = begin + i + j - get<2>(pf[middle + j - get<2>(ptHere)]);
                }
                get<2>(pf[middle + j]) = begin + i + j;
                j++;
            }
        }
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        vector<tuple<int, int>> p1;  // num, lenNow
        vector<tuple<int, int>> p2(nums.size());
        for(auto &i : nums) {
            p1.emplace_back(i, 1);
        }
        mergeGet(p1, p2, true, 0, p1.size() - 1);
        int ret = 0;
        for(auto &i : p2) ret = max(ret, get<1>(i));
        return ret;
    }
};
*/
class Solution {
    inline void addNum(vector<int> &greedy, int num) {
        if(greedy.size() == 0 || greedy.back() < num) {
            greedy.emplace_back(num);
            return;
        }
        int i = 0;
        int j = greedy.size() - 1;

        while(i != j) {
            int middle = (i + j) / 2;
            if(greedy[middle] == num) {
                return;
            } else if(greedy[middle] < num) {
                i = middle + 1;
            } else {
                j = middle;
            }
        }
        greedy[i] = num;
    }

public:
    int lengthOfLIS0(vector<int> &nums) {
        vector<int> greedy;
        for(auto &i : nums) addNum(greedy, i);
        return greedy.size();
    }
    int lengthOfLIS(vector<int> &nums) {
        vector<int> greedy{nums[0]};
        for(int i = 1; i < nums.size(); i++) {
            int &num = nums[i];
            if(greedy.back() < num) {
                greedy.emplace_back(num);
            } else {
                int l = 0;
                int r = greedy.size() - 1;

                while(true) {
                    if(l == r) {
                        greedy[l] = num;
                        break;
                    }
                    int middle = (l + r) / 2;
                    if(greedy[middle] == num) {
                        break;
                    } else if(greedy[middle] < num) {
                        l = middle + 1;
                    } else {
                        r = middle;
                    }
                }
            }
        }
        return greedy.size();
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    // cout << "2:" << endl;
    // {
    //     vector<int> nums = {0, 1, 0, 3, 2, 3};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    // cout << "3:" << endl;
    // {
    //     vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    // cout << "4:" << endl;
    // {
    //     vector<int> nums = {1, 3, 6, 7, 9, 4, 10, 5, 6};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    // cout << "5:" << endl;
    // {
    //     vector<int> nums = {2, 15, 3, 7, 8, 6, 18};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    // cout << "6:" << endl;
    // {
    //     vector<int> nums = {-962, 768, 430, 576, 160, 577, -329, 175, 51, 699, -113};
    //     cout << Solution().lengthOfLIS(nums) << endl;
    // }
    cout << "7:" << endl;
    {
        vector<int> nums = {3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
        cout << Solution().lengthOfLIS0(nums) << endl;
        cout << Solution().lengthOfLIS(nums) << endl;
    }
    return 0;
}
#endif
