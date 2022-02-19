#include <vector>
#include <string>
/*
* 将一个字符串拆分，使其各子字符串是回文串！
*/
using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> res;
    bool distinc_huiwen(const string s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(string s, int startIdex) {
        if (startIdex >= s.size()) {
            res.push_back(path);
        }
        for (int i = startIdex; i < s.size(); i++) {
            if (distinc_huiwen(s, startIdex, i)) {
                string subs = s.substr(startIdex, i - startIdex + 1);
                path.push_back(subs);
            }else {
                continue;
            }
            backtrack(s, i +1);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        backtrack(s, 0);
        return res;
    }
};