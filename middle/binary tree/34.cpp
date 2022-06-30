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
    vector<int> path;
    vector<vector<int>> res;
    void backTrack(TreeNode* root, int target) {
        if (root == nullptr) {
            return;
        }else if (target - root->val == 0 && root->left == nullptr && root->right == nullptr) {
            path.push_back(root->val);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->val);
        target -= root->val;
        backTrack(root->left, target);
        backTrack(root->right, target);
        path.pop_back(); // 弹出当前节点
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        backTrack(root, target);
        return res;
    }
};