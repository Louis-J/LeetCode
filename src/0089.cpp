#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
#include<assert.h>
#include <range/v3/all.hpp>

using namespace std;
using namespace ranges;

class Solution {
public:
    vector<int> grayCode_rva(int n) {
        vector<int> rlt{0};
        vector<int> indexs(n+1, 1);
        for(const auto &i : view::ints(1,n+1)){
            indexs[i] = 2*indexs[i-1];
        }
        rlt.reserve(indexs[n]);
        for(const auto &i : view::ints(1,n+1)){
            for(const auto &j : rlt | view::reverse){
                rlt.emplace_back(j + indexs[i-1]);
            }
        }
        return rlt;
    }
    vector<int> grayCode(int n) {
        vector<int> rlt{0};
        vector<int> indexs(n+1, 1);
        for(int i = 1; i <= n; i++){
            indexs[i] = 2*indexs[i-1];
        }
        rlt.reserve(indexs[n]);
        for(int i = 1; i <= n; i++){
            for(auto j = rlt.rbegin(); j != rlt.rend(); j++){
                rlt.emplace_back(*j + indexs[i-1]);
            }
        }
        return rlt;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        vector<int> ret = Solution().grayCode(n);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}