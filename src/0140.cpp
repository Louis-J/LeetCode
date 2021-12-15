#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

//前缀树
class Solution {
    class PreTree {
        PreTree *nail[26] = {};
        bool valid = false;
    public:
        void build(string &str, size_t from = 0) {
            auto &next = nail[str[from]-'a'];
            if(!next)
                next = new PreTree{};
            if(str.size() == from+1) {
                next->valid = true;
            } else {
                next->build(str, from+1);
            }
        }
        PreTree *find(string &str, size_t &posi) {
            PreTree *it = this;
            while(posi < str.size()) {
                it = it->nail[str[posi++]-'a'];
                if(it == nullptr)
                    return nullptr;
                if(it->valid)
                    return it;
            }
            return nullptr;
        }
    };
    static inline void wordFind(PreTree &head, vector<string> &ret, string &s, size_t from, string &strhas) {
        size_t orifrom = from;
        size_t orisize = strhas.size();
        for(auto it = head.find(s, from); it != nullptr; it = it->find(s, from)) {
            if(from == s.size()) {
                strhas.insert(strhas.end(), s.begin()+orifrom, s.end());
                ret.emplace_back(strhas);
                strhas.resize(orisize);
                return;
            } else {
                strhas.insert(strhas.end(), s.begin()+orifrom, s.begin()+from);
                strhas += ' ';
                wordFind(head, ret, s, from, strhas);
                strhas.resize(orisize);
            }
        }
        return;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        PreTree head;
        //用来排除，否则超时
        bool has[26] = {};
        for(auto &str : wordDict) {
            if(str.size() != 0)
                head.build(str);
            for(auto &c : str)
                has[c-'a'] = true;
        }
        
        for(auto &c : s)
            if(!has[c-'a'])
                return vector<string>{};

        vector<string> ret;
        string strhas;
        wordFind(head, ret, s, 0, strhas);
        return ret;
    }
};

// class Solution {
//     static inline void wordFind(PreTree &head, vector<string> &ret, string &s, size_t from, string &strhas) {
//         size_t orifrom = from;
//         size_t orisize = strhas.size();
//         for(auto it = head.find(s, from); it != nullptr; it = it->find(s, from)) {
//             if(from == s.size()) {
//                 strhas.insert(strhas.end(), s.begin()+orifrom, s.end());
//                 ret.emplace_back(strhas);
//                 strhas.resize(orisize);
//                 return;
//             } else {
//                 strhas.insert(strhas.end(), s.begin()+orifrom, s.begin()+from);
//                 strhas += ' ';
//                 wordFind(head, ret, s, from, strhas);
//                 strhas.resize(orisize);
//             }
//         }
//         return;
//     }
// public:
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         unordered_map<string, int> umap;
//         string temps;
//         for(auto &str : wordDict) {
//             temps.resize(0);
//             for(size_t i = 0; i < str.size(); i++) {

//             }
//         }
//             if(str.size() != 0)
//                 head.build(str);

//         vector<string> ret;
//         string strhas;
//         wordFind(head, ret, s, 0, strhas);
//         return ret;
//     }
// };

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        cout << Solution().wordBreak("catsanddog", wordDict) << endl;
    }
    cout << " 2:" << endl;
    {
        vector<string> wordDict = {"apple", "pen", "applepen", "pine", "pineapple"};
        cout << Solution().wordBreak("pineapplepenapple", wordDict) << endl;
    }
    cout << " 3:" << endl;
    {
        vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
        cout << Solution().wordBreak("catsandog", wordDict) << endl;
    }
    cout << " 4:" << endl;
    {
        vector<string> wordDict = {"pear", "apple", "peach"};
        cout << Solution().wordBreak("applepie", wordDict) << endl;
    }
    return 0;
}
#endif