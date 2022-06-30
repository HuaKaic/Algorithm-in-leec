#include <vector>
using namespace std;
// 跳跃游戏 以步数为单位，实时更新最大跳跃范围, 判断能否跳到终点
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int length = nums.size();
        int cover = 0;
        for (int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if (cover >= length - 1) return true;
        }
        return false;
    }
};