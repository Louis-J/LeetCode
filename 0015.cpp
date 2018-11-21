#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> rlt;
        if(nums.size() < 3){
            return rlt;
        }
        sort(nums.begin(), nums.end());

        for(vector<int>::iterator i = nums.begin(); i + 1 != nums.end() && *i <= 0;){
            vector<int>::iterator j = i + 1, k = nums.end() - 1;
            while(j != k){
                if(*i + *j + *k < 0){
                    while(j != k && *j == *(++j) ){}
                }
                else if(*i + *j + *k > 0){
                    while(j != k && *k == *(--k) ){}
                }
                else{
                    rlt.push_back(vector<int>({*i, *j, *k}));
                    while(j != k && *j == *(++j) ){}
                    while(j != k && *k == *(--k) ){}
                }
            }
            while(i + 1 != nums.end() && *i == *(++i)){}
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        auto ret = Solution().threeSum(nums);

        IntVector2DPrint(ret);
    }
    return 0;
}