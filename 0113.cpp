#include<iostream>
#include<vector>
#include<algorithm>
#include<sstream>
#include<string>
#include<memory>
//#include <boost/progress.hpp>
#include<assert.h>
//#include <range/v3/all.hpp>

#include<cstdio>
#include <cstdarg>

using namespace std;
//using namespace ranges;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x=0) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //倒序输出,因为有数组移动所以速度较慢
    vector<vector<int>> pathSum0(TreeNode* root, int sum) {
        //cout << root->val << endl;
        if(root == nullptr){
            return vector<vector<int>>();
        }else if(root->left != nullptr){
            if(root->right == nullptr){
                vector<vector<int>> &&l(pathSum(root->left, sum - root->val));
                for(auto &i : l){
                    i.emplace(i.begin(), root->val);
                }
                return l;
            }else{
                vector<vector<int>> &&l(pathSum(root->left, sum - root->val));
                vector<vector<int>> &&r(pathSum(root->right, sum - root->val));
                l.insert(l.end(), r.begin(), r.end());
                for(auto &i : l){
                    i.emplace(i.begin(), root->val);
                }
                return l;
            }
        }else if(root->right != nullptr){
            vector<vector<int>> &&r(pathSum(root->right, sum - root->val));
            for(auto &i : r){
                i.emplace(i.begin(), root->val);
            }
            return r;
        }else if(sum == root->val){
            return vector<vector<int>>{{sum}};
        }else{
            return vector<vector<int>>();
        }
    }

    //简单优化代码量,性能有可能降低
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        //cout << root->val << endl;
        if(root == nullptr){
            return vector<vector<int>>();
        }else if(sum == root->val && root->left == nullptr && root->right == nullptr){
            return vector<vector<int>>{{sum}};
        }else{
            vector<vector<int>> &&l(pathSum(root->left, sum - root->val));
            vector<vector<int>> &&r(pathSum(root->right, sum - root->val));
            l.insert(l.end(), r.begin(), r.end());
            for(auto &i : l){
                i.emplace(i.begin(), root->val);
            }
            return l;
        }
    }

    //改用list存储,增加性能
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == nullptr){
            return vector<vector<int>>();
        }else if(sum == root->val && root->left == nullptr && root->right == nullptr){
            return vector<vector<int>>{{sum}};
        }else{
            vector<vector<int>> &&l(pathSum(root->left, sum - root->val));
            vector<vector<int>> &&r(pathSum(root->right, sum - root->val));
            l.insert(l.end(), r.begin(), r.end());
            for(auto &i : l){
                i.emplace(i.begin(), root->val);
            }
            return l;
        }
    }
};


TreeNode *TreeCreate(int count, ...)
{
    va_list argptr;
    va_start(argptr, count);

    TreeNode **treeArr = new TreeNode*[count];
    for (int i = 0; i < count; i++)
    {
        int num = va_arg(argptr, int);
        if (INT_MAX == num)
            treeArr[i] = NULL;
        else
            treeArr[i] = new TreeNode(num);
    }

    int curr = 1;
    for (int i = 0; i<count; i++)
    {
        if( !treeArr[i] )
            continue;

        if( curr < count )
            treeArr[i]->left = treeArr[curr++];
        if (curr < count)
            treeArr[i]->right = treeArr[curr++];
    }

    va_end(argptr);
    return treeArr[0];
}


void IntVector2DPrint(const vector<vector<int>> &vec)
{
    printf("[\n");
    for (size_t i = 0; i < vec.size(); i++)
    {
        printf("[ ");
        for (size_t j = 0; j < vec[i].size(); j++)
            printf("%d, ", vec[i][j]);
        printf(" ]\n");
    }
    printf("]\n");
}
int main() {
    TreeNode *tree = TreeCreate(12,5,4,8,11,INT_MAX,13,4,7,2,INT_MAX,INT_MAX,5,1);
    IntVector2DPrint(Solution().pathSum(tree, 22));
    return 0;
}