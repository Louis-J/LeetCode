#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

//递归
class Solution0 {
    string news;
    int digui(size_t b, size_t e, char c = 0) {
        if(b == e)
            return news[b] != c;

        if(news[b] == c)
            return digui(b+1, e, c);
        else if(news[e] == c)
            return digui(b, e-1, c);

        return 1+min({digui(b+1, e, c), digui(b+1, e, news[b]), digui(b, e-1, c), digui(b, e-1, news[e])});
    }
public:
    int strangePrinter(string s) {
        if(s.size() <= 1)
            return s.size();
        // string news(s[0]);
        // news.emplace_back(s[0]);
        news += s[0];
        for(int i = 1; i < s.size(); i++)
            if(s[i] != s[i-1])
                news += s[i];
        if(news.size() <= 2)
            return news.size();

        return digui(0, news.size()-1);
    }
};

//动规
class Solution {
    string news;
    int digui(size_t b, size_t e, char c = 0) {
        if(b == e)
            return news[b] != c;

        if(news[b] == c)
            return digui(b+1, e, c);
        else if(news[e] == c)
            return digui(b, e-1, c);

        return 1+min({digui(b+1, e, c), digui(b+1, e, news[b]), digui(b, e-1, c), digui(b, e-1, news[e])});
    }
public:
    int strangePrinter(string s) {
        if(s.size() <= 1)
            return s.size();
        string news(s[0]);
        news += s[0];
        for(int i = 1; i < s.size(); i++)
            if(s[i] != s[i-1])
                news += s[i];
        if(news.size() <= 2)
            return news.size();

        return digui(0, news.size()-1);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        cout << Solution().strangePrinter("aaabbb") << endl;
    }
    cout << " 2:" << endl;
    {
        cout << Solution().strangePrinter("aba") << endl;
    }
    cout << " 3:" << endl;
    {
        cout << Solution().strangePrinter("abcdabcdabcdabcd") << endl;
    }
    return 0;
}
#endif