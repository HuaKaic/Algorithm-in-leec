#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 快慢指针应用

vector<int> findSub(vector<int>& origin, int target, vector<int>& res) {
    int slowptr = 0;
    int fastptr = 0;
    
    while (fastptr < origin.size())
    {   
        if (origin[fastptr] != target) {
            res[slowptr] = origin[fastptr];
            slowptr++;
        }
        fastptr++;
    }
    return res;
    
}

int main(){
    vector<int> res;
    res.push_back(4);
    res.push_back(7);
    res.push_back(6);
    res.push_back(4);
    res.push_back(5);
    vector<int> res1(7, 0);
    findSub(res, 4, res1);
    for (auto iter = res1.begin(); iter != res1.end(); iter++) {
        cout << *iter << endl;
    }
    return 0;
}