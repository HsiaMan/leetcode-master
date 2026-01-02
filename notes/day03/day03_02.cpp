#include <cstddef>
#include <iostream>
#include <vector>

int main(){
   unsigned int n ,m;
   std::cin >> n >> m;
   int sum = 0;
   int rows[n];
   int cols[m];
   std::vector<std::vector<int>>nums(n,std::vector<int>(m,0));
   for(unsigned int i = 0 ;i < n; i++){
      for (unsigned int j = 0; j < m ; j++) {
         std::cin >> nums[i][j];
         sum += nums[i][j];
         rows[i] += nums[i][j];
      }
      std::cout << "\n";
   }
   for(size_t j = 0;j < n;j++){
      
   }
}
