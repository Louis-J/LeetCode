#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
//#include <boost/progress.hpp>
#include<assert.h>
//#include <range/v3/all.hpp>

using namespace std;
//using namespace ranges;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> rlt;
        for(int i = 1; i < s.size() && i <= 3 &&
            !(i >= 2 && s[0] == '0') &&
            !(i == 3 && s[0]*100+s[1]*10+s[2] - '0'*111> 255); i++){
            for(int j = i+1; j < s.size() && j-i <= 3 &&
                !(j-i >= 2 && s[i] == '0') &&
                !(j-i == 3 && s[i]*100+s[i+1]*10+s[i+2] - '0'*111> 255); j++){
                for(int k = j+1; k < s.size() && k-j <= 3 &&
                    !(k-j >= 2 && s[j] == '0') &&
                    !(k-j == 3 && s[j]*100+s[j+1]*10+s[j+2] - '0'*111> 255); k++){
                    if(int l = s.size()-k; l <= 3 && l <= 3 &&
                        !(l >= 2 && s[k] == '0') &&
                        !(l == 3 && s[k]*100+s[k+1]*10+s[k+2] - '0'*111> 255)){
                        rlt.emplace_back(s.substr(0, i) + "." +
                                            s.substr(i, j-i) + "." +
                                            s.substr(j, k-j) + "." +
                                            s.substr(k, s.size()-k));
                    }
                }
            }
        }
        return rlt;
    }
};

int main() {
    string line;
    while (cin >> line) {
        auto ret = Solution().restoreIpAddresses(line);
        for(auto r : ret){
            cout << r << endl;
        }
    }
    return 0;
}