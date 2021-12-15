#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    int maxProduct(vector<string>& words) {
        pair<int, int> tag[words.size()];
        fill(tag, tag + words.size(), pair<int, int>{0, 0});
        for(int i = 0; i < words.size(); i++) {
            for(char c: words[i]) {
                tag[i].first |= (1 << (c - 'a'));
            }
            tag[i].second = words[i].size();
        }

        int p = 0;
        for(int i = 1; i < words.size(); i++) {
            for(int j = 0; j < i; j++) {
                if((tag[i].first & tag[j].first) == 0)
                    p = max(p, tag[i].second * tag[j].second);
            }
        }
        return p;
    }
    // int maxProduct(vector<string>& words) {
    //     unordered_map<int, int> hash;
    //     int ans = 0;
    //     for(const string & word : words) {
    //         int mask = 0, size = word.size();
    //         for(const char & ch : word) {
    //             mask |= 1 << (ch - 'a');
    //         }
    //         hash[mask] = max(hash[mask], size);
    //         for(const auto & [h_mask, h_len] : hash) {
    //             if(!(h_mask & mask))
    //                 ans = max(ans, size * h_len);
    //         }
    //     }
    //     return ans;
    // }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
        cout << Solution().maxProduct(words) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<string> words = {"a","ab","abc","d","cd","bcd","abcd"};
        cout << Solution().maxProduct(words) << endl;
    }
    return 0;
}
#endif