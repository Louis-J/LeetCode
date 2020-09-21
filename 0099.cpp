#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    vector<TreeNode*> errors;
    void findErrors(TreeNode *root, TreeNode *l=nullptr, TreeNode *r=nullptr) {
        if(l != nullptr && l->val >= root->val) {
            errors.emplace_back(l);
            errors.emplace_back(root);
        }
        if(r != nullptr && r->val <= root->val) {
            errors.emplace_back(r);
            errors.emplace_back(root);
        }
        if(root->left != nullptr)
            findErrors(root->left, l, root);
        if(root->right != nullptr)
            findErrors(root->right, root, r);
    }
public:
    void recoverTree(TreeNode *root) {
        findErrors(root);
        // for(auto &i : errors)
        //     cout << i->val << endl;
        swap(errors[0]->val, errors[1]->val);
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        auto t = TreeNode::CreateLev({1,3,nullopt,nullopt,2});
        // cout << t << endl;
        Solution().recoverTree(t);
    }
    // cout << "2:" << endl;
    // {
    //     auto t = TreeNode::CreateLev({3,1,4,nullopt,nullopt,2});
    //     // cout << t << endl;
    //     Solution().recoverTree(t);
    // }
    // cout << "2:" << endl;
    // {
    //     auto t = TreeNode::CreateLev({2,3,1});
    //     Solution().recoverTree(t);
    //     cout << t << endl;
    // }
    return 0;
}
#endif