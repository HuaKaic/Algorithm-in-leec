#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int prediff = 0;
        int curdiff = 0;
        int count = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            curdiff = nums[i + 1] - nums[i];
            if ((curdiff > 0 && prediff <= 0) || (curdiff < 0 && prediff >= 0)) {
                count++;
                prediff = curdiff;
            } // 排除两数相等的情况，始终保证curdiff 不等于零
            
        }
        return count;
    }
};