#include <vector>
using namespace std;
// 跳跃游戏，以最小步数跳到终点，已知能跳到终点，利用跳跃距离来判断

class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return 0;
        int step = 0;
        int cover = 0;
        int curCover = 0;
        int preCover = 0;
        for (int i = 0; i < size; i++) {
            curCover = max(curCover, i + nums[i]);
            if (i == preCover) {
                if (curCover < size - 1) {
                    step++;
                    preCover = curCover;
                } else {
                    step++;
                    break;
                }
            }
        }
        return step;
    }
};