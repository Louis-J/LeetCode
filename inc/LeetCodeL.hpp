#ifndef LEETCODE_HPP
#define LEETCODE_HPP

#include <algorithm>
#include <cmath>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <string_view>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int       val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode *Create(initializer_list<int> &list);
    static ListNode *Create(initializer_list<int> &&list);
    friend ostream  &operator<<(ostream &ostr, ListNode *&);
};

inline ListNode *ListNode::Create(initializer_list<int> &list) {
    ListNode *head(new ListNode(0));
    ListNode *next(head);
    for(auto &i : list) {
        next->next = new ListNode(i);
        next       = next->next;
    }
    return head->next;
}
inline ListNode *ListNode::Create(initializer_list<int> &&list) { return ListNode::Create(list); }

struct TreeNode {
    int       val;
    TreeNode *left  = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode() { cout << "destructor of Tree : " << val << endl; }
    static TreeNode *CreatePre(initializer_list<optional<int>> &list);
    static TreeNode *CreatePre(initializer_list<optional<int>> &&list);
    static TreeNode *CreateLev(initializer_list<optional<int>> &list);
    static TreeNode *CreateLev(initializer_list<optional<int>> &&list);
    friend ostream  &operator<<(ostream &ostr, TreeNode *&);

private:
    TreeNode(initializer_list<optional<int>> &list, initializer_list<optional<int>>::iterator &&i);
};
inline TreeNode::TreeNode(initializer_list<optional<int>> &list, initializer_list<optional<int>>::iterator &&i)
    : val(**i) {
    if(i++; i == list.end() || *i == nullopt) {
        left = nullptr;
    } else {
        left = new TreeNode(list, move(i));
    }

    if(i++; i == list.end() || *i == nullopt) {
        right = nullptr;
    } else {
        right = new TreeNode(list, move(i));
    }
}
inline TreeNode *TreeNode::CreatePre(initializer_list<optional<int>> &list) {
    if(list.size() == 0 || *(list.begin()) == nullopt) {
        return nullptr;
    }
    return new TreeNode(list, list.begin());
}
inline TreeNode *TreeNode::CreatePre(initializer_list<optional<int>> &&list) { return TreeNode::CreatePre(list); }
inline TreeNode *TreeNode::CreateLev(initializer_list<optional<int>> &list) {
    if(list.size() == 0 || *(list.begin()) == nullopt) return nullptr;

    TreeNode          *head = new TreeNode(**list.begin());
    vector<TreeNode *> leva{head};
    vector<TreeNode *> levb;
    auto               i = leva.begin();
    for(auto j = (list.begin() + 1); j != list.end(); j++) {
        if(*j != nullopt) {
            (*i)->left = new TreeNode(**j);
            levb.push_back((*i)->left);
        }
        j++;
        if(j == list.end()) return head;
        if(*j != nullopt) {
            (*i)->right = new TreeNode(**j);
            levb.push_back((*i)->right);
        }
        i++;
        if(i == leva.end()) {
            leva = levb;
            // swap(leva, levb);
            levb.clear();
            i = leva.begin();
        }
    }
    return head;
}
inline TreeNode *TreeNode::CreateLev(initializer_list<optional<int>> &&list) { return TreeNode::CreateLev(list); }

struct LCPrinter {
    LCPrinter(bool printFolded) : printFolded(printFolded) {}
    inline friend ostream &operator<<(ostream &ostr, LCPrinter &p) {
        printFoldedStatic = p.printFolded;
        return ostr;
    }

    inline friend ostream &operator<<(ostream &ostr, ListNode *&l) {
        if(l == nullptr) return ostr << "(ListNode*)nullptr";
        ostr << l->val;
        if(l->next != nullptr) ostr << " -> " << l->next;
        return ostr;
    }
    inline friend ostream &operator<<(ostream &ostr, TreeNode *&t) {
        if(t == nullptr) return ostr << "(TreeNode*)nullptr";
        ostr << t->val;
        {
            stringstream sstr;
            if(t->left != nullptr) {
                sstr << "->  " << t->left;
            } else {
                sstr << "->  null\n";
            }
            bool first = true;
            for(string str; getline(sstr, str);) {
                if(first || t->right == nullptr) {
                    first = false;
                    ostr << "\t" << str << '\n';
                } else {
                    ostr << "\t|" << str << '\n';
                }
            }
        }

        {
            stringstream sstr;
            if(t->right != nullptr) {
                sstr << "\\>  " << t->right;
            }
            for(string str; getline(sstr, str);) {
                ostr << "\t" << str << '\n';
            }
        }
        return ostr;
    }

    template <typename T>
    inline friend ostream &operator<<(ostream &ostr, vector<T> &v) {
        if(LCPrinter::printFoldedStatic) {
            ostr << '{';
            stringstream sstr;
            for(auto &t : v) sstr << t << ',';
            for(string str; getline(sstr, str);) ostr << str;
            return ostr << '}';
        } else {
            ostr << "{\n";
            stringstream sstr;
            for(auto &t : v) sstr << t << ",\n";
            for(string str; getline(sstr, str);) ostr << '\t' << str << '\n';
            return ostr << '}';
        }
    }

    inline friend ostream &operator<<(ostream &ostr, vector<bool> &v) {
        if(LCPrinter::printFoldedStatic) {
            ostr << '{';
            stringstream sstr;
            for(bool t : v) sstr << (t ? "true," : "false,");
            for(string str; getline(sstr, str);) ostr << str;
            return ostr << '}';
        } else {
            ostr << "{\n";
            stringstream sstr;
            for(bool t : v) sstr << (t ? "true,\n" : "false,\n");
            for(string str; getline(sstr, str);) ostr << '\t' << str << '\n';
            return ostr << '}';
        }
    }

    template <typename T1, typename T2>
    inline friend ostream &operator<<(ostream &ostr, pair<T1, T2> &v) {
        return ostr << "Pair[" << v.first << ',' << v.second << ']';
    }

    template <typename... Ts>
    inline friend ostream &operator<<(ostream &ostr, tuple<Ts...> &v) {
        return ostr << "Tuple[" << ']';
    }

private:
    static bool printFoldedStatic;
    bool        printFolded;
};
bool LCPrinter::printFoldedStatic = false;

inline ostream &operator<<(ostream &ostr, LCPrinter &p);
inline ostream &operator<<(ostream &ostr, LCPrinter &&p) { return ostr << p; }
inline ostream &operator<<(ostream &ostr, ListNode *&l);
inline ostream &operator<<(ostream &ostr, ListNode *&&l) { return ostr << l; }
inline ostream &operator<<(ostream &ostr, TreeNode *&t);
inline ostream &operator<<(ostream &ostr, TreeNode *&&t) { return ostr << t; }
template <typename T>
inline ostream &operator<<(ostream &ostr, vector<T> &v);
template <typename T>
inline ostream &operator<<(ostream &ostr, vector<T> &&v) {
    return ostr << v;
}
inline ostream &operator<<(ostream &ostr, vector<bool> &v);
inline ostream &operator<<(ostream &ostr, vector<bool> &&v) { return ostr << v; }
template <typename T1, typename T2>
inline ostream &operator<<(ostream &ostr, pair<T1, T2> &v);
template <typename T1, typename T2>
inline ostream &operator<<(ostream &ostr, pair<T1, T2> &&v) {
    return ostr << v;
}
template <typename... Ts>
inline ostream &operator<<(ostream &ostr, tuple<Ts...> &v);
template <typename... Ts>
inline ostream &operator<<(ostream &ostr, tuple<Ts...> &&v) {
    return ostr << v;
}

#endif
