#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> rlt;
        if(nums.size() < 4){
            return rlt;
        }
        sort(nums.begin(), nums.end());

        for(vector<int>::iterator i = nums.begin(); i + 3 != nums.end() && *i * 4 <= target;){
            for(vector<int>::iterator j = i + 1; j + 2 != nums.end() && *j * 3 <= target - *i;){
                vector<int>::iterator k = j + 1, l = nums.end() - 1;
                while(k != l){
                    if(*i + *j + *k + *l < target){
                        while(k != l && *k == *(++k) ){}
                    }
                    else if(*i + *j + *k + *l > target){
                        while(k != l && *l == *(--l) ){}
                    }
                    else{
                        rlt.push_back(vector<int>({*i, *j, *k, *l}));
                        while(k != l && *k == *(++k) ){}
                        while(k != l && *l == *(--l) ){}
                    }
                }
                while(*j == *(++j) && j + 2 != nums.end()){}
            }
            while(*i == *(++i + 1) && i + 3 != nums.end()){}
        }
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

        auto ret = Solution().fourSum(nums, target);

        IntVector2DPrint(ret);
    }
    return 0;
}