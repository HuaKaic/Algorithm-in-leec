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
        void Reverse(TreeNode* node, vector<int>& res, vector<int>& path) {
            if (node == NULL) return;
            path.push_back(node->val);
            if (node->left == NULL && node->right == NULL) {
                int path_sum = 0;
                for (size_t i = 0; i < path.size(); i++) {
                    path_sum += path[i];
                }
                res.push_back(path_sum);
            }
            if (node->left) {
                
                Reverse(node->left, res, path);
                path.pop_back();
            }
            if (node->right) {
                
                Reverse(node->right, res, path);
                path.pop_back();
            }
            return;
        }
        bool hasPathSum(TreeNode* root, int targetSum) {
            if (root == NULL) return false;
            vector<int> path;
            vector<int> res;
            Reverse(root, res, path);
            bool flag = false;
            for (size_t j = 0; j < res.size(); j++) {
                if (res[j] == targetSum) {
                    flag = true;
                }
            }
            return flag;
        }

};