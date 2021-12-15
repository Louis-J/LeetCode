#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    //二叉树动态规划
    //val%3 == 0:监控在父
    //val%3 == 1:监控在本处
    //val%3 == 2:监控在子
    //val/3 :监控数量
    static void MCC0(TreeNode* root) {
        if(root->left == nullptr) {
            if(root->right == nullptr) {
                root->val = 3;
            } else {
                MCC0(root->right);
                root->val = root->right->val+1;
            }
        } else {
            MCC0(root->left);
            if(root->right == nullptr) {
                root->val = root->left->val+1;
            } else {
                MCC0(root->right);
                if(root->left->val%3 == 0 && root->right->val%3 == 0) {
                    root->val = root->left->val + root->right->val-3+1;
                } else {
                    root->val = (root->left->val/3 + root->right->val/3)*3 +
                        min(root->left->val%3, root->right->val%3) + 1;
                }
            }
        }
    }
    static int MCC1(TreeNode* root) {
        if(root->left == nullptr) {
            if(root->right == nullptr)
                return 3;
            else
                return MCC1(root->right)+1;
        } else {
            ;
            if(root->right == nullptr) {
                return MCC1(root->left)+1;
            } else {
                int l = MCC1(root->left);
                int r = MCC1(root->right);
                if(l%3 + r%3 == 0) {
                    return l + r - 2;
                } else {
                    return l+r-l%3-r%3 + min(l%3, r%3) + 1;
                }
            }
        }
    }
public:
    int minCameraCover(TreeNode* root) {
        if(root == nullptr)
            return 0;
        else {
            // MCC0(root);
            // return root->val/3;
            return MCC1(root)/3;
        }
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({0, 0, nullopt, 0, 0});
        cout << Solution().minCameraCover(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({0, 0, nullopt, 0, nullopt, 0, nullopt, nullopt, 0});
        cout << Solution().minCameraCover(root) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({0, 0, 0, nullopt, nullopt, nullopt, 0});
        cout << Solution().minCameraCover(root) << endl;
    }
    cout << " 4:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({0, 0, 0, nullopt, nullopt, 0, nullopt, 0, nullopt, 0});
        cout << Solution().minCameraCover(root) << endl;
    }
    return 0;
}
#endif