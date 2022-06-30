#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) return 0;
        int len = prices.size();
        vector<vector<int>> res(len, vector<int>(2));
        res[0][0] = - prices[0]; // 持有股票下下的最大收益；
        res[0][1] = 0; // 不持有股票下的最大收益；
        for (int i = 1; i < len; i++) {
            res[i][0] = max(res[i - 1][0], -prices[i]);
            res[i][1] = max(res[i - 1][1], res[i - 1][0] + prices[i]);
        }
        return res[len - 1][1];
    }
};