#include <iostream>
#include <assert.h>
#include <boost/progress.hpp>
#include <sstream>
#include <vector>

using namespace std;

class Solution {
public:
    //暴力法，复杂度为O(n^3)
    string longestPalindrome0(string &s) {
        for(int length = s.size();length > 0;length --){
            for(int bgn = 0;bgn <= s.size() - length;bgn ++){
                bool ispalindromic = true;
                for(int b = bgn, e = b + length - 1;b < e;b ++, e --){
                    if(s[b] != s[e]){
                        ispalindromic = false;
                        break;
                    }
                }
                if(ispalindromic){
                    return s.substr(bgn, length);
                }
            }
        }
        return string("");
    }

    //选定中间位算长度，复杂度为O(n^2)
    string longestPalindrome1(string &s) {
        int maxLen = 0, index = 0;
        for(int middle = 0;middle < s.size();middle ++){
            int len = 0;
            //奇数子串
            for(len = 0;middle - len >= 0 && middle + len < s.size() - 1 && s[middle - len] == s[middle + len];len ++){}
            if(maxLen < len * 2 - 1){
                maxLen = len * 2 - 1;
                index = middle - len + 1;
            }
            //偶数子串
            for(len = 0;middle - len >= 0 && middle + len < s.size() - 2 && s[middle - len] == s[middle + len + 1];len ++){}
            if(maxLen < len * 2){
                maxLen = len * 2;
                index = middle - len + 1;
            }
        }
        return s.substr(index, maxLen);
    }

    //预处理字符串，abc预处理后变成$#a#b#c#^
    string preProcess(const string &s)
    {
        int n = s.size();
        string res;
        res.push_back('$');//把$放到字符串头部
        res.push_back('#');//以#作为原来字符串中每个字符的间隔
        for(int i = 0; i < n; i++)
        {
            res.push_back(s[i]);
            res.push_back('#');
        }
        res.push_back('^');//以^作为字符串的结尾
        return res;
    }
    string longestPalindrome2(string &s) {
        if (s.size() < 2)
            return s;

        //Manncher算法 ，o（n）
        string str = preProcess(s);

        int n = str.size();
        int id = 0, mx = 0;
        vector<int>p(n, 0);
        int maxLen = 0, index = 0;
        for(int i = 1; i < n - 1; i++){
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
            if(mx <= i || (mx > i && p[2*id-i] == mx - i)) //根据正文斜体部分的注释，这里可要可不要
            while(str[i+p[i]] == str[i-p[i]])p[i]++;

            if(i + p[i] > mx){
                mx = i + p[i];
                id = i;
            }

            if(p[i] > maxLen){
                maxLen = p[i];
                index = i;
            }
        }

        return s.substr((index - maxLen)/2, maxLen-1);
    }
    string longestPalindrome3(string &s) {
        if (s.size() < 2)
            return s;

        // 添加头^尾$两个不同的字符用于消除边界判断
        string str = "^" + s + "$";

        int n = s.size() * 2 + 1 + 2;
        int id = 0, mx = 0;
        vector<int>p(n, 0);
        int maxLen = 0, index = 0;
        for (int i = 1; i < n - 1; i++) {
            p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;

            // 基于当前点为中心扩展寻找回文
            //if(mx <= i || (mx > i && p[2*id-i] == mx - i))
            {
                int left = i - p[i];
                int right = i + p[i];
                while (str[(left + 1) / 2] == str[right / 2]) {
                    p[i]++;
                    left--;
                    right++;
                }
            }

            if (i + p[i] > mx) {
                mx = i + p[i];
                id = i;
            }
            if (p[i] > maxLen) {
                maxLen = p[i];
                index = i;
            }
        }
        return s.substr((index - maxLen)/2, maxLen - 1);
    }
    string longestPalindrome(string s) {
        return longestPalindrome3(s);
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
    int i = 1000;
    stringstream output;
    stringstream timestat;
    boost::progress_timer timer;
    boost::progress_display pd(7*i);

    string line;
    while (getline(cin, line)) {
        boost::progress_timer mintimer(timestat);
        string s = stringToString(line);
        string ret;

        for(int j=0;j<i;j++){
            ret = Solution().longestPalindrome(s);
            ++pd;
        }

        string out = (ret);
        output << out << endl;
        timestat << "size = " << s.size() << " , maxlength = " << out.size() << " : ";
    }
    cout << output.str() << "Part time:\n" << timestat.str() << "Full time:\n";
    return 0;
}