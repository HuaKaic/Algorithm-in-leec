#include <iostream>
using namespace std;

class Solution {
public:
    double recursive(double x,  long m) { // 考虑数组越界问题
        if (m == 0 || x == 1) {
            return 1;
        }
        if (m & 1) {
            return x * recursive(x * x, m >> 1);
        }else {
            return recursive(x * x, m >> 1); // 左移相当于整除2
        }
        return 0;
    }
    double myPow(double x, int n) {
        long b = n;
        if (n < 0) {
            b = abs(b);
            return 1 / recursive(x, b);
        }
        return recursive(x, b);
    }
};