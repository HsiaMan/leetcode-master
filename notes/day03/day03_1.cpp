#include <cstddef>
#include <iostream>
#include <cstring>
#include <vector>
int main(){
   unsigned int  ArrayLength;
   std::cin >> ArrayLength;
   std::vector<long int >Array(ArrayLength + 1 ,0);
   std::vector<long long int > preSum(ArrayLength + 1,0);
   for(size_t i = 1;i <= ArrayLength;i++){
      std::cin >> Array[i];
      preSum[i] = preSum[i-1]  + Array[i]; 
   }
   unsigned int left,right;
   while(std::cin >> left >> right){
      std::cout << preSum[right+ 1] - preSum[left]<< "\n";
   }
   
   
   return 0;
}
