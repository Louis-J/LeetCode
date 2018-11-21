#ifndef LEETCODE_HPP
#define LEETCODE_HPP
 
#include <iostream>
#include <sstream>

#include <algorithm>
#include <memory>
#include <functional>
#include <optional>

#include <string>
#include <vector>

using namespace std;


struct ListNode
{
    int val;
    shared_ptr<ListNode> next;
    ListNode(int x) : val(x), next(nullptr) {}
    ~ListNode(){cout << "destructor of List : " << val <<endl;}
    static shared_ptr<ListNode> Create(initializer_list<int>& list);
    static shared_ptr<ListNode> Create(initializer_list<int>&& list);
    friend ostream& operator<<(ostream& ostr, shared_ptr<ListNode>&);
};
inline shared_ptr<ListNode> ListNode::Create(initializer_list<int>& list) {
    shared_ptr<ListNode> head(new ListNode(0));
    shared_ptr<ListNode> next(head);
    for(auto& i : list){
        next->next = make_shared<ListNode>(i);
        next = next->next;
    }
    return head->next;
}
inline shared_ptr<ListNode> ListNode::Create(initializer_list<int>&& list) {
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
    shared_ptr<TreeNode> left;
    shared_ptr<TreeNode> right;
    TreeNode(int x=0) : val(x), left(nullptr), right(nullptr) {}
    ~TreeNode(){cout << "destructor of Tree : " << val <<endl;}
    static shared_ptr<TreeNode> Create(initializer_list<optional<int>>& list);
    static shared_ptr<TreeNode> Create(initializer_list<optional<int>>&& list);
    friend ostream& operator<<(ostream& ostr, shared_ptr<TreeNode>&);
private:
    TreeNode(initializer_list<optional<int>>& list, initializer_list<optional<int>>::iterator&& i);
};
inline TreeNode::TreeNode(initializer_list<optional<int>>& list, initializer_list<optional<int>>::iterator&& i) : val(**i){
    if(i++; i == list.end() || *i == nullopt){
        left = nullptr;
    }else{
        left = shared_ptr<TreeNode>(new TreeNode(list, move(i)));
    }

    if(i++; i == list.end() || *i == nullopt){
        right = nullptr;
    }else{
        right = shared_ptr<TreeNode>(new TreeNode(list, move(i)));
    }
}
inline shared_ptr<TreeNode> TreeNode::Create(initializer_list<optional<int>>& list){
    if(list.size() == 0 || *(list.begin()) == nullopt){
        return shared_ptr<TreeNode>(nullptr);
    }
    return shared_ptr<TreeNode>(new TreeNode(list, list.begin()));
}
inline shared_ptr<TreeNode> TreeNode::Create(initializer_list<optional<int>>&& list){
    return TreeNode::Create(list);
}
inline ostream& operator<<(ostream& ostr, shared_ptr<TreeNode>& t) {
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
inline ostream& operator<<(ostream& ostr, shared_ptr<TreeNode>&& t) {
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

#endif