#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    void reverseString0(vector<char>& s) {
        if(s.size() <= 1)
            return;
        const size_t n2 = s.size()/2;
        char *b = &s[0], *e = &s[s.size()-1];
        const char *half = &s[n2];
        for(; b != half; b++, e--)
            swap(*b, *e);
    }
    void reverseString(vector<char>& s) {
        for(size_t i = 0; i < s.size()/2; i++)
            swap(s[i], s[s.size()-1-i]);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        vector<char> s = {'h', 'e', 'l', 'l', 'o'};
        Solution().reverseString(s);
        cout << s << endl;
    }
    cout << "2:" << endl;
    {
        vector<char> s = {'h', 'e'};
        Solution().reverseString(s);
        cout << s << endl;
    }
    // cout << "3:" << endl;
    // {
    // }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif