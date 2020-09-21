#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    int numDistinct0(string s, string t) {
        if(s.size() == 0 || t.size() == 0)
            return 0;
        vector<size_t> bagA(s.size()), bagB(s.size());
        for(size_t i = 0, sum = 0; i < s.size(); i++) {
            if(s[i] == t[0])
                sum++;
            bagA[i] = sum;
        }
        for(size_t i = 1; i < t.size(); i++) {
            bagB[i-1] = 0;
            for(size_t j = i; j < s.size(); j++) {
                bagB[j] = bagB[j-1];
                if(s[j] == t[i])
                    bagB[j] += bagA[j-1];
            }
            swap(bagA, bagB);
        }
        return bagA[bagA.size()-1];
    }
    int numDistinct(string s, string t) {
        if(s.size() == 0 || t.size() == 0)
            return 0;
        vector<size_t> bag(s.size()), bagB(s.size());
        for(size_t i = 0, sum = 0; i < s.size(); i++) {
            if(s[i] == t[0])
                sum++;
            bag[i] = sum;
        }
        size_t swaptmp;
        for(size_t i = 1; i < t.size(); i++) {
            swaptmp = bag[i-1];
            bag[i-1] = 0;
            for(size_t j = i; j < s.size(); j++) {
                swap(bag[j], swaptmp);
                if(s[j] == t[i])
                    bag[j] += bag[j-1];
                else
                    bag[j] = bag[j-1];
            }
        }
        return bag[bag.size()-1];
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        cout << Solution().numDistinct("babba", "ba") << endl;
    }
    cout << "2:" << endl;
    {
        cout << Solution().numDistinct("rabbbit", "rabbit") << endl;
    }
    cout << "3:" << endl;
    {
        cout << Solution().numDistinct("babgbag", "bag") << endl;
    }
    // cout << "4:" << endl;
    // {
    // }
    
    return 0;
}
#endif