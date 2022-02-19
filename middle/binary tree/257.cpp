#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>

using namespace std;

class Solution {
public:
    class TreeNode {
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
    };
    vector<string> binaryTreePaths(TreeNode* root) {
        stack<TreeNode*> treeptr;
        stack<string> pathptr;
        vector<string> res;
        if (root == NULL) return res;
        treeptr.push(root);
        while (!treeptr.empty()) {
            TreeNode* tmp = treeptr.top();
            treeptr.pop();
            pathptr.push(to_string(tmp->val));
            string path = pathptr.top();
            pathptr.pop();
            if (tmp->left == NULL && tmp->right == NULL) {
                res.push_back(path);
            }
            
            if (tmp->right) {
                treeptr.push(tmp->right);
                pathptr.push(path + "->" + to_string(tmp->right->val));
            }
            if (tmp->left) {
                treeptr.push(tmp->left);
                pathptr.push(path + "->" + to_string(tmp->left->val));
            }
        }
        return res;

    }
};