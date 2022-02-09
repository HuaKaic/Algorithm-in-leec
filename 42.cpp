#include<iostream>
#include<vector>


class Solution {
public:
    int trap(vector<int>& height) {
        int fast = 0;
        int slow = 0;
        int result = 0;
        int tmp;
        while (slow < height.size() - 2){
            while (height[slow] <= height[slow+1] && slow < height.size() - 2){
                slow++;
            }
            fast = slow + 1;
            if (fast == height.size() - 2){
                if (height[fast] < height[slow] && height[fast] < height[height.size() - 1]) {
                    tmp = min(height[slow], height[height.size() - 1]);
                    result += (height[fast] - tmp);
                } 
            }else {
                while (fast < height.size() -1 && !(height[fast] > height[fast-1] && height[fast] >= height[fast+1])) {
                    fast++;
                }
            }
            if (fast - slow > 1){
                tmp = min(height[slow], height[fast]);
                for (int j = slow + 1; j < fast; j++) {
                    result += (tmp - height[j]);
                }
            }
            slow = fast;
        }
        return result;
    }
};