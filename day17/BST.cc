#include <cstddef>
#include <iostream>
#include <vector>
int main(){
   std::vector<int> vec;
   for (size_t i = 0; i < 10; i++) {
      vec.push_back(i);
   }
   for (const auto & elem : vec) {
      std::cout << "elem" << elem << std::endl;
   }
   std::cout << "-----" << std::endl;
   vec.clear();
   for (const auto & elem : vec) {
      std::cout << "elem" << elem << std::endl;
   }
   return 0;

}
