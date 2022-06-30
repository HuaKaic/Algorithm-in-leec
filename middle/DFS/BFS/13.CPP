#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int count = 0;
    void Reverse(int row, int col, int k, int m, int n, vector<vector<bool>>& used) {
        if (row >= m || col >= n || used[row][col] || row < 0 || col < 0) return;
        if ((Sum_nums(row) + Sum_nums(col)) > k) return;
        count++; // 当前格子满足要求
        used[row][col] = true;
        // Reverse(row - 1, col, k, m, n, used); // 向上找
        Reverse(row + 1, col, k, m, n, used); // 向下找
        // Reverse(row, col - 1, k, m, n); // 向左找 出现无限递归的情况
        Reverse(row, col + 1, k ,m, n, used); // 向右找
        return;
    }
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> used(m, vector<bool>(n, false)); // 运用数组记录遍历过的下标 该点未想到
        Reverse(0, 0, k, m, n, used);
        return count;
    }
    int Sum_nums(int n) {
        int sum = 0;
        while (n / 10 != 0) {
            sum += n - (n / 10) * 10;
            n = n / 10;
        }
        sum += n;
        return sum;
    }
};