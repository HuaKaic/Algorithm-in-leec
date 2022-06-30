###
二叉树序列化
***
```C++
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        if (root == NULL) return res;
        queue<TreeNode*> que;
        que.push(root);
        // 利用队列层序遍历
        while (!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if (cur) {
                res += to_string(cur->val);
                res += ',';
                que.push(cur->left);
                que.push(cur->right);
            }else {
                res += "#";
                res += ',';
            }
        }
        return res;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return NULL;
        string str;
        int count = 0;
        int size = data.size();
        while (data[count] != ',') {
            str += data[count];
            count++;
        }
        TreeNode* head = new TreeNode(stoi(str));
        queue<TreeNode*> que;
        que.push(head);
        count++;
        while (!que.empty() && count < size) {
            TreeNode* tmp = que.front();
            que.pop();
            
            if (data[count] != '#') {
                str.clear();
                while (data[count] != ',' && count < size) {
                    str += data[count];
                    count++;
                }
                tmp->left = new TreeNode(stoi(str));
                que.push(tmp->left);
                count++;
            }else {
                count += 2;
            }
            
            if (data[count] != '#') {
                str.clear();
                while (data[count] != ',' && count < size) {
                    str += data[count];
                    count++;
                }
                tmp->right = new TreeNode(stoi(str));
                que.push(tmp->right);
                count++;
            }else {
                count += 2;
            }
        }
        return head;
    }
};
、、、
