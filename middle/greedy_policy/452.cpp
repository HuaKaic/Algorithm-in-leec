#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool Tmp(const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), Tmp);
        if (points.size() == 0) return 0;
        int rightlimit = points[0][1];
        int count = 1;
        for (int i = 0; i < points.size(); i++) {
            if (points[i][0] <= rightlimit) {
                if (points[i][1] < rightlimit) {
                    rightlimit = points[i][1];
                    continue;
                }
            }else {
                rightlimit = points[i][1];
                count++;
            }
        }
        return count;
    }
};