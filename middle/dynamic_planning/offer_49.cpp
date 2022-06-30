#include <math.h>
using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n];
        dp[0] = 1;
        int a = 0, b = 0, c = 0;
        for (int i = 1; i < n; i++) {
            int tw = dp[a] * 2, th = dp[b] * 3, fi = dp[c] * 5;
            dp[i] = min(min(tw, th), fi); // 状态转移方程
            if (dp[i] == tw) a++;
            if (dp[i] == th) b++;
            if (dp[i] == fi) c++;
        }
        return dp[n -1];
    }
};