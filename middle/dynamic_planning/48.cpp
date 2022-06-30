#include <iostream>
#include <string>
#include <math.h>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        if (s.size() == 1) return 1;
        int max_size = 0;
        int left = -1;
        unordered_map<char, int> str_map;
        for (int i = 0; i < s.size(); i++) {
            if (str_map.find(s[i]) != str_map.end()) {
                left = max(str_map[s[i]], left);
            }
            str_map[s[i]] = i; // 哈希表的取值也有讲究
            max_size = max(max_size, i - left);

        }
        return max_size;
    }
};