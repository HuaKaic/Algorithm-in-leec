#include <vector>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five_count = 0, ten_count = 0, twenty_count = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) five_count++;
            else if (bills[i] == 10) {
                five_count--;
                ten_count++;
                if (five_count < 0) return false;
            }else {
                if (ten_count > 0) {
                    if (five_count <= 0) return false;
                    ten_count--;
                    five_count--;
                }else {
                    if (five_count < 3) return false;
                    five_count = five_count - 3;
                }
            }

        }
        return true;

    }
};