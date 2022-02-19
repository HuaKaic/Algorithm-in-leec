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
        TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    };
    TreeNode* Reverse(vector<int>& inod, vector<int>& postod) {
        if (postod.size() == 0) return nullptr;
        int deter_number = postod[inod.size() - 1];
        TreeNode* root = new TreeNode(deter_number);
        if (inod.size() == 1) return root;
        int si; // 局部作用域问题，中间节点对应的数组下标。
        for (si = 0; si < inod.size(); si++) {
            if (inod[si] == deter_number) break;
        }
        vector<int> left_inod(inod.begin(), inod.begin() + si);
        vector<int> right_inod(inod.begin() + si + 1, inod.end());

        postod.resize(postod.size() - 1);
        vector<int> left_postod(postod.begin(), postod.begin() + left_inod.size());
        vector<int> right_postod(postod.begin() + left_inod.size(), postod.end());

        root->left = Reverse(left_inod, left_postod);
        root->right = Reverse(right_inod, right_postod);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 && postorder.size() == 0) return nullptr;
        return Reverse(inorder, postorder);
    }
};