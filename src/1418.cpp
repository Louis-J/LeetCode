#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    vector<vector<string>> displayTable0(vector<vector<string>> &orders) {
        vector<vector<string>>                                         ret;
        unordered_map<int, int>                                        tableDict;
        unordered_map<string_view, pair<unordered_map<int, int>, int>> table;
        for(auto &order : orders) {
            int         tableNum = stoi(order[1]);
            string_view food(order[2]);
            tableDict.emplace(tableNum, 0);
            table[food].first[tableNum]++;
        }

        vector<int> tableNums;
        for(auto &[tableNum, ignore] : tableDict) tableNums.emplace_back(tableNum);
        sort(tableNums.begin(), tableNums.end());
        for(int i = 0; i < tableNums.size(); i++) tableDict[tableNums[i]] = i + 1;

        vector<string_view> foods;
        for(auto &[food, ignore] : table) foods.emplace_back(food);
        sort(foods.begin(), foods.end());
        for(int i = 0; i < foods.size(); i++) table[foods[i]].second = i + 1;

        vector<string> tmp;
        tmp.emplace_back("Table");
        tmp.insert(tmp.end(), foods.begin(), foods.end());
        ret.emplace_back(tmp);
        for(int i = 1; i < tmp.size(); i++) tmp[i] = "0";
        for(int i = 0; i < tableNums.size(); i++) {
            tmp[0] = to_string(tableNums[i]);
            ret.emplace_back(tmp);
        }

        for(auto &[ignore, pair] : table) {
            for(auto &[tableNum, num] : pair.first) {
                ret[tableDict[tableNum]][pair.second] = to_string(num);
            }
        }
        return ret;
    }
    vector<vector<string>> displayTable(vector<vector<string>> &orders) {
        vector<vector<string>>                                         ret;
        unordered_map<string_view, int>                                foodDict;
        unordered_map<int, pair<unordered_map<string_view, int>, int>> table;
        for(auto &order : orders) {
            int         tableNum = stoi(order[1]);
            string_view food(order[2]);
            foodDict.emplace(food, 0);
            table[tableNum].first[food]++;
        }

        vector<int> tableNums;
        for(auto &[tableNum, ignore] : table) tableNums.emplace_back(tableNum);
        sort(tableNums.begin(), tableNums.end());
        for(int i = 0; i < tableNums.size(); i++) table[tableNums[i]].second = i + 1;

        vector<string_view> foods;
        for(auto &[food, ignore] : foodDict) foods.emplace_back(food);
        sort(foods.begin(), foods.end());
        for(int i = 0; i < foods.size(); i++) foodDict[foods[i]] = i + 1;

        vector<string> tmp;
        tmp.emplace_back("Table");
        tmp.insert(tmp.end(), foods.begin(), foods.end());
        ret.emplace_back(tmp);
        for(int i = 1; i < tmp.size(); i++) tmp[i] = "0";
        for(int i = 0; i < tableNums.size(); i++) {
            tmp[0] = to_string(tableNums[i]);
            ret.emplace_back(tmp);
        }

        for(auto &[ignore, pair] : table) {
            for(auto &[food, num] : pair.first) {
                ret[pair.second][foodDict[food]] = to_string(num);
            }
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        vector<vector<string>> orders = {{"David", "3", "Ceviche"},       {"Corina", "10", "Beef Burrito"},
                                         {"David", "3", "Fried Chicken"}, {"Carla", "5", "Water"},
                                         {"Carla", "5", "Ceviche"},       {"Rous", "3", "Ceviche"}};
        cout << Solution().displayTable(orders) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<vector<string>> orders = {{"James", "12", "Fried Chicken"},
                                         {"Ratesh", "12", "Fried Chicken"},
                                         {"Amadeus", "12", "Fried Chicken"},
                                         {"Adam", "1", "Canadian Waffles"},
                                         {"Brianna", "1", "Canadian Waffles"}};
        cout << Solution().displayTable(orders) << endl;
    }
    cout << " 3:" << endl;
    {
        // vector<int> nums = {1,-3,2,3,-4};
        // cout << Solution().maxAbsoluteSum(nums) << endl;
    }
    return 0;
}
#endif