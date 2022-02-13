#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<int> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<int> ret;
        queue<TreeNode*> que;
        que.emplace(root);
        while (que.size() != 0) {
            auto node = que.front();
            que.pop();
            ret.emplace_back(node->val);
            if (node->left != nullptr)
                que.emplace(node->left);
            if (node->right != nullptr)
                que.emplace(node->right);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 3,9,20,nullopt,nullopt,15,7 });
        cout << Solution().levelOrder(root) << endl;
    }
    cout << " 2:" << endl;
    {
    }
    return 0;
}
#endif