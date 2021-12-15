#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <functional>
#include <assert.h>

using namespace std;

class Solution {
public:
    string multiply0(string num1, string num2) {
        vector<int> sum(num1.size() + num2.size(), 0);
        for(unsigned i = 0; i < num1.size(); i++){
            for(unsigned j = 0; j < num2.size(); j++){
                sum[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(unsigned i = sum.size() - 1; i > 0; i--){
            sum[i - 1] += sum[i] / 10;
            sum[i] = sum[i] % 10 + '0';
        }
        sum[0] += '0';
        vector<int>::iterator b;
        for(b = sum.begin(); b != sum.end() && *b == '0'; b++){}
        return b == sum.end() ? string("0") : string(b, sum.end());
    }
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> sum(num1.size() + num2.size(), 0);
        for(unsigned i = 0; i < num1.size(); i++){
            for(unsigned j = 0; j < num2.size(); j++){
                sum[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        for(unsigned i = sum.size() - 1; i > 0; i--){
            sum[i - 1] += sum[i] / 10;
            sum[i] = sum[i] % 10 + '0';
        }
        sum[0] += '0';
        return string(sum.begin() + (sum[0] == '0' ? 1 : 0), sum.end());
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}