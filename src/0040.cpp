#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> rlt;
        function<void(vector<int>&& now, unsigned index, int leave)> recursion;
        recursion = [&recursion, &rlt, &candidates](vector<int>&& now, unsigned index, int leave){
            int nowsize = now.size();
            now.push_back(0);
            for(;index < candidates.size() && leave > candidates[index];){
                now[nowsize] = candidates[index];
                recursion(move(now), index + 1, leave - candidates[index]);
                while(++index < candidates.size() && candidates[index] == candidates[index-1]){}
            }
            if(leave == candidates[index]){
                now[nowsize] = leave;
                rlt.push_back(now);
            }
            now.resize(nowsize);
        };
        recursion(vector<int>(), 0, target);
        return rlt;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

void IntVector2DPrint(const vector<vector<int>> &vec)
{
    printf("[\n");
    for (size_t i = 0; i < vec.size(); i++)
    {
        printf("[ ");
        for (size_t j = 0; j < vec[i].size(); j++)
            printf("%d, ", vec[i][j]);
        printf(" ]\n");
    }
    printf("]\n");
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        auto ret = Solution().combinationSum2(nums, target);

        IntVector2DPrint(ret);
    }
    return 0;
}