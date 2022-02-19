#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<algorithm>

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
    void putINmap(TreeNode* root, unordered_map<int, int>& map) {
        if (root == NULL) return;
        map[root->val]++;
        putINmap(root->left, map);
        putINmap(root->right, map);
        return;
    }
    bool sort_vector(TreeNode* node1, TreeNode* node2) {
        return node1->val > node2->val;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }
        unordered_map<int, int> map;
        putINmap(root, map);
        vector<pair<int, int>> res(map.begin(), map.end());
        sort(res.begin(), res.end(), sort_vector);
        result.push_back(res[0].first);
        for (int i = 1; i < res.size(); i++) {
            if (res[0].second == res[i].second) {
                result.push_back(res[i].first);
            }
        }
        return result;
    }
};