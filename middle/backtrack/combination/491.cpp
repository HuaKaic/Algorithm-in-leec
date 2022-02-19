#include <iostream>
#include <vector>

using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        int count[201] = {0};
        for (int i = startIndex; i < nums.size(); i++) {
            if (!path.empty() && nums[i] < path.back() || count[nums[i] + 100] == 1) {
                continue;
            }
            count[nums[i] + 100] = 1; // 数组下标的哈希算法
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};