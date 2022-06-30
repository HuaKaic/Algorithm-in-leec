#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        int limit = target / 2 + 1;
        vector<vector<int>> res;
        vector<int> tmp_res;
        int left = 1;
        int right = 2;
        while (left < right && right <= limit) {
            int sum = (left + right) * (right - left + 1) / 2;
            if (sum == target) {
                tmp_res.clear();
                for (int i = left; i <= right; i++) {
                    tmp_res.push_back(i);
                }
                res.push_back(tmp_res);
                left++;
            }else if (sum > target) {
                left++;
            }else if (sum < target){
                right++;
            }
        }
        return res;
    }
};