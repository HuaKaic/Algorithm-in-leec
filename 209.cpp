#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FindNums{
public:
    int result = INT32_MAX;
    int i = 0;
    int sublength = 0;
    int total = 0;
    int find_sublength(const vector<int>& nums, int sums){
        for (int j = 0; j != nums.size(); j++){
            total += nums[j];
            while (total >= sums){
                sublength = j - i + 1;
                result = result < sublength? result:sublength;
                total -= nums[i++];
            }
        }
        return result == INT32_MAX? 0:result;
    }  
}；