#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

// 看题解
class StreamChecker0 {
    struct LinkNode {
        bool      nail     = false;
        LinkNode *next[26] = {nullptr};

    public:
        void addNext(string_view strv) {
            if(strv.size() == 0)
                nail = true;
            else {
                if(next[strv[0] - 'a'] == nullptr) next[strv[0] - 'a'] = new LinkNode();
                next[strv[0] - 'a']->addNext(strv.substr(1));
            }
        }

        LinkNode *getNext(char letter) { return next[letter - 'a']; }

        bool isNail() { return nail; }
    };

    LinkNode head;

    deque<LinkNode *> que;

public:
    StreamChecker0(vector<string> &words) {
        for(auto &word : words) head.addNext(word);
    }

    bool query(char letter) {
        bool ret = false;

        for(auto it = que.begin(); it != que.end();) {
            auto &node     = *it;
            auto  nextNode = node->getNext(letter);
            if(nextNode != nullptr) {
                if(nextNode->isNail()) ret = true;
                node = nextNode;
                it++;
            } else {
                it = que.erase(it);
            }
        }
        auto nextNode = head.getNext(letter);
        if(nextNode != nullptr) {
            if(nextNode->isNail()) ret = true;
            que.emplace_back(nextNode);
        }

        return ret;
    }
};

class StreamChecker {
    struct LinkNode {
        bool      nail     = false;
        LinkNode *next[26] = {nullptr};

    public:
        void addNext(string_view strv) {
            if(strv.size() == 0)
                nail = true;
            else {
                if(next[strv[0] - 'a'] == nullptr) next[strv[0] - 'a'] = new LinkNode();
                next[strv[0] - 'a']->addNext(strv.substr(1));
            }
        }

        LinkNode *getNext(char letter) { return next[letter - 'a']; }

        bool isNail() { return nail; }
    };

    LinkNode head;

    deque<LinkNode *> que;

public:
    StreamChecker(vector<string> &words) {
        for(auto &word : words) head.addNext(word);
    }

    bool query(char letter) {
        bool ret = false;

        for(auto it = que.begin(); it != que.end();) {
            auto &node     = *it;
            auto  nextNode = node->getNext(letter);
            if(nextNode != nullptr) {
                if(nextNode->isNail()) ret = true;
                node = nextNode;
                it++;
            } else {
                it = que.erase(it);
            }
        }
        auto nextNode = head.getNext(letter);
        if(nextNode != nullptr) {
            if(nextNode->isNail()) ret = true;
            que.emplace_back(nextNode);
        }

        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        vector<string> words = {"cd", "f", "kl"};
        StreamChecker  streamChecker(words);

        cout << streamChecker.query('a') << false << endl;
        cout << streamChecker.query('b') << false << endl;
        cout << streamChecker.query('c') << false << endl;
        cout << streamChecker.query('d') << true << endl;  //，因为 'cd' 在字词表中
        cout << streamChecker.query('e') << false << endl;
        cout << streamChecker.query('f') << true << endl;  //，因为 'f' 在字词表中
        cout << streamChecker.query('g') << false << endl;
        cout << streamChecker.query('h') << false << endl;
        cout << streamChecker.query('i') << false << endl;
        cout << streamChecker.query('j') << false << endl;
        cout << streamChecker.query('k') << false << endl;
        cout << streamChecker.query('l') << true << endl;  //，因为 'kl' 在字词表中。
    }
    // cout << " 2:" << endl;
    // {
    // }
    // cout << " 3:" << endl;
    // {
    // }
    // cout << " 4:" << endl;
    // {
    // }
    return 0;
}
#endif