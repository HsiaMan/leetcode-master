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

#### [区间和](https://kamacoder.com/problempage.php?pid=1070)

>题目描述
>
>给定一个整数数组 Array，请计算该数组在每个指定区间内元素的总和。
>
>输入描述
>
>第一行输入为整数数组 Array 的长度 n，接下来 n 行，每行一个整数，表示数组的元素。随后的输入为需要计算总和的区间，直至文件结束。
>
>输出描述
>
>输出每个指定区间内元素的总和。
>
>输入示例

这个求区间和，并且要求运算时间短，就是要求用preSum 来求和，然后给出范围后，直接减即可，用另一个数组，直接存从开始到当前位置的和即可。可以用两个数组，数组的长度比原本的长度大 1，然后从 1开始直接存，求区间和就可以直接用数组下标索引直接求和就可以了。



#### 开发商购买土地

这个主要的问题就是如何如何使`distance`最小，就是在遍历的过程中不断的更新，最后使`distance`满足条件即可。

```c++
#include <algorithm>
#include <climits>
#include <cstddef>
#include <iostream>
#include <vector>

int main(){
   size_t n ,m;
   std::cin >> n >> m;
   int sum = 0;
   std::vector<int> rows(n,0);
   std::vector<int> cols(m,0);
   std::vector<std::vector<int>>nums(n,std::vector<int>(m,0));
   for(size_t i = 0 ;i < n; i++){
      for (size_t j = 0; j < m ; j++) {
         std::cin >> nums[i][j];
         sum += nums[i][j];
         rows[i] += nums[i][j];
         cols[j] += nums[i][j];
      }
   }

   // std::cout << "please giving the minimum distance" << std::endl;
   unsigned int distance;
   std::cin >>distance;
   int  result = INT_MAX;
   int rowsSum = 0;
   for (size_t i = 0 ; i < n ; i++) {
      rowsSum += rows[i];
      result = std::min(result,sum - rowsSum);
   }
   int colSum = 0;
   for (size_t j = 0; j < m ; j++) {
      colSum += cols[j];
      result = std::min(result,sum - colSum);
   }
   std::cout << result << std::endl;
   return 0;
}

```

