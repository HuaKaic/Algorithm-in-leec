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
    void putINvector(TreeNode* root, vector<int> res) {
        if (root == NULL) return;
        res.push_back(root->val);
        putINvector(root->left, res);
        putINvector(root->right, res);
        return;
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        putINvector(root, res);
        int min_ = 100;
        for (size_t i = 0; i < res.size() - 1; i++) {
            for (size_t j = i + 1; j < res.size(); j++) {
                int tmp = abs(res[j] - res[i]);
                if (tmp < min_) min_ = tmp;
            }
        }
        return min_;
    }
};