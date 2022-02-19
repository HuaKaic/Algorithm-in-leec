#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void RemoveextraSpace(string& s){
        int slowindex = 0;
        int fastindex = 0;
        while (fastindex < s.size() && s[fastindex] == ' ' && s.size() > 0) fastindex++;
        for (;fastindex < s.size(); fastindex++){
            if (fastindex - 1 > 0 && s[fastindex - 1] == s[fastindex] && s[fastindex] == ' ') {
                continue;
            }else {
                s[slowindex++] = s[fastindex];
            }
        }
        if (slowindex - 1 > 0 && s[slowindex - 1] == ' ') {
            s.resize(slowindex-1);
        }else {
            s.resize(slowindex);
        }
    }

    void Reverse(string& s, int left, int right){
        while (left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        
        RemoveextraSpace(s);
        Reverse(s, 0, s.size() - 1);
        int left = 0;
        int right = 0;
        for (; right < s.size(); right++){
            while (s[right] != ' ' && s[right] != '\0'){
                right++;
            }
            Reverse(s, left, right-1);
            left = right + 1;
        }
        return s;
    }
    Solution(): data(0) {};
private:
    int data;
};

int main (int argc, char** argv){
    string s1 = "  int is a datatype in   cpp! ";
    cout << s1.size() << endl;
    Solution s2;
    // s2.RemoveextraSpace(s1);
    // s2.Reverse(s1, 0, s1.size() -1);
    s1 = s2.reverseWords(s1);
    int count = 0;
    int a = 1;
    int b = 2;
    int tmp;
    tmp = min(a, b);
    cout << min(a, b) << endl;
   
    
}
