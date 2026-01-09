#include <iostream>
#include <vector>
int main(){
   std::vector<int> num1 = {1,2,3,4,5,6,7};
   for(int i = 0;i < num1.size();i++){
      std::cout << "i = " << i << std::endl;
      std::cout << "num[" <<i<< "]=" << num1[i] << std::endl;
   }



   return 0;
}
