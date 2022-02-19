#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;
    int sum;
    void backtrack(vector<int>& candidates, int target, int startIndex, vector<bool>& flag) {
        
        if (sum == target) {
            res.push_back(path);
        }
        for (int i = startIndex; i < candidates.size() && (sum + candidates[i]) <= target; i++) {
            /*if (i > startIndex && candidates[i] == candidates[i - 1]) {
              continue;
            }*/
            if (i > 0 && candidates[i] == candidates[i-1] && flag[i-1] == false) {
                continue;
            }
            flag[i] = true;
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtrack(candidates, target, i+1, flag);
            flag[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        path.clear();
        res.clear();
        vector<bool> flag(candidates.size(), false);
        backtrack(candidates, target, 0, flag);
        return res;
    }
};