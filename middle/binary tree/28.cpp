/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <queue>
#include <vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} 
};
class Solution {
public:
    bool judgeSymeric(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        if (!A || !B || A->val != B->val) return false; // 出现空值、不相等则返回
        return judgeSymeric(A->left, B->right) && judgeSymeric(A->right, B->left); // 递归比较左右子树， 注意比较的顺序、逻辑
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return judgeSymeric(root->left, root->right);
    }
};