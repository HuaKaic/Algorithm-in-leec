#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> res; 
    void transform_maxvalues(string s) {
        bool uselessZero = true;
        string tmp = "" ;
        for (auto sub : s) {
            if (uselessZero && sub != '0') uselessZero = false;
            if (!uselessZero) tmp += sub;
        }
        if (tmp != "") res.push_back(stoi(tmp)); // 当前数值超出范围时，out of range提醒
    }
    void permutation(string& s, int length, int pos) { // 递归思想转化为各个数字的组合
        if (pos == length) {
            transform_maxvalues(s);
            return;
        }
        for (int i = 0; i <= 9; i++) {
            s[pos] = i + '0';
            permutation(s, length, pos + 1);
        }
    }
    vector<int> printNumbers(int n) {
        string s(n, '0');
        for (int i = 0; i <= 9;i++) {
            s[0] = i + '0';
            permutation(s, n, 1);
        }
        return res;
    }
};