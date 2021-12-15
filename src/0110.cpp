#ifdef LEETCODE
#include "LeetCodeL.hpp"
#endif

class Solution {
    static int IB(TreeNode *root) {
        if(!root)
            return 0;
        else {
            int l = IB(root->left);
            if(l == -1)
                return -1;
            int r = IB(root->right);
            if(r == -1 || abs(l-r) > 1)
                return -1;
            return max(l, r)+1;
        }
    }
public:
    //后序遍历递归
    bool isBalanced0(TreeNode *root) {
        int ret = IB(root);
        return ret != -1;
    }

    //后序遍历转换为非递归，使用数组(作为任务队列，先先序遍历插入，再从后往前遍历模仿后序遍历)
    bool isBalanced1(TreeNode *root) {
        //对应上个函数的root, l, r, 返回值所在的index
        using T = tuple<TreeNode *, int, int, int>;
        vector<T> tasks;
        tasks.emplace_back(root, 0, 0, -1);
        //先先序遍历插入任务
        for(int i = 0; i < tasks.size(); i++) {
            auto &t = tasks[i];
            auto node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);
            if(node) {
                tasks.emplace_back(node->left, 0, 0, i);
                tasks.emplace_back(node->right, 0, 0, i);
            }
        }
        //模仿后序遍历
        for(int i = tasks.size()-1; i > 0; i--) {
            auto &t = tasks[i];
            auto &node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);
            if(node) {
                if(abs(l-r) > 1)
                    return false;
                auto &reti = get<3>(t);
                auto &retl = get<1>(tasks[reti]);
                auto &retr = get<2>(tasks[reti]);
                if(retl == 0)
                    retl = max(l, r)+1;
                else
                    retr = max(l, r)+1;
            }
        }
        //tasks[0]的返回值处用了nullptr，所以要单独拿出来。
        auto &t = tasks[0];
        auto &l = get<1>(t);
        auto &r = get<2>(t);
        if(abs(l-r) > 1)
            return false;
        else
            return true;
    }
    //上个方法中优化代码的改进，易于理解
    bool isBalanced2(TreeNode *root) {
        using T = tuple<TreeNode *, int, int, int>;
        if(!root)
            return true;
        vector<T> tasks;
        tasks.emplace_back(root, 0, 0, 0);
        //先先序遍历插入任务
        for(int i = 0; i < tasks.size(); i++) {
            auto &t = tasks[i];
            auto node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);
            if(node->left != nullptr)
                tasks.emplace_back(node->left, 0, 0, i);
            if(node->right != nullptr)
                tasks.emplace_back(node->right, 0, 0, i);
        }
        //模仿后序遍历，此处用>=0
        for(int i = tasks.size()-1; i >= 0; i--) {
            auto &t = tasks[i];
            auto &node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);
            if(abs(l-r) > 1)
                return false;
            auto &reti = get<3>(t);
            auto &retl = get<1>(tasks[reti]);
            auto &retr = get<2>(tasks[reti]);
            if(retl == 0)
                retl = max(l, r)+1;
            else
                retr = max(l, r)+1;
        }
        return true;
    }
    //后序遍历转换为非递归，使用单栈
    bool isBalanced3(TreeNode *root) {
        using T = tuple<TreeNode *, int, int>;
        if(!root)
            return true;
        stack<T> stk;
        stk.emplace(nullptr, 0, 0);//用来占位的
        stk.emplace(root, 0, 0);
        //用来记录上个遍历的节点，保证后序的顺序
        TreeNode *visit = nullptr;

        while(stk.size() != 1) {
            auto &t = stk.top();
            auto node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);

            //先遍历左子树
            if(node->left && visit != node->left && !(node->right && visit == node->right)) {
                stk.emplace(node->left, 0, 0);
            //再遍历右子树
            } else if(node->right && visit != node->right) {
                stk.emplace(node->right, 0, 0);
            //最后遍历自己
            } else {
                if(abs(l-r) > 1)
                    return false;
                auto ret = max(l, r)+1;
                stk.pop();
                auto &retl = get<1>(stk.top());
                auto &retr = get<2>(stk.top());
                if(retl == 0)
                    retl = ret;
                else
                    retr = ret;
                visit = node;
            }
        }
        return true;
    }
    //单栈优化效率
    bool isBalanced4(TreeNode *root) {
        using T = tuple<TreeNode *, int, int>;
        if(!root)
            return true;
        stack<T> stk;
        stk.emplace(nullptr, 0, 0);//用来占位的
        stk.emplace(root, 0, 0);
        //用来记录上个遍历的节点，保证后序的顺序
        TreeNode *visit = nullptr;

        while(stk.size() != 1) {
            auto &t = stk.top();
            auto node = get<0>(t);
            auto &l = get<1>(t);
            auto &r = get<2>(t);

            int state;
            if(node->right && visit == node->right) {
                if(abs(l-r) > 1)
                    return false;
                auto ret = max(l, r)+1;
                stk.pop();
                auto &retl = get<1>(stk.top());
                auto &retr = get<2>(stk.top());
                if(retl == 0)
                    retl = ret;
                else
                    retr = ret;
                visit = node;
            } else if(node->left && visit != node->left) {
                stk.emplace(node->left, 0, 0);
            } else if(node->right) {
                stk.emplace(node->right, 0, 0);
            } else {
                if(abs(l-r) > 1)
                    return false;
                auto ret = max(l, r)+1;
                stk.pop();
                auto &retl = get<1>(stk.top());
                auto &retr = get<2>(stk.top());
                if(retl == 0)
                    retl = ret;
                else
                    retr = ret;
                visit = node;
            }
        }
        return true;
    }
    //后序遍历转换为非递归，使用单栈
    bool isBalanced5(TreeNode *root) {
        using T = tuple<TreeNode *, int, int>;
        if(!root)
            return true;
        stack<T> stk;
        stk.emplace(nullptr, 0, 0);//用来占位的
        stk.emplace(root, 0, 0);
        //用来记录上个遍历的节点，保证后序的顺序
        TreeNode *visit = nullptr;

        while(stk.size() != 1) {
            auto &t = stk.top();
            auto node = get<0>(t);
            auto &lev = get<1>(t);
            auto &status = get<2>(t);

            switch(status) {
            //先遍历左子树
            case 0:
                status++;
                if(node->left) {
                    stk.emplace(node->left, 0, 0);
                    break;
                }
            //再遍历右子树
            case 1:
                status++;
                if(node->right) {
                    stk.emplace(node->right, 0, 0);
                    break;
                }
            //最后遍历自己
            case 2: {
                //只有一边有且不平衡
                if(lev < -1)
                    return false;
                auto thislev = abs(lev)+1;
                stk.pop();
                auto &lastlev = get<1>(stk.top());
                if(lastlev == 0)
                    lastlev = -thislev;
                else {
                    if(abs(thislev+lastlev) > 1)
                        return false;
                    lastlev = max(-lastlev, thislev);
                }
            }
            }
        }
        return true;
    }
    bool isBalanced(TreeNode *root) {
        return isBalanced5(root);
    }
};

