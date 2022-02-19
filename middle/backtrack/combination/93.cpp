#include <vector>
#include <iostream>
#include <string>

using namespace std;
class Solution {
private:
    vector<string> res;
    bool isValid(const string& s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && start != end) return false;
        int sum = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') return false;
            sum = sum * 10 + (s[i] - '0');
            if (sum > 255) {
                return false;
            }
        }
        return true;
    }
    void backtrack(string& s, int startIndex, int pointNum) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                res.push_back(s);
            }
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i  + 1,'.');
                pointNum++;
                backtrack(s, i + 2, pointNum);
                pointNum--;
                s.erase(s.begin() + i +1);
            }else break;
            
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        backtrack(s, 0, 0);
        return res;
    }
};