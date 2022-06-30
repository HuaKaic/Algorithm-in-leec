#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int size = s.size();
        string s1(size, 'a');
        for (int i = 0; i < size; i++) {
            if (!isalpha(s[i])) {
                s1[i] = s[i];
            }
        }
        for (int j = 0, i = size - 1; j < size && i >= 0; i--) {
            if (isalpha(s[i])) {
                while (j < size && !isalpha(s1[j]) ) {
                    j++;
                } // 找到放置字母的位置，跳过放置非字母的位置
                s1[j] = s[i]; // 放置字母
                j++;
            } else continue; // 如果遍历到非字母，跳过
        }
        return s1;
    }
};