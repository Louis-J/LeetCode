#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
#include<assert.h>

using namespace std;

class Solution {
public:
    //递归
    bool isMatch0(string s, string p) {
        if (p.empty()) return s.empty();

        bool first_match = (!s.empty() && (p[0] == s[0] || p[0] == '.'));

        if(p.length() >= 2 && p[1] == '*') {
            return (isMatch0(s, p.substr(2)) || (first_match && isMatch0(s.substr(1), p)));
        } else {
            return first_match && isMatch0(s.substr(1), p.substr(1));
        }
    }
    //类似背包
    bool isMatch1(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp( m + 1, vector<bool> ( n + 1, false ) );
        dp[0][0] = true;
        for( int i = 0; i <= m; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                if( p[j - 1] == '*' )
                    dp[i][j] = dp[i][j - 2] || ( i > 0 && ( s[i - 1] == p[j - 2] || p[j - 2] == '.' ) && dp[i - 1][j] );
                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && ( s[i - 1] == p[j - 1] || p[j - 1] == '.' );
            }
        }
        return dp[m][n];
    }
    //优化了1
    bool isMatch2(string s, string p) {
        const auto m = s.length()+1;
        const auto n = p.length()+1;
        if(m == 0) {
            return n == 0 || p == ".*";
        } else if(n == 0) {
            return false;
        }
        auto dp = new bool[m*n];
        dp[0*n+0] = true;
        for(int i = 1; i < m; i++)
            dp[i*n+0] = false;
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(p[j-1] == '*')
                    dp[i*n+j] = j > 1 && (dp[i*n+j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[(i-1)*n+j]));
                else
                    dp[i*n+j] = i > 0 && dp[(i-1)*n+j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            }
        }
        return dp[m*n-1];
    }
};

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    for(string s, p; cin >> s >> p;) {
        cout << boolToString(Solution().isMatch0(s, p)) << endl;
        cout << boolToString(Solution().isMatch1(s, p)) << endl;
        cout << boolToString(Solution().isMatch2(s, p)) << endl;
    }
    return 0;
}
//真是个大傻逼，其实题目本身很简单，只是自己想复杂了。匹配万变不离其宗:单向顺序，不论是