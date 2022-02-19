#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int startIndex, vector<bool>& flags) {
        if (!path.empty()) {
            res.push_back(path);
        }
        if (startIndex >= nums.size()) return;
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1] && flags[i-1] == false) continue;
            flags[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, i + 1, flags);
            path.pop_back();
            flags[i] = false;
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        path.clear();
        res.clear();
        res.push_back(path);
        vector<bool> flags(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, flags);
        return res;
    }
};