#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
public:
    void flatten(TreeNode *root) {
        for(TreeNode *now = root; now != nullptr; now = now->right) {
            if(now->left != nullptr) {
                if(now->right == nullptr) {
                    now->right = now->left;
                    now->left  = nullptr;
                } else {
                    TreeNode *tail = now->left;
                    while(tail->right != nullptr) tail = tail->right;
                    tail->right = now->right;
                    now->right = now->left;
                    now->left  = nullptr;
                }
            }
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1, 2, 5, 3, 4, nullopt, 6});
        cout << "before:\n" << root << endl;
        Solution().flatten(root);
        cout << "after:\n" << root << endl;
    }
    cout << "2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({});
        cout << "before:\n" << root << endl;
        Solution().flatten(root);
        cout << "after:\n" << root << endl;
    }
    cout << "3:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({0});
        cout << "before:\n" << root << endl;
        Solution().flatten(root);
        cout << "after:\n" << root << endl;
    }
    // cout << "4:" << endl;
    // {
    // }

    return 0;
}
#endif