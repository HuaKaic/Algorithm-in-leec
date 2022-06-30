#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        if (postorder.size() == 1) return true;
        bool flag = true;
        stack<int> sta;
        int root = INT_MAX;
        for (int i = postorder.size() - 1; i >= 0; i--) {
            if (postorder[i] > root) {
                flag = false;
                break;
            } // 判断左子树与根节点的关系
            while (sta.size() && postorder[i] < sta.top()) {
                root = sta.top();
                sta.pop();
            } // 找到当前节点的根节点
            sta.push(postorder[i]);
        }
        return flag;
    }
};