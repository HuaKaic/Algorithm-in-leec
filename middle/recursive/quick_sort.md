# 快速排序

## 找到一个基数，将大于该数的放在右边，小于该数的放在左边，依次递归调用
***
```c++
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 将给定数组排序
     * @param arr int整型vector 待排序的数组
     * @return int整型vector
     */
    
    void quick_sort(vector<int>& res, int left, int right) {
        if (left >= right) return;
        int i = left, j = right;
        int x = res[left];
        while (i < j) {
            while (i < j && res[j] >= x) j--;
            res[i] = res[j];
            while (i < j && res[i] < x) i++;
            res[j] = res[i];
        }
        res[i] = x;
        quick_sort(res, left, i - 1);
        quick_sort(res,  i + 1, right);
    }
    vector<int> MySort(vector<int>& arr) {
        quick_sort(arr, 0, arr.size() - 1);
        return arr;
    }
};
```