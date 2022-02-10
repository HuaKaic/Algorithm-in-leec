#include<iostream>
#include<string>
#include<vector>
#include<stack>

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
        void Reverse(TreeNode* node, vector<vector<int>>& res, vector<int>& path, int target) {
            path.push_back(node->val);
            target -= node->val;
            if (node->left == NULL && node->right == NULL & target == 0) {
                    res.push_back(path);
                }
            if (node->left) {
                Reverse(node->left, res, path, target);
                target += path.back();
                path.pop_back();
            }
            if (node->right) {
                
                Reverse(node->right, res, path, target);
                target += path.back();
                path.pop_back();
            }
            return;
        }
        vector<vector<int>> hasPathSum(TreeNode* root, int targetSum) {
            vector<int> path;
            vector<vector<int>> res;
            if (root == NULL) return res;
            Reverse(root, res, path, targetSum);
            return res;
        }

};