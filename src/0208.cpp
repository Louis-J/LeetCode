#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Trie0 {
    struct TrieNode {
        bool      haveThere = false;
        string    before;
        TrieNode *next[26] = {};
        TrieNode() {}
        TrieNode(string_view word) : haveThere(true), before(word) {}
        TrieNode(TrieNode &lastNode, int i) : haveThere(true), before(lastNode.before.substr(i)) {
            for(int j = 0; j < 26; j++) {
                next[j]          = lastNode.next[j];
                lastNode.next[j] = nullptr;
            }
            haveThere = lastNode.haveThere;
        }
    };

    TrieNode head;

public:
    void insert(string word) {
        TrieNode   *node = &head;
        string_view strv = word;
        while(true) {
            int i = 0;
            for(; i != min(node->before.size(), strv.size()); i++) {
                if(node->before[i] != strv[i]) {
                    node->next[node->before[i] - 'a'] = new TrieNode(*node, i + 1);
                    node->next[strv[i] - 'a']         = new TrieNode(strv.substr(i + 1));
                    node->haveThere                   = false;
                    node->before.resize(i);
                    return;
                }
            }
            if(node->before.size() == strv.size()) {
                node->haveThere = true;
                return;
            } else if(node->before.size() < strv.size()) {
                if(node->next[strv[i] - 'a'] == nullptr) {
                    node->next[strv[i] - 'a'] = new TrieNode(strv.substr(i + 1));
                    return;
                } else {
                    node = node->next[strv[i] - 'a'];
                    strv = strv.substr(i + 1);
                }
            } else {
                node->next[node->before[i] - 'a'] = new TrieNode(*node, i + 1);
                node->haveThere                   = true;
                node->before.resize(i);
                return;
            }
        }
    }

    bool search(string word) {
        TrieNode   *node = &head;
        string_view strv = word;
        while(true) {
            int i = 0;
            for(; i != min(node->before.size(), strv.size()); i++) {
                if(node->before[i] != strv[i]) return false;
            }
            if(node->before.size() == strv.size()) {
                return node->haveThere;
            } else if(node->before.size() < strv.size()) {
                if(node->next[strv[i] - 'a'] == nullptr) {
                    return false;
                } else {
                    node = node->next[strv[i] - 'a'];
                    strv = strv.substr(i + 1);
                }
            } else
                return false;
        }
    }

    bool startsWith(string prefix) {
        TrieNode   *node = &head;
        string_view strv = prefix;
        while(true) {
            int i = 0;
            for(; i != min(node->before.size(), strv.size()); i++) {
                if(node->before[i] != strv[i]) return false;
            }
            if(node->before.size() >= strv.size()) {
                return true;
            } else if(node->next[strv[i] - 'a'] == nullptr) {
                return false;
            } else {
                node = node->next[strv[i] - 'a'];
                strv = strv.substr(i + 1);
            }
        }
    }
};
class Trie {
    struct TrieNode {
        bool      haveThere;
        TrieNode *next[26] = {};
        TrieNode() : haveThere(false) {}
    };

    TrieNode head;

public:
    void insert(string word) {
        TrieNode *node = &head;
        for(int i = 0; i != word.size(); i++) {
            if(node->next[word[i] - 'a'] == nullptr) {
                auto newNode              = new TrieNode();
                node->next[word[i] - 'a'] = newNode;
                node                      = newNode;
            } else {
                node = node->next[word[i] - 'a'];
            }
        }
        node->haveThere = true;
    }

    bool search(string word) {
        TrieNode *node = &head;
        for(int i = 0; i != word.size(); i++) {
            if(node->next[word[i] - 'a'] == nullptr)
                return false;
            node = node->next[word[i] - 'a'];
        }
        return node->haveThere;
    }

    bool startsWith(string prefix) {
        TrieNode *node = &head;
        for(int i = 0; i != prefix.size(); i++) {
            if(node->next[prefix[i] - 'a'] == nullptr)
                return false;
            node = node->next[prefix[i] - 'a'];
        }
        return true;
    }
};

#ifdef LEETCODE
int main() {
    // cout << "1:" << endl;
    // {
    //     Trie trie;
    //     trie.insert("apple");
    //     cout << trie.search("apple") << endl;    // 返回 True
    //     cout << trie.search("app") << endl;      // 返回 False
    //     cout << trie.startsWith("app") << endl;  // 返回 True
    //     trie.insert("app");
    //     cout << trie.search("app") << endl;  // 返回 True
    // }
    // cout << "2:" << endl;
    // {
    //     Trie trie;
    //     trie.insert("ab");
    //     cout << trie.search("a") << endl;      // 返回 0
    //     cout << trie.startsWith("a") << endl;  // 返回 1
    // }
    // cout << "3:" << endl;
    // {
    //     Trie trie;
    //     trie.insert("app");
    //     trie.insert("apple");
    //     trie.insert("beer");
    //     trie.insert("add");
    //     cout << trie.search("a") << endl;      // 返回 0
    //     cout << trie.startsWith("a") << endl;  // 返回 1
    // }
    cout << "4:" << endl;
    {
        Trie trie;
        trie.insert("apple");
        cout << trie.search("apple") << endl;    // 返回 1
        cout << trie.search("app") << endl;      // 返回 0
        cout << trie.startsWith("app") << endl;  // 返回 1
        trie.insert("app");
        cout << trie.search("app") << endl;  // 返回 1
    }
    return 0;
}
#endif