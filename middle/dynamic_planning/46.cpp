#include <iostream>
#include <string>
#include <math.h>

using namespace std;


class Solution {
public:
    int translateNum(int num) {
        if (num < 10) return 1;
        string nums = to_string(num); // 转化为字符串
        int dp[nums.size()];
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i++) {
            string tmp;
            tmp += nums[i - 1];
            tmp += nums[i];
            if (stoi(tmp, 0, 10) < 26 && stoi(tmp, 0, 10) > 9) { // 注意不能使用连续比较符
                if (i == 1) {
                    dp[i] = dp [i - 1] + 1;
                }else {
                    dp[i] = dp [i - 1] + dp[i - 2];
                }
                
            }else {
                dp[i] = dp [i - 1];
            }
        }
        return dp[nums.size() - 1];
    }
};