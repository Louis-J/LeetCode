#ifndef LEETCODE_HPP
#define LEETCODE_HPP
 
#include <iostream>
#include <sstream>
#include <initializer_list>

#include <algorithm>
#include <memory>
#include <cmath>
#include <functional>
#include <optional>

#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    static ListNode *Create(initializer_list<int>& list);
    static ListNode *Create(initializer_list<int>&& list);
    friend ostream& operator<<(ostream& ostr, shared_ptr<ListNode>&);
};

inline ListNode *ListNode::Create(initializer_list<int>& list) {
    ListNode *head(new ListNode(0));
    ListNode *next(head);
    for(auto& i : list){
        next->next = new ListNode(i);
        next = next->next;
    }
    return head->next;
}
inline ListNode *ListNode::Create(initializer_list<int>&& list) {
    return ListNode::Create(list);
}
inline ostream& operator<<(ostream& ostr, shared_ptr<ListNode>& l) {
    ostr << l->val;
    if(l->next != nullptr)
    ostr << " -> " << l->next;
    return ostr;
}
inline ostream& operator<<(ostream& ostr, shared_ptr<ListNode>&& l) {
    return ostr << l;
}


struct TreeNode {
    int val;
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
    TreeNode(int x=0) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode(){cout << "destructor of Tree : " << val <<endl;}
    static TreeNode *CreatePre(initializer_list<optional<int>>& list);
    static TreeNode *CreatePre(initializer_list<optional<int>>&& list);
    static TreeNode *CreateLev(initializer_list<optional<int>>& list);
    static TreeNode *CreateLev(initializer_list<optional<int>>&& list);
    friend ostream& operator<<(ostream& ostr, TreeNode*&);
private:
    TreeNode(initializer_list<optional<int>>& list, initializer_list<optional<int>>::iterator&& i);
};
inline TreeNode::TreeNode(initializer_list<optional<int>>& list, initializer_list<optional<int>>::iterator&& i) : val(**i) {
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
inline TreeNode *TreeNode::CreatePre(initializer_list<optional<int>>& list){
    if(list.size() == 0 || *(list.begin()) == nullopt){
        return nullptr;
    }
    return new TreeNode(list, list.begin());
}
inline TreeNode *TreeNode::CreatePre(initializer_list<optional<int>>&& list){
    return TreeNode::CreatePre(list);
}
inline TreeNode *TreeNode::CreateLev(initializer_list<optional<int>>& list){
    if(list.size() == 0 || *(list.begin()) == nullopt){
        return nullptr;
    }
    TreeNode *head = new TreeNode(**list.begin());
    vector<TreeNode*> leva{head};
    vector<TreeNode*> levb;
    auto i = leva.begin();
    for(auto j = (list.begin()+1); j != list.end(); j++) {
        if(*j != nullopt) {
            (*i)->left = new TreeNode(**j);
            levb.push_back((*i)->left);
        }
        j++;
        if(j == list.end())
            return head;
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
inline TreeNode *TreeNode::CreateLev(initializer_list<optional<int>>&& list){
    return TreeNode::CreateLev(list);
}
inline ostream& operator<<(ostream& ostr, TreeNode*& t) {
    if(t == nullptr){
        return ostr << "nullptr";
    }
    ostr << t->val;
    {
        stringstream sstr;
        if(t->left != nullptr){
            sstr << "->  " << t->left;
        }
        else{
            sstr << "->  null\n";
        }
        bool first = true;
        for(string str; getline(sstr, str); ){
            if(first || t->right == nullptr){
                first = false;
                ostr << "\t" << str << '\n';
            }else{
                ostr << "\t|" << str << '\n';
            }
        }
    }

    {
        stringstream sstr;
        if(t->right != nullptr){
            sstr << "\\>  " << t->right;
        }
        for(string str; getline(sstr, str); ){
            ostr << "\t" << str << '\n';
        }
    }
    return ostr;
}
inline ostream& operator<<(ostream& ostr, TreeNode*&& t) {
    return ostr << t;
}


//输出数组内容，可输出多级嵌套的数组
template<typename T>
inline ostream& operator<<(ostream& ostr, vector<T>& v) {
    ostr << "{\n";
    stringstream sstr;
    for(auto& t : v){
        sstr << t << ",\n";
    }
    for(string str; getline(sstr, str); ){
        ostr << "\t" << str << '\n';
    }
    return ostr << "}";
}
template<typename T>
inline ostream& operator<<(ostream& ostr, vector<T>&& v) {
    return ostr << v;
}

/*
//ListNode输入的各函数
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

int stringToInteger(string input) {
    return stoi(input);
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

template <class Solution, typename FUNC_t>
void InputListNode_Num(FUNC_t func) {
    string line;
    while (getline(cin, line)) {
        ListNode* head = stringToListNode(line);
        getline(cin, line);
        int k = stringToInteger(line);

        ListNode* ret = (Solution().*func)(head, k);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
}*/

#endif