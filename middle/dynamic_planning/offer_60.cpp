#include <vector>
using namespace std;

class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<double> tmp;
        vector<vector<double>> res;
        for (int i = 0; i < 6; i++) {
            tmp.push_back(double(1.0 / 6.0));
        }
        res.push_back(tmp);
        for (int i = 2; i <= n; i++) {
            vector<double> path(5 * i + 1, 0); // 增加一个骰子后的结果
            for (int j = 0; j < res.back().size(); j++) {
                for (int k = 0; k < 6; k++) {
                    path[j + k] += (1.0 / 6.0) * res.back()[j];
                }
            } // 动态规划的递推公式，当前结果可有少于1个骰子的结果推出
            res.push_back(path);

        }
        return res.back();
    }
};