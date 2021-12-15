#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int rlt = nums[0] + nums[1] + nums[2];

        for(vector<int>::iterator i = nums.begin(); i + 2 != nums.end() && rlt != target;){
            vector<int>::iterator j = i + 1, k = nums.end() - 1;
            while(j != k){
                if(*i + *j + *k < target){
                    rlt = abs(*i + *j + *k - target) < abs(rlt - target) ? *i + *j + *k : rlt;
                    while(j != k && *j == *(++j) ){}
                }
                else if(*i + *j + *k > target){
                    rlt = abs(*i + *j + *k - target) < abs(rlt - target) ? *i + *j + *k : rlt;
                    while(j != k && *k == *(--k) ){}
                }
                else{
                    return target;
                }
            }
            while(*i == *(++i) && i + 2 != nums.end()){}
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

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}