#include <vector>
using namespace std;
#include <algorithm>

class Solution {
private:
    static bool compa(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 1) return intervals;
        sort(intervals.begin(), intervals.end(), compa);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= intervals[i - 1][1]) { // 发现重叠，更新区间
                intervals[i][0] = intervals[i - 1][0];
                intervals[i][1] =max(intervals[i][1], intervals[i - 1][1]);
                // if (intervals.size() == 2 && i == 1) res.push_back(intervals[i]);
                if (i == intervals.size() - 1) res.push_back(intervals[i]);
            }else {
                res.push_back(intervals[i - 1]);
                if (i == intervals.size() - 1) res.push_back(intervals[i]);
            }
        }
        return res;
    }
};