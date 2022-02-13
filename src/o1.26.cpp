#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
    static bool isSubHelper1(TreeNode* A, TreeNode* B) {
        if (A->val != B->val)
            return false;
        if (B->left != nullptr) {
            if (A->left == nullptr || !isSubHelper1(A->left, B->left))
                return false;
        }
        if (B->right != nullptr) {
            if (A->right == nullptr || !isSubHelper1(A->right, B->right))
                return false;
        }
        return true;
    }
    static bool isSubHelper2(TreeNode* A, TreeNode* B) {
        if (isSubHelper1(A, B))
            return true;
        if (A->left != nullptr && isSubHelper2(A->left, B)) {
            return true;
        }
        if (A->right != nullptr && isSubHelper2(A->right, B)) {
            return true;
        }
        return false;
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        return isSubHelper2(A, B);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode* A = TreeNode::CreateLev({ 1,2,3 });
        TreeNode* B = TreeNode::CreateLev({ 3,1 });
        cout << Solution().isSubStructure(A, B) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode* A = TreeNode::CreateLev({ 3,4,5,1,2 });
        TreeNode* B = TreeNode::CreateLev({ 4,1 });
        cout << Solution().isSubStructure(A, B) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode* A = TreeNode::CreateLev({ 4,2,3,4,5,6,7,8,9 });
        TreeNode* B = TreeNode::CreateLev({ 4,8,9 });
        cout << Solution().isSubStructure(A, B) << endl;
    }
    return 0;
}
#endif