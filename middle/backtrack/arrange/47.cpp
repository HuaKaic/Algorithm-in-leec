#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        int count[21] = {0}; // 记录同层之间的数据使用情况
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == true) continue;
            if (count[nums[i] + 10] == 1) continue;
            count[nums[i] + 10] = 1;
            used[i] = true; // 记录同一根节点下的数据使用情况
            path.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        backtrack(nums, used);
        return res;
    }
};