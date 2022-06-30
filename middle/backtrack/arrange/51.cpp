#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    bool isValid(int row, int col, vector<string> cheseboard, int n) {
        for (int i = 0; i < row; i++) {
            if (cheseboard[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row -1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (cheseboard[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (cheseboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
    void backtrack(vector<string>& cheseboard, int n, int row) {
        if (row == n) {
            res.push_back(cheseboard);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(row, i, cheseboard, n)) {
                cheseboard[row][i] = 'Q';
                backtrack(cheseboard, n, row + 1);
                cheseboard[row][i] = '.';
            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        string samp(n, '.');
        vector<string> cheseboard(n, samp);
        backtrack(cheseboard, n, 0);
        return res;
    }
};