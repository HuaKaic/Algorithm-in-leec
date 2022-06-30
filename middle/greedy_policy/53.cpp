#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int count = 0;
        int result = -1e5;
        for (int i = 0;i < nums.size();) {
            count += nums[i];
            if (count > result) {
                result = count;
            }
            if (count < 0) {
                count = 0;
            }
            i++;
        }
        return result;
    }
};