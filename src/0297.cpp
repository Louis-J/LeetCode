#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)
            return "[null]";

        // queue<TreeNode*, list<TreeNode*>> que;
        queue<TreeNode*> que;
        que.push(root);
        string ret{'['};
        while(!que.empty()) {
            TreeNode *tmp = que.front();
            que.pop();

            if(tmp != nullptr) {
                ret += to_string(tmp->val);
                ret += ',';
                que.push(tmp->left);
                que.push(tmp->right);
            } else
                ret += "null,";
        }
        ret[ret.size()-1] = ']';
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() <= 2 || data.compare(0, 5, "[null") == 0) {
            return nullptr;
        }
        data[data.size()-1] = ',';
        vector<optional<int>> list;
        for(size_t i = 1; i < data.size()-1;) {
            if(data[i] == 'n') {
                list.emplace_back(nullopt);
                i+=5;
            } else {
                int tmp;
                if(data[i] == '-')
                    tmp = '0'-data[++i];
                else if(data[i] == '+')
                    tmp = data[++i]-'0';
                else
                    tmp = data[i]-'0';

                while(data[++i] != ',')
                    tmp = tmp*10 + data[i]-'0';
                i++;
                list.emplace_back(tmp);
            }
        }
        TreeNode *head = new TreeNode(**list.begin());
        vector<TreeNode*> leva{head};
        vector<TreeNode*> levb;
        auto i = leva.begin();
        for(auto j = (list.begin()+1); j != list.end(); j++) {
            if(*j != nullopt) {
                (*i)->left = new TreeNode(**j);
                levb.push_back((*i)->left);
            }
            j++;
            if(j == list.end())
                return head;
            if(*j != nullopt) {
                (*i)->right = new TreeNode(**j);
                levb.push_back((*i)->right);
            }
            i++;
            if(i == leva.end()) {
                // leva = levb;
                swap(leva, levb);
                levb.clear();
                i = leva.begin();
            }
        }
        return head;
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        // TreeNode *root = TreeNode::CreateLev({1, 2, 3, nullopt, nullopt, 4, 5})
        auto sl = Codec();
        cout << sl.serialize(sl.deserialize("[1,2,3,null,null,4,5]")) << endl;
    }
    // cout << " 2:" << endl;
    // {
    //     cout << Solution().countDigitOne(0) << endl;
    // }
    // cout << " 3:" << endl;
    // {
    //     cout << Solution().countDigitOne(1) << endl;
    // }
    return 0;
}
#endif