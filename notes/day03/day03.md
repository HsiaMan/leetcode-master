## DAY 3

####  [209. 长度最小的子数组](https://leetcode.cn/problems/minimum-size-subarray-sum/) 

这题最简单的思路就是两层`for`循环，进行遍历，直接找到最小的子数组长度，**滑动窗口就是在找到符合条件的目标后更新后一个指针更新的同时更新前一个指针。**但是，对于有 负数值的话，一般不可以用滑动窗口

>[!CAUTION]
>
>其实这个思路是不要一下就找出最小的子数组长度，要在循环过程中不断更新最终得到最短的子数组长度



#### [59. 螺旋矩阵 II](https://leetcode.cn/problems/spiral-matrix-ii/)

这题主要是注意边界的界定

```C++
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> nums(n,vector<int>(n,0));
        int left = 0 ,top = 0;
        int bottom = n - 1,right = n - 1;
        int num = 0;
        while(left <= right && top <= bottom){
            //从左到右
            for(int j = left ; j <= right;j++){
                nums[top][j] = ++num;
            }
            top = top + 1;
            for(int i = top;i <= bottom;i++){
                nums[i][right] = ++num;
            }
            right = right - 1;
            if(left <= right){
                for(int j = right; j >= left;j--){
                    nums[bottom][j] = ++num;
                }
            }
            bottom = bottom - 1;
            if(top <= bottom){
                for(int i = bottom; i >= top;i--){
                   nums[i][left] = ++num;
                }
            }

            left = left + 1;
        }
        return nums;
    }
};
```

我写的代码是没有后面的两个`if`的判断，加`if`主要是代码可读性好，`if`就是为了处理`n`为奇数的情况，因为奇数可能只遍历一次就可以了，之后后面的第二个`for`循环的条件就不成立了。后面的也就不成立。





