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
    TreeNode* Reverse(TreeNode* root1, TreeNode* root2) {
        TreeNode* midd = new TreeNode();
        if (root1 == NULL && root2 != NULL) {
            midd->val = root2->val;
        }
        if (root1 != NULL && root2 == NULL) {
            midd->val = root1->val;
        }
        if (root1 && root2) {
            midd->val = (root1->val + root2->val);
        }
        if (!root1 && !root2) return NULL;
        midd->left = Reverse(root1->left, root2->left);
        midd->right = Reverse(root1->right, root2->right);
        return midd;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) return NULL;
        return Reverse(root1, root2);
    }
};