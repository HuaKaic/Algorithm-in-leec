#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }
        bool flag = !s.empty() && (s[0] == p[0] || p[0] == '.');
        if (p.size() > 1 && p[1] == '*') {
            return bool (isMatch(s, p.substr(2)) || (flag && isMatch(s.substr(1), p))); // 正则表达式匹配 当前字符出现过或者是未出现两种情况
        }else {
            return bool (flag && isMatch(s.substr(1), p.substr(1)));
        }
    }
};
