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
    queue<TreeNode*> que;
    vector<vector<int>> vec;
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL) return vec;
        que.push(root);
        while (!que.empty()) {
            vector<int> sub_vec;
            int length_que = que.size();
            for (int i = 0; i < length_que; i++) {
                sub_vec.push_back(que.front()->val);
                TreeNode* tmp = que.front();
                que.pop();
                if (tmp->left) que.push(tmp->left);
                if (tmp->right) que.push(tmp->right);
            }
            vec.push_back(sub_vec);
            
        }
        return vec;
    }
};