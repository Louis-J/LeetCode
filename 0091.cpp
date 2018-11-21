#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
#include <boost/progress.hpp>
#include<assert.h>
#include <range/v3/all.hpp>

using namespace std;
using namespace ranges;

class Solution {
private:
    class Fib{
    private:
        vector<int> fib;
    public:
        Fib():fib(2, 1){}
        int operator()(int n){
            if(n >= fib.size()){
                for(int i = fib.size(); i <= n; i++){
                    fib.emplace_back(fib[i - 1] + fib[i - 2]);
                }
            }
            return fib[n];
        }
    };
    static Fib f;
public:
    //O(n),分类累乘法
    int numDecodings0(string s) {
        int rlt = 1;
        for(int i = -1, j = 0;; j++){
            if(j >= s.size()){
                rlt *= f(j - i - 1);
                break;
            }else if(s[j] == '0'){
                if(j-1 == i || s[j-1] >= '3'){
                    return 0;
                }else{
                    rlt *= f(j - i - 2);
                    i = j;
                }
            }else if(s[j] == '0' || (s[j] >= '7' && (j-1 > i && s[j-1] == '2'))){
                rlt *= f(j - i - 1);
                i = j;
            }else if(s[j] >= '3'){
                rlt *= f(j - i);
                i = j;
            }
        }
        return rlt;
    }
    //O(n),分类累加法
    int numDecodings1(string s) {
        if(s.size() == 0 || s[0] == '0'){
            return 0;
        }
        int sum = 1, sum_1 = 1, sum_2 = 1;
        for(int i = 1; i < s.size(); i++){
            int now = s[i-1]*10 + s[i] - 11*'0';
            if(now == 10 || now == 20){
                sum = sum_2;
            }else if(s[i] == '0'){
                return 0;
            }else if(now > 26 || now < 10){
                sum = sum_1;
            }else{
                sum = sum_1 + sum_2;
            }
            sum_2 = sum_1;
            sum_1 = sum;
        }
        return sum;
    }
};
Solution::Fib Solution::f;

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
        string s = stringToString(line);
        const int nums = 10000;
        {
            boost::progress_timer timer;
            for(int i = 0; i < nums; i++){
                int ret = Solution().numDecodings0(s);
            }
            cout << "0:";
        }

        {
            boost::progress_timer timer;
            for(int i = 0; i < nums; i++){
                int ret = Solution().numDecodings1(s);
            }
            cout << "1:";
        }
    }
    return 0;
}