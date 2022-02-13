#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> ret;
        queue<pair<TreeNode*, int>> que;
        que.emplace(root, 0);
        while (que.size() != 0) {
            auto node = que.front();
            que.pop();
            if (ret.size() == node.second) {
                ret.emplace_back(vector<int>());
            }
            ret[node.second].emplace_back(node.first->val);
            if (node.first->left != nullptr)
                que.emplace(node.first->left, node.second + 1);
            if (node.first->right != nullptr)
                que.emplace(node.first->right, node.second + 1);
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