#include <vector>
#include <algorithm>
#include <string>
using namespace std;


class Solution {
private:
    int row, col;
    bool backTtrack(vector<vector<char>>& board, string word, int index, int i, int j) {
        if (i >= row || j >= col || index >= word.size() || i < 0 || j < 0 || board[i][j] != word[index]) return false;
        if(index == word.size() - 1) return true;
        board[i][j] = '/'; // 避免元素的重复判断
        bool up = backTtrack(board, word, index + 1, i - 1, j);
        bool down = backTtrack(board, word, index + 1, i + 1, j);
        bool right = backTtrack(board, word, index + 1, i, j + 1);
        bool left = backTtrack(board, word, index + 1, i, j - 1);
        board[i][j] = word[index];
        return down || right || left || up;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        int len_word = word.size();
        int row_size = board.size();
        int col_size = board[0].size();
        for(int i = 0; i < row_size; i++) {
            for(int j = 0; j < col_size; j++) {
                if(backTtrack(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};