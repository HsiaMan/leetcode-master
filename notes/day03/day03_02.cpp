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
