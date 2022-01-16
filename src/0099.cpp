#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static void order(vector<TreeNode*> &vec, TreeNode *root) {
        if(root->left)
            order(vec, root->left);
        vec.emplace_back(root);
        if(root->right)
            order(vec, root->right);
    }
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode*> vec;
        order(vec, root);
        int err1 = -1, err2 = -1;
        for(int i = 1; i < vec.size(); i++) {
            if(vec[i]->val < vec[i-1]->val) {
                if(err1 == -1) {
                    err1 = i-1;
                } else {
                    err2 = i;
                    break;
                }
            }
        }
        if(err2 != -1) {
            swap(vec[err1]->val, vec[err2]->val);
        } else {
            swap(vec[err1]->val, vec[err1+1]->val);
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        auto t = TreeNode::CreateLev({1,3,nullopt,nullopt,2});
        cout << t << endl;
        Solution().recoverTree(t);
        cout << t << endl;
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