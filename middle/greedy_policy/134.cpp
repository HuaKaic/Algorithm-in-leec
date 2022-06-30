#include <vector>
using namespace std;
// 加油站问题， 由于只有唯一解，找到剩余汽油数不为零的地方。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0;
        int cur_gas = 0;
        int startIndex = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i] - cost[i];
            cur_gas += gas[i] - cost[i];
            if (cur_gas < 0) {
                cur_gas = 0;
                startIndex = i + 1;
            }
        }
        if (total_gas < 0) return -1;
        else return startIndex;
    }
};