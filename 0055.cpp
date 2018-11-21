#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>
#include <assert.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxjump = -1;
        for(int i = 0; i < nums.size(); i++){
            if(maxjump < nums[i] + i){
                maxjump = nums[i] + i;
                if(maxjump >= nums.size() - 1){
                    return true;
                }
            }
            if(i == maxjump){
                return false;
            }
        }
        return false;
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}