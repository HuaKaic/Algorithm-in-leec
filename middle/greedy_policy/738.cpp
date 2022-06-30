#include <vector>
#include <math.h>
using namespace std;


class Solution {
    
public:
    int monotoneIncreasingDigits(int n) {
        if (n <= 10 && n != 0) return 9;
        if (n == 0) return 0;
        vector<int> num_list;
        num_list.push_back(n % 10);
        n = int (n / 10);
        while (n > 0) {
            int cur_tail = n % 10;
            if (cur_tail > num_list.back()) {
                for (int number = 0; number < num_list.size(); number++) {
                    num_list[number] = 9;
                }
                num_list.push_back(cur_tail - 1);
            }else num_list.push_back(cur_tail);
            n = int (n / 10);
        }
        num_list.push_back(n);
        int count = 0;
        for (int i = 0; i < num_list.size(); i++) {
            count += pow(10, i) * num_list[i];
        }
        return count;
    }
};