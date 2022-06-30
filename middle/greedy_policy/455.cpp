#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int count = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        for (int i = g.size() - 1; i >=0 && index >= 0; i--) {
            if (s[index] >= g[i]) {
                count++;
                index--; // 让大尺寸饼干充分利用，优先发给胃口大的孩子
            }
        }
        return count;
    }
};