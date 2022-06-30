#include <iostream>
using namespace std;

class Solution {
public:
    int add(int a, int b) {
        if (a == 0 || b == 0) {
            return a == 0 ? b : a;
        }
        while (b) {
            int c = (unsigned int) (a & b) << 1; //C++ 不支持负数移位
            a ^= b;
            b = c;
        }
        return a;
        
    }
};