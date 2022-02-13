#ifdef LEETCODE
#include <LeetCodeL.hpp>
#endif

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution1 {
    static pair<vector<int>, int> getTreeSum(TreeNode* root) {
        pair<vector<int>, int> ret;
        if (root->left != nullptr) {
            auto [arr, val] = getTreeSum(root->left);
            ret.first = arr;
            ret.second = val;
        }
        if (root->right != nullptr) {
            auto [arr, val] = getTreeSum(root->right);
            ret.first.insert(ret.first.end(), arr.begin(), arr.end());
            ret.second += val;
        }
        ret.second += root->val;
        ret.first.emplace_back(ret.second);

        return ret;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        auto [all, _] = getTreeSum(root);
        map<int, int> dict;
        int maxNum = 0;
        for (auto& val : all) {
            auto it = dict.find(val);
            if (it != dict.end()) {
                it->second++;
                maxNum = max(maxNum, it->second);
            } else {
                dict.emplace(val, 0);
            }
        }
        vector<int> ret;
        for (auto& [val, time] : dict) {
            if (time == maxNum)
                ret.emplace_back(val);
        }
        return ret;
    }
};

class Solution {
    vector<int> all;
    int getTreeSum(TreeNode* root) {
        int ret = 0;
        if (root->left != nullptr) {
            int val = getTreeSum(root->left);
            ret = val;
        }
        if (root->right != nullptr) {
            int val = getTreeSum(root->right);
            ret += val;
        }
        ret += root->val;
        all.emplace_back(ret);

        return ret;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        getTreeSum(root);
        map<int, int> dict;
        int maxNum = 0;
        for (auto& val : all) {
            auto it = dict.find(val);
            if (it != dict.end()) {
                it->second++;
                maxNum = max(maxNum, it->second);
            } else {
                dict.emplace(val, 0);
            }
        }
        vector<int> ret;
        for (auto& [val, time] : dict) {
            if (time == maxNum)
                ret.emplace_back(val);
        }
        return ret;
    }
};

#ifdef LEETCODE
int main() {
    cout << "1:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 5,2,-3 });
        cout << Solution().findFrequentTreeSum(root) << endl;
        //[2, -3, 4]
    }
    cout << "2:" << endl;
    {
        TreeNode* root = TreeNode::CreateLev({ 5,2,-5 });
        cout << Solution().findFrequentTreeSum(root) << endl;
        //[2]
    }

    return 0;
}
#endif
