#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    //最简单办法,看起来没问题，但复杂度过高超时了
    bool wordBreak0(string s, vector<string> &wordDict) {
        auto have = [](string &a, string &b) {
            if(a.size() < b.size()) {
                return false;
            }
            for(size_t i = 0; i < b.size(); i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        };

        function<bool(string &&)> recursion;
        recursion = [&](string &&now) {
            if(now == "") {
                return true;
            }
            for(auto &w : wordDict) {
                if(have(now, w) && recursion(now.substr(w.size(), now.size() - w.size()))) {
                    return true;
                }
            }
            return false;
        };
        return recursion(move(s));
    }
    //加个排序，估计差不了太多，果然也超时了
    bool wordBreak1(string s, vector<string> &wordDict) {
        sort(wordDict.begin(), wordDict.end());
        auto have = [](string &a, string &b) {
            if(a.size() < b.size()) {
                return false;
            }
            for(size_t i = 0; i < b.size(); i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        };

        function<bool(string &&)> recursion;
        recursion = [&](string &&now) {
            if(now == "") {
                return true;
            }
            for(auto &w : wordDict) {
                if(have(now, w) && recursion(now.substr(w.size(), now.size() - w.size()))) {
                    return true;
                }
            }
            return false;
        };
        return recursion(move(s));
    }
    //完全改革，使用multiset，再自定义数据类型，失败，不知哪里出错重载小于号失败
    class stringT : public string {
    public:
        stringT() : string() {}
        stringT(const stringT &s) : string(s) {}
        stringT(const char *s) : string(s) {}
        stringT(string &s) : string(s) {}
        stringT(string &&s) : string(s) {}

        int compare(const basic_string &str) const {
            const size_type len = std::min(this->size(), str.size());

            int r = traits_type::compare(data(), str.data(), len);
            if(!r) r = str.size() - this->size();
            return r;
        }
        int compare(const stringT &str) const {
            const size_type len = std::min(this->size(), str.size());

            int r = traits_type::compare(data(), str.data(), len);
            if(!r) r = str.size() - this->size();
            return r;
        }
        bool operator<(const basic_string &str) { return compare(str) < 0; }
        bool operator<(const stringT &str) { return compare(str) < 0; }
    };
    bool wordBreak2(string s, vector<string> &wordDict) {
        multiset<string> dict;
        for(auto &w : wordDict) {
            dict.emplace(stringT(move(w)));
        }
        for(auto &w : dict) {
            cout << w << endl;
        }
        function<bool(stringT &&)> recursion;
        recursion = [&](stringT &&now) {
            if(now.size() == 0) {
                return true;
            }
            for(auto w = dict.lower_bound(now); w != dict.upper_bound(now); w++) {
                if(now.size() >= w->size() && recursion(now.substr(w->size(), now.size() - w->size()))) {
                    return true;
                }
            }
            return false;
        };
        return recursion(stringT(s));
    }
    //做了好久发现不对，没满足stl排序函数的原则。想了一下反向排序可能有用
    //仔细求证发现完全是想法错了。无法无法满足stl排序函数的原则下创造一个a==aa==aaa的排序准则。需要一些其他方法
    bool wordBreak3(string s, vector<string> &wordDict) {
        multiset<string, greater<string>> dict(wordDict.begin(), wordDict.end());

        for(auto &w : dict) {
            cout << w << endl;
        }
        function<bool(string &&)> recursion;
        recursion = [&](string &&now) {
            if(now.size() == 0) {
                return true;
            }
            for(auto w = dict.lower_bound(now); w != dict.upper_bound(now.substr(0, 1)); w++) {
                if(now.size() >= w->size() && recursion(now.substr(w->size(), now.size() - w->size()))) {
                    return true;
                }
            }
            return false;
        };
        return recursion(string(s));
    }
    //验证是否s和wordDict分别能否被覆盖，剔除无法覆盖的部分
    bool wordBreak4(string s, vector<string> &wordDict) {
        multiset<string, greater<string>> dict;
        vector<bool>                      ifused(s.size(), false);
        for(auto &w : wordDict) {
            if(auto from = s.find(w); from != string::npos) {
                dict.emplace(w);
            }
        }
        auto have = [](string &a, string &b) {
            if(a.size() < b.size()) {
                return false;
            }
            for(size_t i = 0; i < b.size(); i++) {
                if(a[i] != b[i]) {
                    return false;
                }
            }
            return true;
        };

        function<bool(string &&)> recursion;
        recursion = [&](string &&now) {
            if(now == "") {
                return true;
            }
            for(auto &w : wordDict) {
                if(have(now, w) && recursion(now.substr(w.size(), now.size() - w.size()))) {
                    return true;
                }
            }
            return false;
        };
        return recursion(move(s));
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        vector<uint8_t> dp(s.size(), 0);

        string_view                strvs(s);
        unordered_set<string_view> wordSet;

        for(auto &str : wordDict) wordSet.emplace(str);

        for(int i = 0; i < s.size(); i++) {
            if(wordSet.contains(strvs.substr(0, i + 1)))
                dp[i] = true;
            else
                for(int j = 0; j < i; j++) {
                    if(dp[j] && wordSet.find(strvs.substr(j + 1, i - j)) != wordSet.end()) {
                        dp[i] = true;
                        break;
                    }
                }
        }
        return dp[s.size() - 1];
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        string         s        = "bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcd";
        vector<string> wordDict = {"b", "bb", "bbb", "bbbb", "c", "bc", "bbc", "bbbc", "a", "ba", "bba", "bbba"};

        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    cout << " 2:" << endl;
    {
        string         s        = "catsandog";
        vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};

        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    cout << " 3:" << endl;
    {
        string         s        = "leetcode";
        vector<string> wordDict = {"leet", "code"};

        cout << Solution().wordBreak(s, wordDict) << endl;
    }
    return 0;
}
#endif