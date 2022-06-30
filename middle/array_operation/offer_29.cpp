#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 1) return matrix[0];
        int row = matrix.size();
        vector<int> res;
        if (row == 0) return res;
        int col = matrix[0].size();
        int total = row * col;
        int up = 0;
        int down = row - 1;
        int left = 0;
        int right = col - 1;
        while (total) {
            for (int i = left; i <= right && total > 0; i++) { // 从左到右
                res.push_back(matrix[up][i]);
                total--;
            }
            up++; // 更新上边界
            for (int i = up;i <= down && total > 0; i++) { // 从上到下
                res.push_back(matrix[i][right]);
                total--;
            }
            right--; // update right;
            for (int i = right; i >= left && total > 0; i--) {
                res.push_back(matrix[down][i]);
                total--;
            }
            down--; // update down;
            for (int i = down; i >= up && total > 0; i--) {
                res.push_back(matrix[i][left]);
                total--;
            }
            left++;
        }
        return res;
    }
};