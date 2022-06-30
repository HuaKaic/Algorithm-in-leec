#include <vector>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> numbers(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) numbers[i] = numbers[i -1] + 1;
        } // 比较左边的孩子
        int count = numbers[ratings.size() - 1];
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                numbers[i] = max(numbers[i + 1] + 1, numbers[i]);
            }
            count += numbers[i];
        } // 比较右边的孩子，取同时满足左右孩子的值。
        return count;
    }
};