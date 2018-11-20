#include <LeetCode.hpp>

int main()
{
    shared_ptr<ListNode> l(ListNode::Create({1,2,3,4,5}));
    cout << l << endl;

    shared_ptr<TreeNode> t(TreeNode::Create({1,2,4,8,nullopt,nullopt,9,nullopt,nullopt,nullopt,3,nullopt,nullopt}));
    cout << t << endl;

    t->left->left = shared_ptr<TreeNode>(nullptr);

    cout <<"\nhaha\n";
    cout << t << endl;
    cout <<"\nhaha\n";

    cout << TreeNode::Create({100,200,nullopt,nullopt,300,nullopt,nullopt}) << endl;
    return 0;
}