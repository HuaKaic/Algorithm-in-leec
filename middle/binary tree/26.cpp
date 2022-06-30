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
    bool findSub(TreeNode* A, TreeNode* B) {
        if (!B) return true; // 所有节点均能匹配上
        if (!A || A->val != B->val) return false; // 对应A树没有相应的节点、数值不匹配
        return findSub(A->left, B->left) && findSub(A->right, B->right);
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) return false;
        if  (findSub(A, B)) return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};