#include <iostream>
#include <vector>
int main(){

   std::vector<int> v = {1,2,3,4,5};
   std::erase(v,2);
   for (const auto & elem : v) {
      std::cout << elem << std::endl;
   }
}
