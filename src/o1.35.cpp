#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Node {
public:
    int   val;
    Node *next;
    Node *random;

    Node(int _val) {
        val    = _val;
        next   = NULL;
        random = NULL;
    }
    inline friend ostream &operator<<(ostream &ostr, Node *&n) {
        if(n == nullptr) return ostr << "(Node*)null";
        ostr << n->val;
        {
            stringstream sstr;
            if(n->next != nullptr) {
                sstr << "->  " << n->next;
            } else {
                sstr << "->  null\n";
            }
            bool first = true;
            for(string str; getline(sstr, str);) {
                if(first || n->random == nullptr) {
                    first = false;
                    ostr << "\t" << str << '\n';
                } else {
                    ostr << "\t|" << str << '\n';
                }
            }
        }

        {
            stringstream sstr;
            if(n->random != nullptr) {
                sstr << "\\>  " << n->random;
            }
            for(string str; getline(sstr, str);) {
                ostr << "\t" << str << '\n';
            }
        }
        return ostr;
    }
    inline friend ostream &operator<<(ostream &ostr, Node *&&n) { return ostr << n; }
    inline static Node *   Create(initializer_list<pair<int, optional<int>>> &list) {
        Node **nodes = new Node *[list.size()];

        for(int i = 0; i < list.size(); i++) {
            auto listI = list.begin() + i;
            nodes[i]   = new Node(listI->first);
            if(i != 0) nodes[i - 1]->next = nodes[i];
            if(i == list.size() - 1) nodes[i]->next = nullptr;
        }
        for(int i = 0; i < list.size(); i++) {
            auto listI = list.begin() + i;
            if(listI->second == nullopt)
                nodes[i]->random = nullptr;
            else
                nodes[i]->random = nodes[*listI->second];
        }

        return nodes[0];
    }
    inline static Node *Create(initializer_list<pair<int, optional<int>>> &&list) { return Create(list); }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if(head == nullptr) return nullptr;
        unordered_map<Node *, Node *> nodeMap;
        for(auto i = head; i != nullptr; i = i->next) {
            auto newNode    = new Node(i->val);
            newNode->next   = i->next;
            newNode->random = i->random;
            nodeMap.emplace(i, newNode);
        }

        auto newHead = nodeMap.at(head);
        for(auto i = newHead; i != nullptr; i = i->next) {
            if(i->next != nullptr) i->next = nodeMap.at(i->next);
            if(i->random != nullptr) i->random = nodeMap.at(i->random);
        }
        return newHead;
    }
};

#ifdef LEETCODE
int main() {
    cout << LCPrinter(true);
    cout << " 1:" << endl;
    {
        Node *head = Node::Create({{7, nullopt}, {13, 0}, {11, 4}, {10, 2}, {1, 0}});
        cout << Solution().copyRandomList(head) << endl;
    }
    cout << " 2:" << endl;
    {}
    return 0;
}
#endif