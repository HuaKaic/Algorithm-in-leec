#include <iostream>
#include <vector>

using namespace std;

int find_subnums(const vector<int>& nums, int values){
    
    int slowindex = 0;
    int fastindex = 0;
    for (;slowindex != nums.size(); ++slowindex){
        int sum = nums[slowindex];
        cout << slowindex << endl;
        for (fastindex = slowindex+1; fastindex != nums.size(); ++fastindex){
            sum += nums[fastindex];
            if (sum == values){
                return (fastindex - slowindex + 1);
            }
        }
    }
    return -1;
}


int main ()
{   
    vector<vector<int>> res(3,vector<int>(3,0));
    cout << res[2][2] << endl;
    vector<int> b;
    b.push_back(2);
    b.push_back(3);
    b.push_back(7);
    b.push_back(4);
}