#ifdef LEETCODE
int main() {
    cout << " 1:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({3,9,20,nullopt,nullopt,15,7});
        cout << Solution().isBalanced0(root) << endl;
        cout << Solution().isBalanced1(root) << endl;
        cout << Solution().isBalanced2(root) << endl;
        cout << Solution().isBalanced3(root) << endl;
        cout << Solution().isBalanced4(root) << endl;
        cout << Solution().isBalanced5(root) << endl;
    }
    cout << " 2:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,2,3,3,nullopt,nullopt,4,4});
        cout << Solution().isBalanced0(root) << endl;
        cout << Solution().isBalanced1(root) << endl;
        cout << Solution().isBalanced2(root) << endl;
        cout << Solution().isBalanced3(root) << endl;
        cout << Solution().isBalanced4(root) << endl;
        cout << Solution().isBalanced5(root) << endl;
    }
    cout << " 3:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,2,3,4,5,6,nullopt,8});
        cout << Solution().isBalanced0(root) << endl;
        cout << Solution().isBalanced1(root) << endl;
        cout << Solution().isBalanced2(root) << endl;
        cout << Solution().isBalanced3(root) << endl;
        cout << Solution().isBalanced4(root) << endl;
        cout << Solution().isBalanced5(root) << endl;
    }
    cout << " 4:" << endl;
    {
        TreeNode *root = TreeNode::CreateLev({1,nullopt,2,nullopt,3});
        cout << Solution().isBalanced0(root) << endl;
        cout << Solution().isBalanced1(root) << endl;
        cout << Solution().isBalanced2(root) << endl;
        cout << Solution().isBalanced3(root) << endl;
        cout << Solution().isBalanced4(root) << endl;
        cout << Solution().isBalanced5(root) << endl;
    }
    return 0;
}
#endif