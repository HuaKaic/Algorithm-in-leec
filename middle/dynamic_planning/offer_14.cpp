#include <vector>
using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            int cur_max = 0;
            for (int j = 1; j < i; j++) {
                cur_max = max(cur_max, max(j * (i -j), j * dp[i -j])); // 递推公式 更新用到多个变量
            }
            dp[i] = cur_max;
        }
        return dp[n];
    }
};