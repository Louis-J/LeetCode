#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static constexpr int divNum = 1e9 + 7;

public:
    int recr0(vector<pair<int, int>> newArr, unordered_map<int, int> dict, int fromIndex, int target) {
        int sum = 0;
        for(int i = fromIndex; i < newArr.size() && target >= newArr[i].first * 2; i++) {
            if(target == newArr[i].first * 2) {
                if(newArr[i].second >= 2) sum += newArr[i].second * (newArr[i].second - 1) / 2;
            } else {
                auto it = dict.find(target - newArr[i].first);
                if(it != dict.end()) sum += newArr[i].second * it->second;
            }
        }
        return sum;
    }

    int recr1(vector<pair<int, int>> newArr, int fromIndex, int target) {
        int sum = 0;
        int i = fromIndex, j = newArr.size() - 1;
        while(i < j) {
            int add11 = newArr[i].first + newArr[j].first;
            if(add11 == target) {
                sum += newArr[i].second * newArr[j].second;
                i++, j--;
            } else if(add11 < target) {
                i++;
            } else {
                j--;
            }
        }
        if(i == j && newArr[i].second >= 2 && newArr[i].first * 2 == target) {
            sum += newArr[i].second * (newArr[i].second - 1) / 2;
        }
        return sum;
    }

    int threeSumMulti0(vector<int> &arr, int target) {
        vector<pair<int, int>>  newArr;
        unordered_map<int, int> dict;
        for(auto &i : arr) dict[i]++;
        for(auto &[k, v] : dict) newArr.emplace_back(k, v);
        sort(newArr.begin(), newArr.end(), [](pair<int, int> &l, pair<int, int> &r) { return l.first < r.first; });

        long sum = 0;
        for(int i = 0; i < newArr.size() && target >= newArr[i].first * 3; i++) {
            if(target == newArr[i].first * 3) {
                if(newArr[i].second >= 3)
                    sum += long(newArr[i].second) * (newArr[i].second - 1) * (newArr[i].second - 2) / 6;
            } else {
                auto it = dict.find(target - newArr[i].first * 2);
                if(it != dict.end()) sum += long(newArr[i].second) * (newArr[i].second - 1) / 2 * it->second;

                sum += long(newArr[i].second) * recr0(newArr, dict, i + 1, target - newArr[i].first);
            }
        }
        return sum % divNum;
    }

    int threeSumMulti(vector<int> &arr, int target) {
        vector<pair<int, int>>  newArr;
        unordered_map<int, int> dict;
        for(auto &i : arr) dict[i]++;
        for(auto &[k, v] : dict) newArr.emplace_back(k, v);
        sort(newArr.begin(), newArr.end(), [](pair<int, int> &l, pair<int, int> &r) { return l.first < r.first; });

        long sum = 0;
        for(int i = 0; i < newArr.size() - 1 && target > newArr[i].first; i++) {
            sum += long(newArr[i].second) * recr1(newArr, i + 1, target - newArr[i].first);
        }

        int i = 0, j = newArr.size() - 1;
        while(i < j) {
            int add21 = newArr[i].first * 2 + newArr[j].first;
            if(add21 == target) {
                if(newArr[i].second >= 2) sum += long(newArr[i].second) * (newArr[i].second - 1) * newArr[j].second / 2;
                i++, j--;
            } else if(add21 < target) {
                i++;
            } else {
                j--;
            }
        }
        if(i == j && newArr[i].second >= 3 && newArr[i].first * 3 == target) {
            sum += long(newArr[i].second) * (newArr[i].second - 1) * (newArr[i].second - 2) / 6;
        }
        return sum % divNum;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(false);
    cout << " 1:" << endl;
    {
        vector<int> arr    = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
        int         target = 8;
        cout << Solution().threeSumMulti(arr, target) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<int> arr    = {1, 1, 2, 2, 2, 2};
        int         target = 5;
        cout << Solution().threeSumMulti(arr, target) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<int> arr    = {0, 0, 0};
        int         target = 0;
        cout << Solution().threeSumMulti(arr, target) << endl;
    }
    return 0;
}
#endif