#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    bool isNumber(string s) {
       typedef pair<char, int> add_pair;
       typedef unordered_map<char, int> unmap;
       vector<unmap> res = {
           unmap{add_pair(' ', 0), add_pair('d', 2), add_pair('s', 1), add_pair('.', 4)},
           unmap{add_pair('.', 4), add_pair('d', 2)},
           unmap{add_pair('.', 3), add_pair('d', 2), add_pair('e', 5) ,add_pair(' ', 8)},
           unmap{add_pair('d', 3), add_pair('e', 5),add_pair(' ', 8)},
           unmap{add_pair('d', 3)},
           unmap{add_pair('s', 6), add_pair('d', 7)},
           unmap{add_pair('d', 7)},
           unmap{add_pair('d', 7), add_pair(' ', 8)},
           unmap{add_pair(' ', 8)} // 有限状态机的思想，分别对应几种状态
       };
       int p = 0;
       char t;
       for (char sub:s) {
           if (sub >= '0' && sub <= '9') {
               t = 'd';
           }else if (sub == 'e' || sub == 'E') {
               t = 'e';
           }else if (sub == '+' || sub == '-') {
               t = 's';
           }else if (sub == '.' || sub == ' ') {
               t = sub;
           }else t = '?';
           if (!res[p].count(t)) {
               return false;
           }
           p = (int) res[p][t];
        }
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};