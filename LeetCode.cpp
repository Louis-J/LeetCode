#include <LeetCode.hpp>

int main()
{
    vector<string> vs{"a", "b"};
    vector<vector<string>> vvs{{"1a", "1b"},{"2a", "2b"}};
    vector<vector<vector<string>>> vvvs{{{"1a"}, {"1b"}},{{"2a"}, {"2b"}}};
    cout << vs << endl << vvs << endl << vvvs << endl;

    vector<int> vi{1, 2};
    vector<vector<int>> vvi{{11, 12},{21, 22}};
    vector<vector<vector<int>>> vvvi{{{11}, {12}},{{21}, {22}}};
    cout << vi << endl << vvi << endl << vvvi << endl;
	
	
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